#include <iostream>
#include <assert.h>
#include "BoundedQueue.cpp"

//Author: Damas Mlabwa
//Date: October 31, 2013

using namespace std;
int main(int argc, char *argv[]) {
  
  //Creating BoundedQueue Object of Size 10
  BoundedQueue *bq = new BoundedQueue(10);
    
  //Fill BoundedQueue with integers 0 to 9
  int i = 0;
  for(int i = 0; i < 10; i++){
    bq -> enqueue(i);
  }
  
  //Test if size of the Queue is 10 to ensure that
  //elements have been added
  assert(bq -> getSize() == 10);
  
  //Test to see if queue maximum size is observed, and
  //no elements are added once queue is full
  bq -> enqueue(10);
  bq -> enqueue(11);
  
  //asserting size should return 10
  assert(bq -> getSize() == 10);
  
  //assert that this size is queue's maximum size
  assert(bq -> isFull() == true);
  
  //remove an element from the queue and assert size
  assert(bq -> dequeue() == 0); //first out should be zero
  assert(bq -> getSize() == 9);
  assert(bq -> isFull() == false); //queue not full
  
  //remove all elements and see if they are removed in correct order
  int j = 0;
  for(j = 1; j < 10; j++){
    assert(bq -> dequeue() == j);
  }
  
  //check if array is empty
  assert(bq -> isEmpty() == true);
  
  cout << "Sucess! No Error Found\n";

}
