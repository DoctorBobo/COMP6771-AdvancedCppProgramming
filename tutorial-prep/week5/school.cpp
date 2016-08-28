#include "school.hpp"

int School::Student::nextStudentNumber = 9312;

// adds a student to the course
// return false if the student is already enrolled in the course
bool School::Course::addStudent(std::weak_ptr<Student> wp)
{
   auto result = std::find_if(studentsInCourse.begin(),studentsInCourse.end(),
                              [wp](auto s){ return wp.lock() == s.lock(); });
   if (result != studentsInCourse.end())
      return false;

   studentsInCourse.push_back(wp); 
   return true;
}

// prints the students in a course
void School::Course::printRoll() const noexcept
{
   std::cout << courseCode << " Roll\n";
   for (auto wp : studentsInCourse)
   {
      // TODO: print the names of the students in the course
      // std::cout << sp->getName() << '\n';
   }
}

// adds a course that this student is taking. 
// Pre-Condition: The student has already been enrolled in the course. 
// Pre-Condition: The student hasn't already had this course added to their timetable
bool School::Student::addCourse(std::weak_ptr<Course> wp)
{
   coursesEnrolledIn.push_back(wp);
   return true;
}

// method to print a student's timetable
void School::Student::printTimetable() const noexcept
{
   std::cout << "Timetable for " << name << ' ' << studentNumber << '\n';
   for (auto c : coursesEnrolledIn)
   {
      auto sp = c.lock();
      if (sp)
         std::cout << sp->getCourseCode() << '\n';
   }
}

// create a course object and add it to the list of courses
// return false if the course already exists
bool School::addCourse(const std::string& courseCode)
{
   // TODO: double check that the course doesn't already exist.
   courses.push_back(std::make_shared<Course>(courseCode));
   return true;
}

// adds a student to a course. 
void School::addStudentToCourse(const int id, const std::string& courseCode)
{
   auto courseObject = findCourse(courseCode);
   auto studentObject = findStudent(id);

   //TODO: try to add the student to the course.
   // if the student can't be added to the course, e.g. they are already enrolled
   // then return false.

   studentObject->addCourse(*courseObject);
}

// method to transfer ownership of a locker to a student if 
// there are enough lockers available. 
bool School::assignLocker(const int id)
{
   auto studentObject = findStudent(id);
   if (!lockers.empty())
   {
      // TODO: assign the locker to the student
      lockers.pop_back();
      return true;
   }
   return false;
}

// method to find a course object. 
// showcasing a trailing return type, using the type of iterator that courses returns. 
// this is used as trying to determine the type of this iterator is difficult. 
auto School::findCourse(const std::string& courseCode) const -> decltype(courses.begin()) // we will revise this
{
   auto courseObject = std::find_if(courses.begin(), courses.end(),
                                    [&courseCode](auto c)
                                    {
                                       return c->getCourseCode() == courseCode;
                                    });
   if (courseObject == courses.end())
      throw std::runtime_error{"Can't find course " + courseCode};
   return courseObject;
}

/*
bool operator==(const std::shared_ptr<School::Course>& a, const std::shared_ptr<School::Course>& b)
{
   return a->getCourseCode() == b->getCourseCode();
}
*/
