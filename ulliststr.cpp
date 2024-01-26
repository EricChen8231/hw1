#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>

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
  Item *current = head_;
  while (current != nullptr)
  {
    Item *next = current->next;
    delete current;
    current = next;
  }
  head_ = tail_ = nullptr;
  size_ = 0;
}

void ULListStr::push_back(const std::string &val)
{
  if (empty())
  {
    head_ = new Item();
    tail_ = head_;
  }

  if (tail_->last == ARRSIZE) 
  {
    Item *newItem = new Item();
    newItem->prev = tail_;
    tail_->next = newItem;
    tail_ = newItem;
  }

  tail_->val[tail_->last] = val;
  tail_->last++;
  tail_->next = nullptr;
  size_++;

}
void ULListStr::push_front(const std::string &val)
{
  if (empty())
  {
    head_ = new Item();
    tail_ = head_;
  }

  if (head_->first > 0)
  {
    head_->first--;
    head_->val[head_->first] = val;
  }
  else
  {
    Item *newItem = new Item();
    newItem->next = head_;
    head_->prev = newItem;
    head_ = newItem;
    head_->first = ARRSIZE - 1;
    head_->last = ARRSIZE;
    head_->val[head_->first] = val;
  }
  size_++;
}

void ULListStr::pop_front()
{
  if (empty())
    return;

  if (head_->first < ARRSIZE - 1)
  {
    head_->first++;
  }
  else
  {
    Item *temp = head_;
    head_ = head_->next;
    if (head_ != nullptr)
    {
      head_->prev = nullptr;
      head_->first = 0;
    }
    else
    {
      tail_ = nullptr;
    }

    delete temp;
  }

  size_--;
  if (empty())
  {
    clear();
  }
}
void ULListStr::pop_back()
{
  if (empty())
    return;

  if (tail_->last > 0)
  {
  
    size_--;
    tail_->last--;
  }
  else
  {
    Item *temp = tail_;
    tail_ = tail_->prev;

    if (tail_ != nullptr)
    {
      tail_->last = ARRSIZE - 1; 
      tail_->next = nullptr;
    }
    else
    {
      head_ = nullptr;
    }
    delete temp;
    size_--;
  }
  if (empty())
  {
    clear(); 
  }
}

std::string const &ULListStr::back() const
{
  if (empty())
  {
    throw std::out_of_range("List is empty");
  }

  if (tail_->last == 0)
  {
    if (tail_->prev != nullptr)
    {
      return tail_->prev->val[ARRSIZE - 1];
    }
    else
    {
      throw std::out_of_range("List is empty");
    }
  }
  return tail_->val[tail_->last - 1];
}

std::string const &ULListStr::front() const
{
  if (empty())
  {
    throw std::out_of_range("List is empty");
  }
  return head_->val[head_->first];
}
std::string *ULListStr::getValAtLoc(size_t loc) const
{
  size_t currentPos = 0;
  Item *current = head_;
  while (current != nullptr && currentPos + (current->last - current->first) <= loc)
  {
    currentPos += (current->last - current->first);
    current = current->next;
  }
  if (current == nullptr || loc - currentPos >= current->last - current->first)
  {
    return nullptr;
  }
  size_t indexWithinNode = loc - currentPos + current->first;
  return &(current->val[indexWithinNode]);
}

