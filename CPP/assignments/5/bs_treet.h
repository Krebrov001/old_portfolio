/*
 * Name        : bs_treet.h
 * Author      : Konstantin Rebrov
 * Date        : 05/16/2017
 * Language    : C++
 * Description : A templated Binary Search Tree class to hold templated nodes.
 */

#ifndef BS_TREET_H
#define BS_TREET_H

#include "bst_nodet.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

template <typename T>
class BSTreeT {
 public:
  /*
   * The constructor Initializes root to NULL and your node count to 0.
   */
  BSTreeT();

  /*
   * The destructor calls the Clear() function.
   */
  ~BSTreeT();

  /*
   * This is the accessor for size_
   * @return - the number of nodes in the tree.
   */
  unsigned int GetSize() const;

  /*
   * This is the public Clear() function.
   * It calls the private Clear(BSTNodeT*) function.
   * Deletes all nodes in the tree. (Frees the Memory)
   */
  void Clear();

  /*
   * This is the public Insert(const T&) function.
   * It calls the private Insert(const T&, BSTNodeT<T>*&) function.
   * This function adds a value to the tree.
   * @param const T &value - The value to add to the tree.
   * @return unsigned int - Returns the count of the value in the node.
   *                        i.e. returns 1 the first time the value is added
   *                        to the tree. Returns 2 the second time the value
   *                        is added, 3 the third time, etc.
   */
  unsigned int Insert(const T &value);

  /*
   * This function searches for a value in the tree.
   * @param const T &value - The value to search for.
   * @return bool - If found returns true, else returns false.
   */
  bool Exists(const T &value);

  /*
   * This is the public Remove(const T&) function.
   * It calls the private Remove(const T&, BSTNodeT<T>*&) function.
   * This function removes the given value from the tree.
   * @param const T &value - the value to remove from the tree.
   * @return int - Returns the current count of the value in the tree,
   *               0 if it was just removed,
   *               and -1 if it doesn't exist in the tree.
   */
  int Remove(const T &value);

  /*
   * This is the public Get(const T&) function.
   * It calls the private Get(const T&, BSTNodeT<T>*) function.
   * Searches for a particular value.
   * @param const T &value - The value to search for in the tree.
   * @return BSTNodeT<T>* - Returns a pointer to the node if found
   *                        otherwise returns NULL.
   */
  BSTNodeT<T>* Get(const T &value);

  /*
   * This is the public ToStringForwards() function.
   * It calls the private ToStringForwards(BSTNodeT<T>*) function.
   * Outputs the contents of the nodes in the tree (in order) as a
   * comma separated list.
   * @return string - The contents of the tree in order.
   *                  If the list is empty return the empty string.
   */
  string ToStringForwards();

  /*
   * This is the public ToStringBackwards() function.
   * It calls the private ToStringBackwards(BSTNodeT<T>*) function.
   * Outputs the contents of the nodes in the tree (in backwards order) as a
   * comma separated list.
   * @return string - The contents of the tree in backwards order.
   *                  If the list is empty return the empty string.
   */
  string ToStringBackwards();

 private:
  BSTNodeT<T>* root_;
  unsigned int size_;

  /*
   * Deletes all nodes in the tree. (Frees the Memory)
   * @param BSTNodeT*& sub_root - The node from which to start the
   *                              deletion process. It is initialized to
   *                              root_ in the first iteration.
   */
  void Clear(BSTNodeT<T>*& sub_root);

  /*
   * This function adds a value to the tree.
   * If the value is already in the tree just increment that node's count.
   * @param const T &value - The value to add to the tree.
   * @param BSTNodeT<T>*& sub_root - The node from which to start the insertion
   *                                 function. It is a pointer by reference
   *                                 because we change what sub_root points to.
   * @return unsigned int - The count of the value in the node.
   */
  unsigned int Insert(const T &value, BSTNodeT<T>*& sub_root);

