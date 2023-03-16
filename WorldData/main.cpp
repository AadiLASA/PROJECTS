 //FINAL STEP : COMPLETE 

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int findNthOccur(string str,char ch, int N);
struct countryNums{
double nums;
string country;
};

void bubble_sort(countryNums* arr, size_t len)
{
    double temp;
  string temp2;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j + 1 < len - i; j++)
        {
            // Swaping the elements if first one is
            // smaller than second one.
            if (arr[j].nums < arr[j + 1].nums)
            {
                temp = arr[j].nums;
                arr[j].nums = arr[j + 1].nums;
                arr[j + 1].nums = temp;

               temp2 = arr[j].country;
                arr[j].country = arr[j + 1].country;
                arr[j + 1].country = temp2;
            }
        }
    }
}

int main(){
  string line;
  int count = 0;
  ifstream myfile("WPP2015_MORT_F07_1_LIFE_EXPECTANCY_0_BOTH_SEXES.csv");
  countryNums arr[227];
  countryNums testcounts[5]= {{73.75,"Europe"},{77.38, "Northern America",},{80,"Australia/New Zealand",},{81.83,"Japan",},{77.13,"United States of America"}};


  if(myfile.is_open()){
    for(int i = 0;i<31;i++){
      getline(myfile,line);
    }
    while(getline(myfile,line)){
     // cout<<line<<endl;
      int contidx = line.find("\"Estimates\"") + 13;
      int endcontidx = line.find("\"",contidx);      
      int contlen = endcontidx - contidx;      
       arr[count].country=line.substr(contidx,contlen);
     // cout<<arr[count].country<<endl;
      
     int numidx = findNthOccur(line,',',15)+1;
      int endnumidx = findNthOccur(line,',',16);
      int numlen = endnumidx-numidx;
      arr[count].nums= stod(line.substr(numidx,numlen));
      // cout<<arr[count].country<<"\t"<<arr[count].nums<<endl;
      
     
       count++;
    }   
  }
   int len = sizeof(arr)/sizeof(arr)[0];
  bubble_sort(arr,len);
  bubble_sort(testcounts,5);
  int goodplace;
  for(int i = 0;i<5;i++){
    if(testcounts[i].country=="United States of America"){
      goodplace = i+1;
    }
  }
  cout<<endl<<endl<<endl;

  int place;
  for(int i = 0;i<len;i++){
           cout<<arr[i].country<<"\t"<<arr[i].nums<<endl;
    if(arr[i].country=="United States of America"){
      place = i+1;
    }

  }

  
  cout<<endl<<endl<<"The United States places: "<<place<<"st overall.";
  cout<<endl<<endl<<"The United States places: "<<goodplace<<"th within the following countries: Europe, Northern America, Australia/New Zealand and Japan"; 
  }


int findNthOccur(string str,
                 char ch, int N)
{
    int occur = 0;
 
    // Loop to find the Nth
    // occurrence of the character
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ch) {
            occur += 1;
        }
        if (occur == N)
            return i;
    }
    return -1;
}
