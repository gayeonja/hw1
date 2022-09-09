#ifndef SPLIT_H
#define SPLIT_H


struct Node 
{
  int value;
  Node* next;

  /**
   * Initializing constructor
   */
  Node(int v, Node* n)
  {
    value = v;
    next = n;
  }
};

void split(Node*& in, Node*& odds, Node*& evens);
// WRITE YOUR CODE HERE
void isOdd(Node*& in, Node*& odds); 
void isEven(Node*& in, Node*& evens); 
#endif
