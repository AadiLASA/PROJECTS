#include<stdio.h>
#include<iostream>
#include<math.h>
#include "stack.h"
#include "disc.h"

using namespace std;
int moveNum = 0;


void displayDisks(Stack* a,Stack* b,Stack* c){
a->display();
b->display();
c->display();
}


void moveDisks(int n, Stack *from, Stack *to, Stack *spare) {
    if (n <= 0){
      return;
    }
      

    moveDisks(n-1, from, spare, to);

    moveNum++;
    printf("\nMOVE #%d:\n", moveNum);
  

    void *temp = from->pop();
    to->push(temp); 
    
    displayDisks(from,spare,to);
  

    moveDisks(n-1, spare, to, from);
}

void toh(int n)
{
    int i, x;
	Disc* a;
	Disc* b;
	Stack* t1 = new Stack();
	Stack* t2 = new Stack();
	Stack* t3 = new Stack();
	

    for (i = n; i >= 1; i--)
    {
		//d.setSize(i);
		Disc* d = new Disc(i);
		//cout << d->toString() << "  ";
        t1->push(d);
    }
//  t1->pop();
 // displayDisks(t1,t2,t3);
  moveDisks(n,t1,t3,t2);
printf("\n\nTower of Hanoi Completed");

	// ****  Your Tower of Hanoi solution!
delete t1;
delete t2;
delete t3;

}
int main()
{
   
    int n;
    cout<<"enter the number of disks: ";
    cin>>n;
    toh(n);
    return 0;
}
