#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include <exception>
#include <map>

class School
{
   class Student;

   class Course
   {
   public:
      Course() = default;
      Course(const std::string& s) : courseCode{s} {}
      const std::string& getCourseCode() const { return courseCode; }
      
      // adds a student to the course
      bool addStudent(std::weak_ptr<Student> wp);
      
      // method to print the students in a course
      void printRoll() const noexcept;
   private:
      std::string courseCode{"<unknown>"};
      std::vector<std::weak_ptr<Student>> studentsInCourse;
   };

   class Locker
   {
   public:
      Locker() = default;
      Locker(int id) : lockerId{id} {}
   private:
      const int lockerId = 0;
   };

   class Student
   {
   public:
      Student() = default;
      Student(const std::string& s) : name{s} {}
      int getStudentNumber() const noexcept { return studentNumber; }
      std::string getName() const noexcept { return name; }
      
      // method to add a course that this student is taking. 
      bool addCourse(std::weak_ptr<Course> wp);
      
      // method to print a student's timetable
      void printTimetable() const noexcept;
      
      // method to take ownership of a locker object
      void assignLocker(std::unique_ptr<Locker> locker) noexcept { assignedLocker = std::move(locker); }
      
      // returns true if the student has ownership over a locker object.
      bool hasLocker() const noexcept { return assignedLocker != nullptr; }
   private:
      std::unique_ptr<Locker> assignedLocker;
      std::string name{"<unknown>"};
      int studentNumber{++nextStudentNumber};
      std::vector<std::weak_ptr<Course>> coursesEnrolledIn;
      
      static int nextStudentNumber;
   };
public:
   School() : School{100} {}

   // Create some lockers. 
   School(const int numLockers)
   {
      for (auto i = 0; i < numLockers; ++i)
         lockers.push_back(std::make_unique<Locker>(i));
   }

   // create a course object and add it to the list of courses
   bool addCourse(const std::string& courseCode);
   
   // method to add a new student and return their new student id
   int addStudent(const std::string& studentName)
   {
      auto newStudent = std::make_shared<Student>(studentName);
      students.emplace(newStudent->getStudentNumber(), newStudent);
      return newStudent->getStudentNumber();
   }
   
   // add a student to a course. 
   void addStudentToCourse(int id, const std::string& courseCode);
   
   // method to print a roll for a course
   void printRoll(const std::string& s) const { (*findCourse(s))->printRoll(); }
   
   // print a student's timetable.
   void printTimetable(const int id) const { findStudent(id)->printTimetable(); }
   
   // method to transfer ownership of a locker to a student if 
   // there are enough lockers available. 
   bool assignLocker(int id);
   
   // test if a student has a locker assigned.
   bool hasLocker(int id) const { return findStudent(id)->hasLocker(); }
   
   // removes a student from the school
   void expelStudent(int id) { students.erase(id); }
   
   // cancels a course at the school
   void cancelCourse(const std::string& s) { courses.erase(findCourse(s)); }
private:
   std::vector<std::shared_ptr<Course>> courses;
   std::map<int, std::shared_ptr<Student>> students;
   std::vector<std::unique_ptr<Locker>> lockers;
   
   // method to find a course object. 
   // showcasing a trailing return type, using the type of iterator that courses returns. 
   // this is used as trying to determine the type of this iterator is difficult. 
   auto findCourse(const std::string& courseCode) const -> decltype(courses.begin());
   
   // find a student object. 
   std::shared_ptr<Student> findStudent(const int id) const
   {
      auto studentObject = students.find(id);
      if (studentObject == students.end())
         throw std::runtime_error{"Can't find student " + std::to_string(id)};
      return studentObject->second;
   }
};
