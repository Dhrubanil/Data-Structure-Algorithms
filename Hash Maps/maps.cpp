#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    string sen = "My name is Dhrubanil Sikdar Dhrubanil Sikdar Dhrubanil";
    map<string,int> m;
    // unordered_map<string,int> m;

    //Insertion

    pair<string,int> p1 = make_pair("Dhruba",0);
    m.insert(p1);
    pair<string,int>p2("Dhrubanil",3);
    m.insert(p2);
    m["Sikdar"]=1;

    // Search
    cout<<m.at("Sikdar")<<endl;

    // Size
    cout<<m.size()<<endl;

    // To Check Presence
    cout<<m.count("Dhrubanil")<<endl;

    // Erase
    m.erase("Dhruba");

    // Iterator
    map<string,int> :: iterator it = m.begin();
    // unordered_map<string,int> :: iterator it = m.begin();
    while(it!=m.end()){
        cout<<it->first<<" "<<it->second<<" "<<endl;
        it++;
    }

}