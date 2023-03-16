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
double total,quantity,unitval;
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
    
    cosita = line.substr(0) + ",";
    full=cosita+to_string(total);
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
int main() {
CuhStream ch[30];
  std::string line;
  std::ifstream myfile("SalesDataPt2.csv");
  if(myfile.is_open()){
    getline(myfile,line);
    line.erase(std::remove(line.begin(),line.end(),' '),line.end());
    for(int i = 0;i<1;i++){
      cout<<line<<",Total"<<endl;
    }
      int count = 0;
  while(getline(myfile,line)){
    string ln1 = line.substr(0,findNthOccur(line,',',3)+1);
    string ln2= line.substr(((findNthOccur(line,',',3)+1)+1));
    ln1.erase(std::remove(ln1.begin(),ln1.end(),' '),ln1.end());
    line = ln1+ln2;

    
    ch[count].Total(line);

    count++;
  }
  }
int len =  sizeof(ch)/sizeof(ch[0]);
  bubble_sort(ch,len);
for(int i = 0;i<len;i++){
  cout<<ch[i].getCosita()<<ch[i].getTotal()<<endl;
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
            if (arr[j].getTotal() < arr[j + 1].getTotal())
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
