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
/**
* Adds a new value to the back of the list
*   - MUST RUN in O(1)
*/
void ULListStr::push_back(const std::string& val){
  // list completely empty 
  if ( empty() ){
    Item * newHead = new Item; 
    head_ = newHead; 
    tail_ = newHead; 
    head_->val[head_->last++] = val; 
    size_++; 
  }
  // tail is full 
  else if ( tail_->last == ARRSIZE ){
    Item * newTail = new Item; 
    tail_->next = newTail; 
    newTail->prev = tail_; 
    tail_ = newTail; 
    tail_->val[tail_->last++] = val; 
    size_++; 
  }
  // tail is not empty 
  else {
    tail_->val[tail_->last++] = val; 
    size_++; 
  }
}

/**
* Removes a value from the back of the list
*   - MUST RUN in O(1)
*/
void ULListStr::pop_back(){
  // nothing in list 
  if ( empty() ){
    return; 
  }
  // only one element 
  else if ( size_ == 1 ){
    head_->val[head_->first] = ""; 
    head_->first = 0; 
    head_->last = 0; 
    size_--; 
  }
  // if first of item 
  else if ( tail_->first == tail_->last - 1 ){
    tail_->prev->next = NULL; 
    tail_ = tail_->prev;
    size_--;  
  }
  else{
    tail_->val[tail_->last - 1] = ""; 
    tail_->last--; 
    size_--; 
  }
}
  
/**
* Adds a new value to the front of the list.
* If there is room before the 'first' value in
* the head node add it there, otherwise, 
* allocate a new head node.
*   - MUST RUN in O(1)
*/
void ULListStr::push_front(const std::string& val){
  // list completely empty 
  if ( empty() ){
    Item * newHead = new Item; 
    head_ = newHead; 
    tail_ = newHead; 
    head_->val[head_->last++] = val; 
    size_++; 
  }
  // if head is full 
  else if ( head_->first == 0 ){
    Item* newHead = new Item; 
    head_->prev = newHead; 
    newHead->next = head_; 
    head_ = newHead; 
    head_->val[ARRSIZE-1] = val; 
    head_->first = ARRSIZE-1; 
    head_->last = ARRSIZE; 
    size_++; 
  }
  // if not full 
  else {
    head_->first--; 
    head_->val[head_->first] = val; 
    size_++; 
  }
}

/**
* Removes a value from the front of the list
*   - MUST RUN in O(1)
*/
void ULListStr::pop_front(){
  // nothing in list 
  if ( empty() ){
    return; 
  }
  // only one element 
  else if ( size_ == 1 ){
    head_->val[head_->first] = ""; 
    head_->first = 0; 
    head_->last = 0; 
    size_--; 
  }
  // if last of item 
  else if ( head_->first == head_->last - 1 ){
    head_->next->prev = NULL; 
    head_ = head_->next;
    size_--;  
  }
  else{
    head_->val[head_->first] = ""; 
    head_->first++; 
    size_--; 
  }
}

/**
* Returns a const reference to the back element
*   - MUST RUN in O(1)
*/
std::string const & ULListStr::back() const{
  return tail_->val[tail_->last - 1]; 
}

/**
* Returns a const reference to the front element
*   - MUST RUN in O(1)
*/
std::string const & ULListStr::front() const{
  return head_->val[head_->first]; 
}

/** 
* Returns a pointer to the item at index, loc,
*  if loc is valid and NULL otherwise
*   - MUST RUN in O(n) 
*/
std::string* ULListStr::getValAtLoc(size_t loc) const{
  if ( empty() ){
    return NULL; 
  }

  // local variables 
  Item* where = head_; 
  int inValCount = head_->first; 
  std::string* ptr; 

  // loop through 
  for ( unsigned int i = 0; i <= loc; i++ ){
    if ( inValCount == (int) where->last){
      // at end of array 
      if ( where->next == NULL ){
        return NULL; 
      }
      where = where->next; 
      inValCount = where->first; 
    }
    // at loc 
    if ( i == loc ){
      ptr = &where->val[inValCount]; 
      return ptr; 
    }
    else{
      inValCount++; 
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
