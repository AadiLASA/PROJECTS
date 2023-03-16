#include<stdio.h>
#include<iostream>
#include<math.h>
#include "stack.h"
#include "disc.h"
#include <vector>
using namespace std;

Stack::Stack()
{
pTop = new Node();
}
/*
Stack::~Stack()
{
	// delete data;
}
*/

void Stack::push(void* inData)
{
  if (pTop==NULL){
    pTop = new Node;
  }
  Node* current = new Node;
    current->pNext=pTop;
  current->data=inData;
  pTop = current;

}
void* Stack::pop()
{
	// your code
  struct Node* current;
  if(pTop==NULL){
    return NULL;
  }
  else{
    current = pTop;
    pTop = pTop->pNext;
    current -> pNext = NULL;
    void* result = current->data;
    delete current;
    return result;
  }
}

void* Stack::top()
{
	// your code
  void* result = pTop->data;
  return result;
}

bool Stack::empty()
{
	// your code
  if(pTop==NULL){
    return true;
  }
  return false;
}

void Stack::display()
{
	// //cout<<endl;
	// Node *p1;
	// p1 = pTop;
  // //cout<<"Display!"<<endl;
	// while (p1 != NULL)
	// {
  //   //cout<<"Display!"<<endl;
	// 	cout<< ((Disc*)(p1->data))->toString()<<"\t";
	// 	p1 = p1->pNext;
  //   //cout<<"Display!"<<endl;
	// }
    cout << "[ ";
    Node *n = pTop;
  vector<Disc*> vect;
    while (n->pNext != nullptr) {
        auto* d= static_cast<Disc*>(n->data);
      
      vect.push_back(d);
        //cout<<d->toString();
        n = n->pNext;
     
     //   cout << (n->pNext == nullptr ? "" : ", ");
    }
  for (int i = vect.size() - 1; i >= 0; i--) {
    cout<<vect[i]->toString()<<" ";
}
	  cout << "]" << endl;
	//cout<<"Display!"<<endl;
}


