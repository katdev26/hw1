#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val)
{
  if(tail_ == NULL){
    Item* newItem = new Item();
    newItem->val[0] = val;
    newItem->first = 0;
    newItem->last = 1;

    head_ = newItem;
    tail_ = newItem;
  }
  else if(tail_->last < ARRSIZE){
    tail_->val[tail_->last] = val;
    tail_->last += 1;
  }
  else{ //tail_->last == ARRSIZE
    Item* newItem = new Item();
    newItem->prev = tail_;
    tail_->next = newItem;
    tail_ = newItem;

    newItem->val[0] = val;
    newItem->first = 0;
    newItem->last = 1;
  }

  size_+= 1;
}

std::string const & ULListStr::back() const{
  return tail_->val[tail_->last - 1];
}

void ULListStr::pop_back(){

  if(tail_ == NULL){
    return;
  }

  tail_->last -= 1;
  size_ -= 1;

  if(tail_->first == tail_-> last){
    Item* tempItem = tail_;
    tail_ = tail_->prev;

    if(tail_ != NULL){
      tail_->next = NULL;
    }
    else{
      head_ = NULL;
    }

    delete tempItem;

  }
}

std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}

void ULListStr::push_front(const std::string& val){
  if(head_ == NULL){
    Item* newItem = new Item();
    newItem->val[ARRSIZE - 1] = val;

    newItem->first = ARRSIZE - 1;
    newItem->last = ARRSIZE;

    head_ = newItem;
    tail_ = newItem;
  }
  else if(head_->first > 0){
    head_->first -= 1;
    head_->val[head_->first] = val;
  }
  else{ //head->first == 0
    Item* newItem = new Item();
    newItem->next = head_;
    head_->prev = newItem;
    head_ = newItem;

    newItem->val[ARRSIZE - 1] = val;
    newItem->first = ARRSIZE - 1;
    newItem->last = ARRSIZE;
  }

  size_ += 1;

}

void ULListStr::pop_front(){
  
  if(head_ == NULL){
    return;
  }

  head_->first += 1;
  size_ -= 1;

  if(head_->first == head_->last){
    Item* tempItem = head_;
    head_ = head_->next;

    if(head_ != NULL){
      head_->prev = NULL;
    }
    else{
      tail_ = NULL;
    }

    delete tempItem;

  }
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  if(loc >= size_){
    return NULL; //safety check for bounds
  }

  Item* current = head_;

  while(current != NULL){
    size_t countElements = current->last - current->first;

    if(loc < countElements){
      return &(current->val[current->first + loc]);
    }
    else{
      loc -= countElements;
      current = current->next;
    }
    
  }

  return NULL;

}



void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