  /*
   * This function searches the tree for a particular value and decrements the
   * corresponding count. If the current count is 1 remove the node instead of
   * decrementing the count.
   * @param const T &value - the value to remove from the tree.
   * @param BSTNodeT<T>*& sub_root - The node from which to start the search.
   *                                 a pointer by reference to a BSTNodeT.
   * @return int - Returns the current count of the value in the tree,
   *               0 if it was just removed,
   *               and -1 if it doesn't exist in the tree.
   */
  int Remove(const T &value, BSTNodeT<T>*& sub_root);

  /*
   * This function finds and returns the smallest value in the tree.
   * @param - BSTNodeT<T>* sub_root - The node to start searching from.
   * @return T - The minimum value of the templated type in the tree.
   */
  T FindMin(BSTNodeT<T>* sub_root) const;

  /*
   * This function finds and returns the largest value in the tree.
   * @param - BSTNodeT<T>* sub_root - The node to start searching from.
   * @return T - The maximum value of the templated type in the tree.
   */
  T FindMax(BSTNodeT<T>* sub_root) const;

  /*
   * Searches for a particular value.
   * @param const T &value - The value to search for in the tree.
   * @param BSTNodeT<T>* sub_root - The node to start the search from.
   * @return BSTNodeT<T>* - Returns a pointer to the node if found
   *                        otherwise returns NULL.
   */
  BSTNodeT<T>* Get(const T &value, BSTNodeT<T>* sub_root);

  /*
   * Outputs the contents of the nodes in the tree (in order) as a
   * comma separated list.
   * @param BSTNodeT<T>* sub_root - The node to start the output from.
   * @return string - The contents of the tree in order.
   *                  If the list is empty return the empty string.
   */
  string ToStringForwards(BSTNodeT<T>* sub_root);

  /*
   * Outputs the contents of the nodes in the tree (in backwards order) as a
   * comma separated list.
   * @param BSTNodeT<T>* sub_root - The node to start the output from.
   * @return string - The contents of the tree in backwards order.
   *                  If the list is empty return the empty string.
   */
  string ToStringBackwards(BSTNodeT<T>* sub_root);
};

template <typename T>
BSTreeT<T>::BSTreeT() : root_(NULL), size_(0) {}

template <typename T>
BSTreeT<T>::~BSTreeT() {
  Clear();
}

template <typename T>
unsigned int BSTreeT<T>::GetSize() const {
  return size_;
}

template <typename T>
void BSTreeT<T>::Clear() {
  Clear(root_);
}

template <typename T>
void BSTreeT<T>::Clear(BSTNodeT<T>*& sub_root) {
  if (sub_root != NULL) {
    Clear(sub_root->GetLeft());
    Clear(sub_root->GetRight());
    delete sub_root;
    sub_root = NULL;
    size_--;
  }
}

template <typename T>
unsigned int BSTreeT<T>::Insert(const T &value) {
  return Insert(value, root_);
}

template <typename T>
unsigned int BSTreeT<T>::Insert(const T &value, BSTNodeT<T>*& sub_root) {
  if (sub_root == NULL) {
    sub_root = new BSTNodeT<T>(value);
    size_++;
    sub_root->IncrementCount();
    return sub_root->GetCount();
  } else if (value < sub_root->GetContents()) {
    return Insert(value, sub_root->GetLeft());
  } else if (value > sub_root->GetContents()) {
    return Insert(value, sub_root->GetRight());
  } else {
    sub_root->IncrementCount();
    return sub_root->GetCount();
  }
}

template <typename T>
bool BSTreeT<T>::Exists(const T &value) {
  return ((Get(value, root_) == NULL) ? false : true);
}

template <typename T>
int BSTreeT<T>::Remove(const T &value) {
  return Remove(value, root_);
}

