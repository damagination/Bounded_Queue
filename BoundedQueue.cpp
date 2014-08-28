#include <iostream>
#include "BoundedQueue.h"

//Author: Damas Mlabwa
//Date: October 31, 2013

using namespace std;

//creating node structure
struct Node{
  int data;
  Node *next;
};

  
//constructor
BoundedQueue::BoundedQueue(int max){
  front = NULL;
  back = NULL;
  size = 0;
  maxSize = max;
  }

//Add element to the end of the queue
void BoundedQueue::enqueue(int elem){
  //new node
  Node *temporary = new Node;
  
  if(temporary == NULL){
    //do nothing, memory not enough
    return;
  }
  
  temporary->data = elem;
  
  //if queue is empty
  if(isEmpty()){
    front = back = temporary;
  } else if(isFull()){
    //queue is full
    return;
  }else {
    back -> next = temporary;
    back = back -> next;
  }
  
  size++;
}

//Remove element at the front of the queue
int BoundedQueue::dequeue(){
  if(isEmpty()){
    //queue is empty
    return -1;
  }
  
  Node *temp = front;
  
  if(size > 0){
    front = temp -> next;
    size--;
    delete temp;
  }
  
  return temp -> data;
}

//check if the queue is empty
bool BoundedQueue::isEmpty(){
  return front == NULL;
}

//check if the queue is full
bool BoundedQueue::isFull(){
  return size == maxSize;
}

//check the size of the queue
int BoundedQueue::getSize(){
  return size;
}

//clear memory
BoundedQueue::~BoundedQueue(){
  if(isEmpty()){
    //nothing to clear
    return;
  }
  
  Node *temp = front;
  
  if(size > 0){
    front = temp -> next;
    size--;
    delete temp;
  }
 }

