#include "disc.h"

// Implement the functions protoyped in disc.h
// Your code here
Disc::Disc(){
  size = 0;
}
Disc::Disc(int a){
    size = a;
  }
Disc::~Disc(){
  delete &size;
}
 int Disc::getSize(){
   return size;
 }
	bool Disc::setSize(int a){
    size = a;
    return true;
  }
	std::string Disc::toString(){
    return "--"+ std::to_string(size)+"--";
  }