template <typename T>
int BSTreeT<T>::Remove(const T &value, BSTNodeT<T>*& sub_root) {
  if (sub_root == NULL) {
    return -1;  // the value doesn't exist in the tree
  } else if (value == sub_root->GetContents()) {
    if (sub_root->GetCount() == 1) {
      if ((sub_root->GetLeft() == NULL) && (sub_root->GetRight() == NULL)) {
        delete sub_root;
        sub_root = NULL;
      } else if ((sub_root->GetLeft() != NULL) &&
                 (sub_root->GetRight() == NULL)) {
        BSTNodeT<T>* temp = sub_root;
        sub_root = sub_root->GetLeft();
        delete temp;
      } else if ((sub_root->GetLeft() == NULL) &&
                 (sub_root->GetRight() != NULL)) {
        BSTNodeT<T>* temp = sub_root;
        sub_root = sub_root->GetRight();
        delete temp;
      } else {  // ((sub_root->GetLeft() != NULL) &&
                //  (sub_root->GetRight() != NULL))
        T smallest = FindMin(sub_root->GetRight());
        sub_root->SetContents(smallest);
        Remove(smallest, sub_root->GetRight());
        size_++;
      }
      size_--;
      return 0;
    } else {
      sub_root->DecrementCount();
    }
    return sub_root->GetCount();
  } else if (value < sub_root->GetContents()) {
    return Remove(value, sub_root->GetLeft());
  } else {  // (value > sub_root->GetContents())
    return Remove(value, sub_root->GetRight());
  }
}

template <typename T>
T BSTreeT<T>::FindMin(BSTNodeT<T>* sub_root) const {
  if (size_ == 0) {
    return T();
  } else if (sub_root->GetLeft() == NULL) {
    return sub_root->GetContents();
  } else {
    return FindMin(sub_root->GetLeft());
  }
}

template <typename T>
T BSTreeT<T>::FindMax(BSTNodeT<T>* sub_root) const {
  if (size_ == 0) {
    return T();
  } else if (sub_root->GetRight() == NULL) {
    return sub_root->GetContents();
  } else {
    return FindMax(sub_root->GetRight());
  }
}

template <typename T>
BSTNodeT<T>* BSTreeT<T>::Get(const T &value) {
  return Get(value, root_);
}

template <typename T>
BSTNodeT<T>* BSTreeT<T>::Get(const T &value, BSTNodeT<T>* sub_root) {
  if (sub_root == NULL) {
    return NULL;
  }
  if (value < sub_root->GetContents()) {
    return Get(value, sub_root->GetLeft());
  } else if (value > sub_root->GetContents()) {
    return Get(value, sub_root->GetRight());
  } else {
    return sub_root;  // pointer to the found node
  }
}

template <typename T>
string BSTreeT<T>::ToStringForwards() {
  return ToStringForwards(root_);
}

template <typename T>
string BSTreeT<T>::ToStringForwards(BSTNodeT<T>* sub_root) {
  if (sub_root == NULL)
    return "";
  stringstream ss;
  ss << ToStringForwards(sub_root->GetLeft());
  if (sub_root->GetContents() == FindMax(root_)) {
    ss << sub_root->GetContents();
  } else {
    ss << sub_root->GetContents() << ", ";
  }
  ss << ToStringForwards(sub_root->GetRight());
  return ss.str();
}

template <typename T>
string BSTreeT<T>::ToStringBackwards() {
  return ToStringBackwards(root_);
}

template <typename T>
string BSTreeT<T>::ToStringBackwards(BSTNodeT<T>* sub_root) {
  if (sub_root == NULL)
    return "";
  stringstream ss;
  ss << ToStringBackwards(sub_root->GetRight());
  if (sub_root->GetContents() == FindMin(root_)) {
    ss << sub_root->GetContents();
  } else {
    ss << sub_root->GetContents() << ", ";
  }
  ss << ToStringBackwards(sub_root->GetLeft());
  return ss.str();
}

#endif /* BS_TREET_H */

