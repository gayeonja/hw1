#include "split.h"
#include <iostream>
using namespace std; 

int main() {

  Node e( 5, nullptr ); 
  Node d( 1, &e ); 
  Node c( 40, &d ); 
  Node b( 10, &c ); 
  Node a( 9, &b ); 
  
  Node* li = &a; 
  Node* odd = NULL; 
  Node* even = NULL; 

  split( li, odd, even ); 

  cout << "odd list: "; 
  while ( odd != NULL ){
    cout << odd->value << " "; 
    odd = odd->next; 
  }
  cout << endl; 

  cout << "even list: "; 
  while ( even != NULL ){
    cout << even->value << " "; 
    even = even->next; 
  }
  cout << endl; 

  cout << "original list: "; 
  if ( li == NULL ){
    cout << "nothing"; 
  }
  else{
    while ( li->next != nullptr ){
    cout << li->value << " "; 
    even = li->next; 
    }
  }
  cout << endl; 
  
  return 0; 
}