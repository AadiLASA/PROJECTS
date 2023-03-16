#include <iostream>
#include <string>
#include <cmath>
using namespace std;


// returns count of non-overlapping occurrences of 'sub' in 'str'
int countSubstring(const string& str, const string& sub)
{
	if (sub.length() == 0) return 0;
	int count = 0;
	for (int offset = str.find(sub); offset != string::npos; 
		offset = str.find(sub, offset + sub.length()))
	{
		++count;
	}
	return count;
}

int countWords(string str){
  int count = 0;
  for(int i = 0;i<str.length();i++){
    if((str[i+1]>='a' && str[i+1]<='z') || (str[i+1]>='A' && str[i+1]<='Z')){
    if(str[i]==' '){
      count++;
    }
  }
  }
  return ++count;
}


int uniqueWords (string str){
  string word = "";
  string otherword = "";
  int check = 0;
  int space = 0;
  int a = 0;
  int b = 0;
  string foo[countWords(str)];
  string nodupes[countWords(str)];
  for(int i = 0; i < str.length(); i++){
    
   if(str[i] == 32){
      space = i;
      word = str.substr(a,space-a);
      foo[b] = word;
      a = ++i;
      b++;
    }
  }
  for(int i = 0;i<sizeof(foo)/sizeof(foo)[0];i++){
    nodupes[i]=foo[i];
  }

  for(int i = 0;i<sizeof(foo)/sizeof(foo)[0];i++){
    for(int j = i;j<sizeof(nodupes)/sizeof(nodupes)[0];j++){
    if(foo[i]==nodupes[j+1]){
    check++;
      }
    }
  check--;
  }
int count = countWords(str);
   for(int i = 0;i<str.length();i++){
    if((str[i+1]>='a' && str[i+1]<='z') || (str[i+1]>='A' && str[i+1]<='Z')){
    if(str[i]==' '){
      count--;
    }
  } //subtract numbers
     }
  check-=count;
  return sizeof(foo)/sizeof(foo)[0] + check-1; //subtract 1 for the last word which will never be counted
  }
double lexdense(string str){
  double d = (uniqueWords(str)+0.0)/(countWords(str)+0.0);
  d = ceil(d * 100.0);
  return d;
}

int main()
{


	//. . .;

   string source = ("I was born in Lousiana down on the ol bayou raised on shrimps and catfish mamas good gumbo. I got the ramblin fever. Said goodbye to ma and pa. Crossed that ol red river and this is what I saw. I saw miles and miles of Texas 1000 stars up in the sky. I saw miles and miles of Texas gonna live here till I die.");


	cout << "substring count: " << countSubstring(source, "is")        << '\n';
  cout<< "word count: " << countWords(source)<<"\n";
  cout <<"Unique word count: "<<uniqueWords(source)<<"\n";
  cout<<"Lexical density: "<<lexdense(source)<<+"%\n";

//	. . .;
  


	return 0;
}
