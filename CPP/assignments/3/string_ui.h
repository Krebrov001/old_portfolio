/*
 * Name        : string_ui.h
 * Author      : Konstantin Rebrov
 * Language    : C++
 * Description : This is the file that defines the StringUI class.
 *               It creates a menu or UI for the user to add input
 *               to choose how to manipulate the string list.
 */

#ifndef STRING_UI_H
#define STRING_UI_H

#include <iostream>
#include <iomanip>  // includes setw() and setfill()
#include <cstdlib>  // includes system()
// also includes rand() and srand()

#include <unistd.h>  // includes sleep()
#include <ctime>     // includes time()
#include <string>
#include <fstream>
#include <cctype>   // includes character functions
using std::fstream;
using std::string;
using std::cout;
using std::endl;
using std::setw;
using std::setfill;
#include "string_list.h"
#include "CinReader.h"

class StringUI {
 public:
  /*
   * This is the constructor for the StringUI class.
   * It allocates the memory for the dynamic StringList* object.
   */
  StringUI();

  /*
   * This is the destructor for the StringUI class.
   * It deallocates the memory for the dynamic StringList* object.
   */
  ~StringUI();

  /*
   * This is the main menu function. It provides a way for the user to call
   * the private class functions. All input/output happens through the Menu()
   * function.
   */
  void Menu();

 private:
  // A dynamic instance of the StringList class
  StringList* string_list;
  // An instance of the CinReader class (from CinReader.h and CinReader.cpp)
  CinReader reader;

  /*
   * This function allows the user to create a new string and add it
   * to the list.
   */
  void CreateString();

  /*
   * This function asks the user to input an index location and edits the
   * string at that index.
   */
  void EditString();

   /*
   * This function asks the user to input an index location and deletes the
   * string at that index.
   */
  void DeleteString();

  /*
   * This function prints all the strings in the list to stdout.
   */
  void ViewStrings();

  /*
   * This function asks the user to input an index location and prints out the
   * string at that index.
   */
  void ViewSpecificString();

  /*
   * This function deletes all the strings in the list.
   */
  void DeleteAllStrings();

  /*
   * This function asks the user to input a file name and saves the whole
   * string list to that file.
   */
  void SaveList();

  /*
   * This function asks the user to input a file name and retrieves the list
   * from that file, giving the user the option to overwrite the current
   * string list, if necessary.
   */
  void RetreiveList();

  /*
   * This function clears the screen in a way depending on the computer's OS.
   * It is required for the animation and smoothness of displaying the menu.
   */
  void ClearScreen();

  /*
   * This function delays stdout in a way depending on the computer's OS.
   * It is required for the animation and smoothness of displaying the menu.
   * @param int miliseconds = 1000 - The number of miliseconds to delay the
   *                                 output for. Default argument is 1 second.
   */
  void Sleeps(int miliseconds = 1000);

  /*
   * This function "loads" the program. It is just an extra feature to make
   * the output look nice. It may be omitted if you wish.
   */
  void Loading();

  /*
   * This function formats and prints the Main Menu to stdout.
   */
  void DrawMenu();
};

#endif /* STRING_UI_H */
