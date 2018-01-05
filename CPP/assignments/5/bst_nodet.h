/*
 * Name        : bst_nodet.h
 * Author      : Konstantin Rebrov
 * Date        : 05/16/2017
 * Language    : C++
 * Description : Models information about a single node in the BSTreeT
 */

#ifndef BST_NODET_H
#define BST_NODET_H

template<typename T>
class BSTNodeT {
 public:
  /*
   * Sets the templated contents to its default
   * Sets the count to 0
   * Sets the left child to NULL
   * Sets the right child to NULL
   */
  BSTNodeT();

  /*
   * The constructor sets the internal T data_ (of any type) to
   * the parameter.
   * Sets the count to 0
   * Sets the left child to NULL
   * Sets the right child to NULL
   * @param const T &data - the const data variable is of any type.
   *                        It is a const pass by reference to remove
   *                        inefficiency passing in structs.
   *                        That value is copied into the internal T data_.
   */
  BSTNodeT(const T &data);

  /*
   * The destructor sets the left child to NULL and the right child to NULL.
   */
  ~BSTNodeT();

  /*
   * This is the setter for data_.
   * @param const T &data - Sets the internal T data_ to
   *                         the given parameter's value.
   */
  void SetContents(const T &data);

  /*
   * This is the setter for left_child_.
   * Sets the internal left pointer to the given parameter's value.
   */
  void SetLeft(BSTNodeT* node);

  /*
   * This is the setter for right_child_.
   * Sets the internal right pointer to the given parameter's value.
   */
  void SetRight(BSTNodeT* node);

  /*
   * Increments the count by 1.
   */
  void IncrementCount();

  /*
   * Decrements the count by 1.
   */
  void DecrementCount();

  /*
   * This is the accessor for data_.
   * @return T - the value of the templated contents
   */
  T GetContents() const;

  /*
   * This is the accessor for left_child_.
   * @return BSTNodeT*& - a pointer by reference to the left node
   */
  BSTNodeT<T>*& GetLeft();

  /*
   * This is the accessor for right_child_.
   * @return BSTNodeT*& - a pointer by reference to the right node
   */
  BSTNodeT<T>*& GetRight();

  /*
   * This is the accessor for count_.
   * @return unsigned int - returns the count
   */
  unsigned int GetCount();

 private:
  T data_;
  unsigned int count_;
  BSTNodeT<T>* left_child_;
  BSTNodeT<T>* right_child_;
};

template<typename T>
BSTNodeT<T>::BSTNodeT() : count_(0), left_child_(NULL), right_child_(NULL) {
  data_ = T();
}

template<typename T>
BSTNodeT<T>::BSTNodeT(const T &data) : count_(0), left_child_(NULL),
                                       right_child_(NULL) {
  data_ = data;
}

template<typename T>
BSTNodeT<T>::~BSTNodeT() {
  left_child_ = NULL;
  right_child_ = NULL;
}

template<typename T>
void BSTNodeT<T>::SetContents(const T &data) {
  data_ = data;
}

template<typename T>
void BSTNodeT<T>::SetLeft(BSTNodeT* node) {
  left_child_ = node;
}

template<typename T>
void BSTNodeT<T>::SetRight(BSTNodeT* node) {
  right_child_ = node;
}

template<typename T>
void BSTNodeT<T>::IncrementCount() {
  count_++;
}

template<typename T>
void BSTNodeT<T>::DecrementCount() {
  count_--;
}

template<typename T>
T BSTNodeT<T>::GetContents() const {
  return data_;
}

template <typename T>
BSTNodeT<T>*& BSTNodeT<T>::GetLeft() {
  return left_child_;
}

template <typename T>
BSTNodeT<T>*& BSTNodeT<T>::GetRight() {
  return right_child_;
}

template <typename T>
unsigned int BSTNodeT<T>::GetCount() {
  return count_;
}

#endif /* BST_NODET_H */

