#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;

int main(){
   vector <pair<pair<int,int>,string>> p1;
    p1.push_back(make_pair(make_pair(3,2),"a"));
    // p1.first.first=4;
    // p1.first.second=5;
    // p1.second="15";
    cout<<p1[0].first.first<<endl;
    cout<<p1[0].first.second<<endl;
    cout<<p1[0].second<<endl;
    cout<<sizeof(string);
}