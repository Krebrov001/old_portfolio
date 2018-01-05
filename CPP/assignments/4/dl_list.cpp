/*
 * Name        : dl_list.cpp
 * Author      : Konstantin Rebrov
 * Date        : 04/27/2017
 * Language    : C++
 * Description : This file defines member functions of the class DLList.
 */

#include "dl_list.h"
using std::cout;

DLList::~DLList() {
  Clear();
}

unsigned int DLList::GetSize() const {
  return size_;
}

void DLList::PushFront(int number) {
  DLNode* new_node = new DLNode;
  new_node->SetContents(number);
  new_node->SetNext(head_);
  new_node->SetPrevious(NULL);
  if (head_ != NULL) {
    head_->SetPrevious(new_node);
  }
  head_ = new_node;
  if (size_ == 0)
    tail_ = new_node;
  size_++;
}

void DLList::PushBack(int number) {
  DLNode* new_node = new DLNode;
  new_node->SetContents(number);
  new_node->SetNext(NULL);
  new_node->SetPrevious(tail_);
  if (tail_ != NULL) {
    tail_->SetNext(new_node);
  }
  tail_ = new_node;
  if (size_ == 0)
    head_ = new_node;
  size_++;
}

int DLList::GetFront() const {
  if (size_ == 0) {
    cerr << "List Empty";
    return 0;
  }
  return head_->GetContents();
}

int DLList::GetBack() const {
  if (size_ == 0) {
    cerr << "List Empty";
    return 0;
  }
  return tail_->GetContents();
}

void DLList::PopFront() {
  if (size_ == 0) {
    cerr << "List Empty";
    return;
  }
  DLNode* temp = head_;
  head_ = head_->GetNext();
  delete temp;
  if (head_ != NULL) {
    head_->SetPrevious(NULL);
  } else {
    tail_ = NULL;
  }
  size_--;
}

void DLList::PopBack() {
  if (size_ == 0) {
    cerr << "List Empty";
    return;
  }
  DLNode* temp = tail_;
  tail_ = tail_->GetPrevious();
  delete temp;
  if (tail_ != NULL) {
    tail_->SetNext(NULL);
  } else {
    head_ = NULL;
  }
  size_--;
}

void DLList::RemoveFirst(int value) {
  if (size_ == 0) {
    cerr << "Not Found";
    return;
  }
  DLNode* trailer = head_;
  DLNode* iterator = head_;
  if (iterator->GetContents() == value) {
    PopFront();
    return;
  }
  while (iterator != NULL && iterator->GetContents() != value) {
    trailer = iterator;
    iterator = iterator->GetNext();
  }
  if (iterator == NULL) {
    cerr << "Not Found";
  } else if (iterator == tail_) {
    PopBack();
  } else {
    trailer->SetNext(iterator->GetNext());
    (iterator->GetNext())->SetPrevious(trailer);
    delete iterator;
    size_--;
  }
  return;
}

void DLList::RemoveAll(int value) {
  if (size_ == 0) {
    cerr << "Not Found";
    return;
  }
  DLNode* trailer = head_;
  DLNode* iterator = head_;
  bool deleted = false;
  while (iterator != NULL) {
    if (iterator->GetContents() == value) {
      if (iterator == head_) {
        PopFront();
        iterator = head_;
        trailer = head_;
      } else if (iterator == tail_) {
        PopBack();
        iterator = NULL;
      } else {
        trailer->SetNext(iterator->GetNext());
        (iterator->GetNext())->SetPrevious(trailer);
        delete iterator;
        iterator = trailer->GetNext();
        size_--;
      }
      deleted = true;
    } else {
      trailer = iterator;
      iterator = iterator->GetNext();
    }
  }
  if (size_ == 0) {
    head_ = NULL;
    tail_ = NULL;
  }
  if (!deleted) {
    cerr << "Not Found";
  }
  return;
}

bool DLList::Exists(int value) {
  DLNode* iterator = head_;
  bool found = false;
  while (iterator != NULL) {
    if (iterator->GetContents() == value) {
      found = true;
      break;
    }
    iterator = iterator->GetNext();
  }
  return found;
}

void DLList::Clear() {
  DLNode* iterator = head_;
  while (iterator != NULL) {
    head_ = head_->GetNext();
    delete iterator;
    iterator = head_;
    size_--;
  }
  tail_ = NULL;
}

string DLList::ToStringForwards() {
  if (size_ == 0) {
    cerr << "List Empty";
    return "";
  }
  DLNode* iterator = head_;
  stringstream ss;
  while (iterator->GetNext() != NULL) {
    ss << iterator->GetContents();
    ss << ", ";
    iterator = iterator->GetNext();
  }
  ss << iterator->GetContents();
  return ss.str();
}

string DLList::ToStringBackwards() {
  if (size_ == 0) {
    cerr << "List Empty";
    return "";
  }
  DLNode* iterator = tail_;
  stringstream ss;
  while (iterator->GetPrevious() != NULL) {
    ss << iterator->GetContents();
    ss << ", ";
    iterator = iterator->GetPrevious();
  }
  ss << iterator->GetContents();
  return ss.str();
}
