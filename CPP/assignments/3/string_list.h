#ifndef STRING_LIST_H
#define STRING_LIST_H

#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
using std::stringstream;
using std::string;
using std::ostream;

class StringList {
 public:
  /*
   * This is the constructor for the class.
   * It initializes the private data members max_capacity_ and curr_size_
   * Also allocates emmory for the dynamic array of dynamic strings.
   */
  StringList();

  /*
   * This is the destructor for the class
   * It deallocates the memory for the dynamic array of dynamic strigns.
   */
  ~StringList();

  /*
   * This function adds an item to the array and takes care of
   * growing the array if there is no more room.
   * @param string* the_string - a pointer to the string to be added
   */
  void AddItem(string* the_string);

 /*
  * This function deletes a string from the string list.
  * @param int index - the index of the string to delete at that location
  *                    if the index is not valid, the function does nothing
  */
  void DeleteItem(unsigned int index);

  /*
   * This function returns an item from the array.
   * @param int index - the index where to get the string from
   * @return string* - a pointer to the string at that index
   *                   if index is not valid, NULL is returned
   */
  string* GetItem(unsigned int index);

  /*
   * This function gets the size of the string list.
   * @return int - the current size of the string list
   */
  int GetSize();

  /*
   * This function gets the capacity of the string list.
   * @return int - the maximum capacity of the string list
   */
  int GetCapacity();

  /*
   * This function uses the Insertion sort to arrange the strings
   * into a case-insensetive lexicographic ordering.
   */
  void Sort();

  /*
   * This function returns a string of all the strings in the list
   * separated by a ` char.
   * @return string - a string containing all the strings formatted like that
   */
  string ToFile();

  /*
   * This friend function is an overloaded << operator that prints
   * out a numbered list of all the strings.
   * @param ostream &out - an ostream object passed by reference
   * @param const StringList &string_list - the StringList object to be printed
   *                                        to stdout
   * @return ostream& - an outstream object containing the formatted output
   */
  friend ostream& operator <<(ostream &out, const StringList &string_list);

 private:
  string** string_array_;
  unsigned int max_capacity_;
  unsigned int curr_size_;

 /*
  * This function increases the capacity of the string list by 10
  */
  void IncreaseCapacity();

  /*
   * This function compacts the array, getting rid of a "hole" in the array
   * @param int index - the index where the "hole" is
   */
  void CompactArray(unsigned int index);

  /*
   * This function converts a string to all upper case
   * @param string the_string - the string to be converted to upper case
   * @return string - the ready string that is in all upper case
   */
  string ToUpper(string the_string);
};

#endif /* STRING_LIST_H */
