/*
 * Name        : assignment_3_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit test to test StringList Functionality
 *               THIS FILE SHOUD NOT BE ALTERED, UNLESS DEBUGGING IN MAIN
 */

#include <iostream>
#include <sstream>
#include <streambuf>
#include "string_list.h"
// Double Include to Check for Header Guards
#include "string_list.h"
using std::cout;
using std::endl;
using std::string;

// For testing (DO NOT ALTER)
#include <cctype>
#include <vector>
void UnitTest();
void Test(bool test, int line_number, string more_info = "", string yours = "!",
          string actual = "!");
void OutputFailedTests();
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0, num_of_tests = 53;
std::vector<int> failed_tests;

// Program Execution Starts Here
int main() {
  // START DEBUGGING CODE

  // END DEBUGINH CODE
  // To test your code (DO NOT ALTER)
  UnitTest();
  // This ends program execution
  return 0;
}

// For testing (DO NOT ALTER)
void UnitTest() {
  cout << string(40, '-') << endl;
  cout << "UNIT TEST:\n" << string(40, '-') << endl;
  if (num_of_tests != 0)
    cout << "Total Number of Tests: " << num_of_tests << endl;
  string yours = "", actual = "";

  cout << "\n*****StringList Constructor*****\n";
  StringList list;
  Test(list.GetSize() == 0, __LINE__, "GetSize()");
  Test(list.GetCapacity() == 25, __LINE__, "GetCapacity()");
  Test(list.GetItem(0) == NULL, __LINE__, "GetItem(0)");
  yours = list.ToFile();
  actual = "";
  Test(yours == actual, __LINE__, "ToFile()", yours, actual);


  cout << "\n*****StringList Member Functions with 1 Item*****\n";
  list.AddItem(new string("Hello"));
  Test(list.GetSize() == 1, __LINE__, "AddItem(new string(\"Hello\") / GetSize()");
  Test(list.GetCapacity() == 25, __LINE__, "GetCapacity()");
  yours = *list.GetItem(0);
  actual = "Hello";
  Test(yours == actual, __LINE__, "*GetItem(0)", yours, actual);
  yours = list.ToFile();
  actual = "Hello";
  Test(yours == actual, __LINE__, "ToFile()", yours, actual);
  cout << "Testing (1 Item) Overloaded <<:\n" << list << endl;


  cout << "\n*****StringList Member Functions with 2 Items*****\n";
  list.AddItem(new string("World!"));
  Test(list.GetSize() == 2, __LINE__, "AddItem(new string(\"World!\") / GetSize()");
  Test(list.GetCapacity() == 25, __LINE__, "GetCapacity()");
  yours = *list.GetItem(0);
  actual = "Hello";
  Test(yours == actual, __LINE__, "*GetItem(0)", yours, actual);
  yours = *list.GetItem(1);
  actual = "World!";
  Test(yours == actual, __LINE__, "*GetItem(1)", yours, actual);
  Test(list.GetItem(2) == NULL, __LINE__, "GetItem(2)", yours, actual);
  yours = list.ToFile();
  actual = "Hello`World!";
  Test(yours == actual, __LINE__, "ToFile()", yours, actual);
  cout << "Testing (2 Items) Overloaded <<:\n" << list << endl;

  cout << "\n*****StringList - Deleting the First Item - Performs Compaction*****\n";
  list.DeleteItem(0);
  Test(list.GetSize() == 1, __LINE__, "DeleteItem(0) / GetSize()");
  Test(list.GetCapacity() == 25, __LINE__, "GetCapacity()");
  yours = *list.GetItem(0);
  actual = "World!";
  Test(yours == actual, __LINE__, "*GetItem(0)", yours, actual);
  Test(list.GetItem(1) == NULL, __LINE__, "GetItem(1)", yours, actual);
  yours = list.ToFile();
  actual = "World!";
  Test(yours == actual, __LINE__, "ToFile()", yours, actual);
  cout << "Testing (1 Item) Overloaded <<:\n" << list << endl;

  cout << "\n*****StringList - Trying to Delete Non-Existant Item*****\n";
  list.DeleteItem(1);
  Test(list.GetSize() == 1, __LINE__, "DeleteItem(1) / GetSize()");
  Test(list.GetCapacity() == 25, __LINE__, "GetCapacity()");
  yours = *list.GetItem(0);
  actual = "World!";
  Test(yours == actual, __LINE__, "*GetItem(0)", yours, actual);
  Test(list.GetItem(1) == NULL, __LINE__, "GetItem(1)", yours, actual);
  yours = list.ToFile();
  actual = "World!";
  Test(yours == actual, __LINE__, "ToFile()", yours, actual);
  cout << "Testing (1 Item) Overloaded <<:\n" << list << endl;


  cout << "\n*****StringList Member Functions with 25 Items*****\n";
  stringstream ss;
  for (int i = 0; i < 24; i++) {
    ss << "String " << i + 2;
    list.AddItem(new string(ss.str()));
    ss.str("");
  }
  Test(list.GetSize() == 25, __LINE__, "AddItem(Adding 24 More Items) / GetSize()");
  Test(list.GetCapacity() == 25, __LINE__, "GetCapacity()");
  yours = *list.GetItem(17);
  actual = "String 18";
  Test(yours == actual, __LINE__, "*GetItem(17)", yours, actual);
  yours = *list.GetItem(24);
  actual = "String 25";
  Test(yours == actual, __LINE__, "*GetItem(24)", yours, actual);
  Test(list.GetItem(25) == NULL, __LINE__, "GetItem(25)", yours, actual);
  yours = list.ToFile();
  actual = "World!`String 2`String 3`String 4`String 5`String 6`String 7`String 8`String 9`String 10`String 11`String 12`String 13`String 14`String 15`String 16`String 17`String 18`String 19`String 20`String 21`String 22`String 23`String 24`String 25";
  Test(yours == actual, __LINE__, "ToFile()", yours, actual);
  cout << "Testing (25 Items) Overloaded <<:\n" << list << endl;


  cout << "\n*****StringList - Deleting Item 15 - Performs Compaction*****\n";
  list.DeleteItem(15);
  Test(list.GetSize() == 24, __LINE__, "DeleteItem(15) / GetSize()");
  Test(list.GetCapacity() == 25, __LINE__, "GetCapacity()");
  yours = *list.GetItem(17);
  actual = "String 19";
  Test(yours == actual, __LINE__, "*GetItem(19)", yours, actual);
  yours = *list.GetItem(23);
  actual = "String 25";
  Test(yours == actual, __LINE__, "*GetItem(23)", yours, actual);
  Test(list.GetItem(24) == NULL, __LINE__, "GetItem(24)", yours, actual);
  yours = list.ToFile();
  actual = "World!`String 2`String 3`String 4`String 5`String 6`String 7`String 8`String 9`String 10`String 11`String 12`String 13`String 14`String 15`String 17`String 18`String 19`String 20`String 21`String 22`String 23`String 24`String 25";
  Test(yours == actual, __LINE__, "ToFile()", yours, actual);
  cout << "Testing (24 Items) Overloaded <<:\n" << list << endl;

  cout << "\n*****StringList Member Functions with 30 Items - Performs Increase Capacity*****\n";
  for (int i = 26; i <= 31; i++) {
    ss << "String " << i;
    list.AddItem(new string(ss.str()));
    ss.str("");
  }
  Test(list.GetSize() == 30, __LINE__, "AddItem(Adding 6 More Items) / GetSize()");
  Test(list.GetCapacity() == 35, __LINE__, "GetCapacity()");
  yours = *list.GetItem(17);
  actual = "String 19";
  Test(yours == actual, __LINE__, "*GetItem(17)", yours, actual);
  yours = *list.GetItem(29);
  actual = "String 31";
  Test(yours == actual, __LINE__, "*GetItem(29)", yours, actual);
  Test(list.GetItem(30) == NULL, __LINE__, "GetItem(30)", yours, actual);
  yours = list.ToFile();
  actual = "World!`String 2`String 3`String 4`String 5`String 6`String 7`String 8`String 9`String 10`String 11`String 12`String 13`String 14`String 15`String 17`String 18`String 19`String 20`String 21`String 22`String 23`String 24`String 25`String 26`String 27`String 28`String 29`String 30`String 31";
  Test(yours == actual, __LINE__, "ToFile()", yours, actual);
  cout << "Testing (30 Items) Overloaded <<:\n" << list << endl;


  cout << "\n*****Sorting StringList with 30 Items*****\n";
  list.Sort();
  Test(list.GetSize() == 30, __LINE__, "Sort() / GetSize()");
  Test(list.GetCapacity() == 35, __LINE__, "GetCapacity()");
  yours = *list.GetItem(0);
  actual = "String 10";
  Test(yours == actual, __LINE__, "*GetItem(0)", yours, actual);
  yours = *list.GetItem(17);
  actual = "String 27";
  Test(yours == actual, __LINE__, "*GetItem(17)", yours, actual);
  yours = *list.GetItem(29);
  actual = "World!";
  Test(yours == actual, __LINE__, "*GetItem(29)", yours, actual);
  Test(list.GetItem(30) == NULL, __LINE__, "GetItem(30)", yours, actual);
  yours = list.ToFile();
  actual = "String 10`String 11`String 12`String 13`String 14`String 15`String 17`String 18`String 19`String 2`String 20`String 21`String 22`String 23`String 24`String 25`String 26`String 27`String 28`String 29`String 3`String 30`String 31`String 4`String 5`String 6`String 7`String 8`String 9`World!";
  Test(yours == actual, __LINE__, "ToFile()", yours, actual);
  cout << "Testing (30 Sorted Items) Overloaded <<:\n" << list << endl;


  cout << "\n*****StringList Member Functions with 1000 Items - Increases Capacity Many Times*****\n";
  for (int i = 0; i < 970; i++)
    list.AddItem(new string("A"));
  Test(list.GetSize() == 1000, __LINE__, "AddItem(Adding 970 More Items) / GetSize()");
  Test(list.GetCapacity() == 1005, __LINE__, "GetCapacity()");


  cout << "\n*****Deleting All Items - Runs Compaction Many Times*****\n";
  for (int i = 999; i >= 0; i--)
    list.DeleteItem(i);
  Test(list.GetSize() == 0, __LINE__, "Deleting All Items / GetSize()");
  Test(list.GetCapacity() == 1005, __LINE__, "GetCapacity()");


  cout << "\n*****Testing Destructors*****" << endl
       << "If the next line is the \"END Testing Destructors\" then you passed!"
       << endl;
  StringList *dynamic_list = new StringList();
  delete dynamic_list;
  dynamic_list = new StringList();
  for (int i = 0; i < 50; i++)
    dynamic_list->AddItem(new string("testing"));
  delete dynamic_list;
  cout << "*****END Testing Destructors*****" << endl;

  cout << string(40, '-') << endl;
  cout << "Passed: " << ut_passed << " / " << ut_total << endl;
  OutputFailedTests();
  cout << string(40, '-') << endl;
  cout << "END OF UNIT TEST!\n";
  cout << string(40, '-') << endl;
  cout << "Be sure to run 'make style' to check for any style errors.\n"
       << "Please note that 'make style' does NOT check variable names or"
       << " indentation" << endl << endl;
}

// For testing (DO NOT ALTER)
void Test(bool test, int line_number, string more_info, string yours,
          string actual) {
  ut_total++;
  if (test) {
    cout << "PASSED TEST ";
    ut_passed++;
  } else {
    cout << "FAILED TEST ";
    ut_failed++;
    failed_tests.push_back(ut_total);
  }
  cout << ut_total << " " << more_info << "!" << endl;
  if (!test) {
    if (yours != "!")
      cout << "Yours:  \"" << yours << '"' << endl;
    if (actual != "!")
      cout << "Actual: \"" << actual << '"' << endl;
    cout << "  Check Line " << line_number << " for more info" << endl;
  }
}

void OutputFailedTests() {
  if (failed_tests.size()) {
    cout << "Failed test number(s): ";
    for (unsigned int i = 0; i < failed_tests.size() - 1; i++)
      cout << failed_tests.at(i) << ", ";
    cout << failed_tests.at(failed_tests.size() - 1) << endl;
  }
}

