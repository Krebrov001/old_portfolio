/*
 * Name        : dl_list.h
 * Author      : Konstantin Rebrov
 * Date        : 04/27/2017
 * Language    : C++
 * Description : This file defines the class DLList.
 */

#ifndef DL_LIST_H
#define DL_LIST_H

#include "dl_node.h"
#include <iostream>  // also includes string and cstddef
#include <sstream>
using std::string;
using std::stringstream;
using std::cerr;

class DLList {
 public:
  /*
   * This is the constructor.
   * It sets head_ and tail_ to NULL and size_(0).
   */
  DLList() : size_(0), head_(NULL), tail_(NULL) {}

  /*
   * This is the destructor.
   * It calls the Clear() function.
   */
  ~DLList();

  /*
   * This is the accessor for size_.
   * @return unsigned int - the size of the linked list.
   */
  unsigned int GetSize() const;

  /*
   * Creates a new DLNode with the contents of the parameter,
   * and adds that node to the front of the list.
   * @param int number - an int value to save into the contents of the new node.
   */
  void PushFront(int number);

  /*
   * Creates a new DLNode with the contents of the parameter,
   * and adds that node to the end of the list.
   * @param int number - an int value to save into the contents of the new node.
   */
  void PushBack(int number);

  /*
   * Returns the integer value of the node at the front of the list.
   * If list is empty, prints a message to stderr and returns 0.
   * @return int - the contents of the front node.
   */
  int GetFront() const;

  /*
   * Returns the integer value of the node at the end of the list.
   * If list is empty, prints a message to stderr and returns 0.
   * @return int - the contents of the end node.
   */
  int GetBack() const;

  /*
   * Deletes the front node in the linked list.
   * If list is empty, prints a message to stderr and returns.
   */
  void PopFront();

  /*
   * Deletes the end node in the linked list.
   * If list is empty, prints a message to stderr and returns.
   */
  void PopBack();

  /*
   * Finds and deletes only the first node that matches the value parameter.
   * If the value is not found, prints a message to stout and returns.
   * @param value - The value to be removed from the list.
   */
  void RemoveFirst(int value);

  /*
   * Finds and deletes all nodes that match the value parameter.
   * If the value is not found, prints a message to stout and returns.
   * @param value - The value to be deleted from the list in all occurances.
   */
  void RemoveAll(int value);

  /*
   * Determines if a given value exists in the linked list.
   * @param int value - The integer value to find.
   * @return bool - true if the value was found, else false.
   */
  bool Exists(int value);

  /*
   * Clears all nodes from the linked list,
   * resets head_ and tail_ to NULL and size_ to 0.
   */
  void Clear();

  /*
   * Outputs the contents of the list as a comma-separated list
   * starting at the first node and ending at the last node.
   * Ex: "1, 2, 3".
   * If the list is empty, prints a message to stderr and returns "".
   * @return string - The linked list as a comma-separated string,
   *                - or the empty string "" if the list is empty.
   * @uses stringstream
   */
  string ToStringForwards();

  /*
   * Outputs the contents of the list as a comma-separated list
   * starting at the last node and ending at the first node.
   * Ex: "3, 2, 1".
   * If the list is empty, prints a message to stderr and returns "".
   * @return string - The linked list as a comma-separated string,
   *                - or the empty string "" if the list is empty.
   * @uses stringstream
   */
  string ToStringBackwards();

 private:
  // the number of items in the list
  unsigned int size_;
  // pointer to the head node
  DLNode* head_;
  // pointer to the tail node
  DLNode* tail_;
};

#endif /* DL_LIST_H */
