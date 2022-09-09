#include<iostream>
using namespace std;

void swap(string &a,string &b){
    string temp=a;
    a=b;
    b=a;
}
void reverseString(string &name,int start,int end){
    if(start>end){
        return;
    }
    swap(name[start],name[end]);
    reverseString(name,++start,--end);
}

int main(){
    string name ="dhrubanil sikdar" ;
    reverseString(name,0,name.length()-1);
    cout<<name<<endl;
}