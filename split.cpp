/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */
void split(Node*& in, Node*& odds, Node*& evens)
{
  isOdd( in, odds ); 
  isEven( in, evens );
}

void isOdd(Node*& in, Node*& odds){
  if ( in == NULL ){
    odds->next = NULL; 
    return; 
  }
  else if ( odds == NULL && (in->value % 2 == 1)){
    odds = in; 
    in = in->next; 
    isOdd ( in, odds ); 
  }
  else if ( in->value % 2 == 1 ){ 
    odds->next = in; 
    in = in->next; 
    isOdd ( in, odds->next ); 
  }
  else{
    isOdd ( in->next, odds ); 
  }
}

void isEven(Node*& in, Node*& evens){
  if ( in == nullptr ){
    evens->next = NULL; 
    return; 
  }
  else if ( evens == NULL ){
    evens = in; 
    in = in->next; 
    isEven ( in, evens ); 
  }
  else if ( in->value % 2 == 0 ){ 
    evens->next = in; 
    in = in->next; 
    isEven ( in, evens->next ); 
  }
  else{
    in = in->next; 
    isEven ( in, evens ); 
  }
}



/*
void split(Node*& in, Node*& odds, Node*& evens){
  if ( in == NULL ){
    odds->next = NULL; 
    evens->next = NULL; 
    return; 
  }
  else if ( in->value % 2 == 1 ){
    if ( odds == NULL ){
      odds = in; 
    }
    else {
      odds->next = in; 
      odds = odds->next; 
    }
  }
  else {
    if ( evens == NULL ){
      evens = in; 
    }
    else {
      evens->next = in; 
      evens = evens->next; 
    }
  }
  split( in->next, odds, evens ); 
}
*/


/*
void split(Node*& in, Node*& odds, Node*& evens)
{
  isOdd( in, odds ); 
  isEven( in, evens );
}

void isOdd(Node*& in, Node*& odds){
  if ( in == NULL ){
    return; 
  }
  else if ( odds == NULL && (in->value % 2 == 1)){
    odds = in; 
    isOdd ( in->next, odds ); 
  }
  else if ( odds->next == NULL ){ 
    if ( in->value % 2 == 1 ){
      odds->next->next = in->next; 
      odds->next = in; 
    }
    isOdd ( in->next, odds->next ); 
  }
  else{
    isOdd ( in->next, odds ); 
  }
}

void isEven(Node*& in, Node*& evens){
  return; 
  if ( in == NULL ){
    evens->next = NULL; 
    return; 
  }
  else if ( evens == NULL && in->value % 2 == 0 ){
    evens = in; 
    isEven ( in->next, evens ); 
  }
  else if ( evens->next == NULL ){
    if ( in->value % 2 == 0 ){ 
      evens->next->next = in->next; 
      evens->next = in; 
    }
    isEven ( in->next, evens->next ); 
  }
  isEven ( in->next, evens ); 
}
*/