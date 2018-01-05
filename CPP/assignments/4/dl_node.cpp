/*
 * Name        : dl_node.cpp
 * Author      : Konstantin Rebrov
 * Date        : 04/26/2017
 * Language    : C++
 * Description : This file defines the member functions of the class DLNode.
 */

#include "dl_node.h"

void DLNode::SetContents(int data) {
  contents_ = data;
}

void DLNode::SetNext(DLNode* next) {
  next_ = next;
}

void DLNode::SetPrevious(DLNode* previous) {
  prev_ = previous;
}

int DLNode::GetContents() const {
  return contents_;
}

DLNode* DLNode::GetNext() const {
  return next_;
}

DLNode* DLNode::GetPrevious() const {
  return prev_;
}
