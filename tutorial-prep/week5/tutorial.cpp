#include "school.hpp"

int main()
{
   auto s = School{};

   using namespace std::string_literals;
   s.addCourse("CS1917"s);
   s.addCourse("CS2911"s);
   s.addCourse("CS6771"s);

   if (s.addCourse("CS1917"s) == false)
      std::cerr << "can't add a duplicate course\n";

   // add some students. 
   auto tomStudentId   = s.addStudent("Tom"s);
   auto jerryStudentId = s.addStudent("Jerry"s);
   auto homerStudentId = s.addStudent("Homer"s);

   // add students to some courses 
   try
   {
      s.addStudentToCourse(tomStudentId,   "CS1917"s);
      s.addStudentToCourse(jerryStudentId, "CS1917"s);
      s.addStudentToCourse(homerStudentId, "CS1917"s);
      s.addStudentToCourse(1234, "CS1917"s);
   }
   catch(const std::exception& ex)
   {
      std::cerr << ex.what() << '\n';
   }

   // try to enroll homer twice:
   try
   {
      s.addStudentToCourse(homerStudentId, "CS2911"s);
      s.addStudentToCourse(homerStudentId, "CS1917"s);
   }
   catch(const std::exception & ex)
   {
      std::cerr << ex.what() << '\n';
   }

   s.printRoll("CS1917"s);

   s.printTimetable(homerStudentId);

   s.assignLocker(homerStudentId);
   std::cout << std::boolalpha
             << "Homer has a locker: " << s.hasLocker(homerStudentId) << '\n'
             << "Tom has a locker: "   << s.hasLocker(tomStudentId)   << '\n' 
             << std::noboolalpha;

   // delete a student
   s.expelStudent(tomStudentId);
   s.printRoll("CS1917"s);

   // delete a course. 
   s.cancelCourse("CS1917"s);
   s.printTimetable(homerStudentId);

   // if we delete homer, what happens to the locker he owns?
}
