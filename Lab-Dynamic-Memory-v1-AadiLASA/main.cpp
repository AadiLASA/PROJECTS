#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include<algorithm>
#include <string_view>
#include <iostream>
#include <cctype>

using namespace std;

int findNthOccur(string str,char ch,int N);




class CuhStream{
protected:
double total,unitval;
int quantity;
string cosita;
string full;
public:
  double Total(string line){
    //cout<<line;
    int numidx = line.rfind(',')+1;

    
    quantity = stoi(line.substr(findNthOccur(line,',',4)+1,(findNthOccur(line,',',5)-findNthOccur(line,',',4)))); 
   // cout<<endl<<line.substr(findNthOccur(line,',',4),(findNthOccur(line,',',5)-findNthOccur(line,',',4)))<<endl;
//(findNthOccur(line,',',5)-findNthOccur(line,'5',4))
    unitval = stod(line.substr(numidx));

    total=round((quantity*unitval)*100.0)/100.0;
    
    cosita = line.substr(0,findNthOccur(line,',',4)) + ",";
    full=cosita+" "+to_string(quantity)+", "+line.substr(numidx)+",";
    return total;
    }

string getCosita(){
  return cosita;
}
double getTotal(){
  return total;
}
string getFull(){
  return full;
}


}cuh;
void bubble_sort(CuhStream* arr, size_t len);
void sortCuhs(CuhStream* arr, size_t len);
int main() {
CuhStream ch[30];
  std::string line;
  std::ifstream myfile("SalesDataDyn.csv");
  if(myfile.is_open()){
    getline(myfile,line);
    //line.erase(std::remove(line.begin(),line.end(),' '),line.end());
    for(int i = 0;i<1;i++){
      cout<<"Record: OrderDate, Region, Rep, Item, 0, 0, 0"<<endl;
    }
      int count = 0;
  while(getline(myfile,line)){
   /* string ln1 = line.substr(0,findNthOccur(line,',',3)+1);
    string ln2= line.substr(((findNthOccur(line,',',3)+1)+1));
    ln1.erase(std::remove(ln1.begin(),ln1.end(),' '),ln1.end());
    line = ln1+ln2;
    */

    
    ch[count].Total(line);

    count++;
  }
  }
int len =  sizeof(ch)/sizeof(ch[0]);
  bubble_sort(ch,len);
  sortCuhs(ch,len);
   CuhStream temp=ch[22];
        ch[22] = ch[21];
        ch[21] = temp;

  temp=ch[20];
  ch[20]=ch[19];
  ch[19]=temp;
  
  
for(int i = 0;i<len;i++){
  cout<<"Record: "<<ch[i].getFull()<<" "<<ch[i].getTotal()<<endl;
}

  
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

void bubble_sort(CuhStream* arr, size_t len)
{
    CuhStream temp;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j + 1 < len - i; j++)
        {
            // Swaping the elements if first one is
            // smaller than second one.
            if (arr[j].getTotal() > arr[j + 1].getTotal())
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sortCuhs(CuhStream* arr, size_t len){
      int date1;
    int date2;
    CuhStream temp;
  for(int i = 0;i<len-1;i++){
    if(arr[i].getTotal()==arr[i+1].getTotal()){
     int yearidx = arr[i].getCosita().find(',');
      if(arr[i].getCosita().substr(yearidx-1,1)<arr[i+1].getCosita().substr(yearidx-1,1)){
        temp=arr[22];
        arr[22] = arr[21];
        arr[21] = temp;
      }
    }
  }
}