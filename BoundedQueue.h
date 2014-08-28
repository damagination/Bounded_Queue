#include <stdio.h>
#ifndef BOUNDEDQUEUE_H
#define BOUNDEDQUEQUE_H

//Author: Damas Mlabwa
//Date: October 31, 2013

struct Node;
class BoundedQueue;

class BoundedQueue{
 
private:
  Node *front;
  Node *back;
  int size;
  int maxSize;
  
public:
   BoundedQueue(int);
   void enqueue(int);
   int dequeue();
   bool isFull();
   bool isEmpty();
   int getSize();
   ~BoundedQueue();
  };
  
#endif
