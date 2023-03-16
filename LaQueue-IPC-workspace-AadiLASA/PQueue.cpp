/*
 * LaQueue
 * 
 * 
 * This is part of a series of labs for the Liberal Arts and Science Academy.
 * The series of labs provides a mockup of an POSIX Operating System
 * referred to as LA(SA)nix or LAnix.
 *  
 * (c) copyright 2018, James Shockey - all rights reserved
 * 
 * */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "PQueue.h"



/*
 * Class Priority Queue
 */

		
/*
* Insert into Priority Queue
*/
void PQueue::push(void *item, int priority)
{
	/* Your code here */
  node* temp = new node;
  temp->data=item;
  temp->priority=priority;
  if(front==nullptr){
    front = temp;
  }
  else if(front->priority>priority){
    temp->link = front;
    front = temp;
  }
  else{
    while(!(front->link==nullptr) && front->link->priority<=priority){
      front=front->link;
      temp->link = front->link;
      front=temp->link;
      
    }
  }
}

/*
 * Delete from Priority Queue
 */
void* PQueue::top()
{
	/* Your code here */
  // node* temp = new node();
  // int biggest = front->priority;
  // void* data;
  // while(front->data!=NULL){
  //   if(front->link->priority>biggest){
  //     data=front->link->data;
  //     biggest=front->link->priority;
  //   }
  //    front=front->link;
  //     temp->link = front->link;
  //     front=temp->link;
  if(front==nullptr){
    return nullptr;
  }
  return front->data;

}
/*
 * Delete from Priority Queue
 */
void PQueue::pop()
{
	/* Your code here */
//  node* temp = new node;
  if(front->data==nullptr){
    return;
  }
  std::cout<<(char*)front->data<<"\n";
  //temp->data=front->data;
  front=front->link;
 // return temp->data;
}

/*
 * Print Priority Queue
 */
void PQueue::display()
{

	/* Your code here */
//node* temp = front;
	/* Use the following out command for the data */
  node* temp = front;
  while(temp!=nullptr){
	std::cout<<front->priority<<"\n "<<(char*)front->data<<std::endl;
    temp=temp->link;
    }
}
	