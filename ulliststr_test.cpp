/* Write your test code for the ULListStr in this file */

#include "ulliststr.h"
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
  ULListStr test;

  cout << "---------------basics test---------------" << endl; 

  test.pop_front(); 
  test.pop_back(); 

  test.push_front("5"); 
  test.push_back("6"); 
  test.push_front("4"); 
  test.push_back("7"); 
  test.push_front("3"); 
  test.push_front("2"); 
  test.push_front("1"); 
  test.push_back("8"); 
  test.push_back("9"); 
  test.push_front("0"); 

  cout << "Initial List: "; 
  cout << test.get(0) << " "; 
  cout << test.get(1) << " "; 
  cout << test.get(2) << " "; 
  cout << test.get(3) << " "; 
  cout << test.get(4) << " "; 
  cout << test.get(5) << " "; 
  cout << test.get(6) << " "; 
  cout << test.get(7) << " "; 
  cout << test.get(8) << " "; 
  cout << test.get(9) << " "; 
  cout << endl; 

  test.pop_front(); 
  test.pop_back(); 

  cout << "Pop front and back test: "; 
  cout << test.get(0) << " "; 
  cout << test.get(1) << " "; 
  cout << test.get(2) << " "; 
  cout << test.get(3) << " "; 
  cout << test.get(4) << " "; 
  cout << test.get(5) << " "; 
  cout << test.get(6) << " "; 
  cout << test.get(7) << " "; 
  cout << endl; 
  
  cout << "Front test: " << test.front() << endl; 
  cout << "Back test: " << test.back() << endl; 

  test.pop_front(); 
  test.pop_back(); 
  test.pop_front(); 
  test.pop_back(); 
  test.pop_front(); 
  test.pop_back(); 
  test.pop_front(); 
  test.pop_back(); 

  cout << "------------end of basics test------------" << endl; 
  cout << endl; 

  cout << "--------------pushback test--------------" << endl; 
  cout << "Tests every case in function: " << endl; 
  test.push_back("0"); 
  test.push_back("1"); 
  test.push_back("2"); 
  test.push_back("3"); 
  test.push_back("4"); 
  test.push_back("5"); 
  test.push_back("6"); 
  test.push_back("7"); 
  test.push_back("8"); 
  test.push_back("9"); 
  test.push_back("10"); 

  cout << test.get(0) << " "; 
  cout << test.get(1) << " "; 
  cout << test.get(2) << " "; 
  cout << test.get(3) << " "; 
  cout << test.get(4) << " "; 
  cout << test.get(5) << " "; 
  cout << test.get(6) << " "; 
  cout << test.get(7) << " "; 
  cout << test.get(8) << " ";
  cout << test.get(9) << " ";  
  cout << test.get(10) << " "; 
  cout << endl; 

  cout << "------------end pushback test------------" << endl;
  cout << endl;  
  
  cout << "--------------popback test---------------" << endl; 
  cout << "Tests every case in function: " << endl; 
  test.pop_back(); 
  test.pop_back(); 
  test.pop_back(); 
  test.pop_back(); 
  test.pop_back(); 
  test.pop_back(); 
  test.pop_back(); 
  test.pop_back(); 
  test.pop_back(); 
  test.pop_back(); 
  test.pop_back(); 
  cout << "Size: " << test.size() << endl; 
  cout << "------------end popback test-------------" << endl; 
  cout << endl; 
  
  cout << "-------------pushfront test--------------" << endl; 
  cout << "Tests every case in function: " << endl; 
  test.push_front("10"); 
  test.push_front("9"); 
  test.push_front("8"); 
  test.push_front("7"); 
  test.push_front("6"); 
  test.push_front("5"); 
  test.push_front("4"); 
  test.push_front("3"); 
  test.push_front("2"); 
  test.push_front("1"); 
  test.push_front("0"); 

  cout << test.get(0) << " "; 
  cout << test.get(1) << " "; 
  cout << test.get(2) << " "; 
  cout << test.get(3) << " "; 
  cout << test.get(4) << " "; 
  cout << test.get(5) << " "; 
  cout << test.get(6) << " "; 
  cout << test.get(7) << " "; 
  cout << test.get(8) << " ";
  cout << test.get(9) << " ";  
  cout << test.get(10) << " "; 
  cout << endl; 
  cout << "-----------end pushfront test------------" << endl; 
  cout << endl; 

  cout << "--------------popfront test--------------" << endl; 
  cout << "Tests every case in function: " << endl; 
  test.pop_front(); 
  test.pop_front(); 
  test.pop_front(); 
  test.pop_front(); 
  test.pop_front(); 
  test.pop_front(); 
  test.pop_front(); 
  test.pop_front(); 
  test.pop_front(); 
  test.pop_front(); 
  test.pop_front(); 
  cout << "Size: " << test.size() << endl; 
  cout << "------------end popfront test------------" << endl; 
  cout << endl; 



  return 0;
}

