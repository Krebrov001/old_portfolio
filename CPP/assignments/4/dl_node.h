/*
 * Name        : dl_node.h
 * Author      : Konstantin Rebrov
 * Date        : 04/26/2017
 * Language    : C++
 * Description : This file defines the class DLNode.
 */

#ifndef DL_NODE_H
#define DL_NODE_H

#include <cstddef>

class DLNode {
 public:
  /*
   * This is the constructor for the DLNode class.
   * It sets contents_ to 0 and the DLNode pointers to NULL.
   */
  DLNode() : contents_(0), next_(NULL), prev_(NULL) {}

  /*
   * This is the destructor for the DLNode class.
   * It doesn't really do anything.
   */
  ~DLNode() {}

  /*
   * Sets the internal integer to the given parameter's value.
   * @param int data - the integer value to save into contents_.
   */
  void SetContents(int data);

  /*
   * Sets the internal next pointer to the given parameter's value.
   * @param DLNode* next - a pointer to a DLNode.
   */
  void SetNext(DLNode* next);

  /*
   * Sets the internal previous pointer to the given parameter's value.
   * @param DLNode* previous - a pointer to a DLNode.
   */
  void SetPrevious(DLNode* previous);

  /*
   * This is the accessor for contents_.
   * @return int - the value of the internal integer.
   */
  int GetContents() const;

  /*
   * This function returns a pointer to the next node.
   * @return DLNode* - the memory address of the next node.
   */
  DLNode* GetNext() const;

  /*
   * This function returns a pointer to the previous node.
   * @return DLNode* - the memory address of the previous node.
   */
  DLNode* GetPrevious() const;

 private:
  // the data of this DLNode
  int contents_;
  // a pointer to the next DLNode
  DLNode *next_;
  // a pointer to the previous DLNode
  DLNode *prev_;
};

#endif /* DL_NODE_H */
