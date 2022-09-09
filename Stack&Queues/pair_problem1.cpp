#include<bits/stdc++.h>
using namespace std;
/* Inserts a pair  <string,   pair<x, y> > >    into the vector A */
void add_pair(vector<pair<string,pair<int,int> > > &A, string str, int x, int y)
{
    A.push_back(make_pair(str,make_pair(x,y)));
     // Your code here
}

/* Returns the size of the vector A */
int get_size(vector<pair<string,pair<int,int> > > &A)
{
    return A.size();
     // Your code here
}

/* Prints space separated values of vector A */
bool sortComparator(pair<string,pair<int,int > > &v1,pair<string,pair<int,int > > &v2){
    if(v1.second.first  == v2.second.first){
        return v1.second.second<v2.second.second;
    }
    return (v1.second.first<v2.second.first);
}
void print_values(vector<pair<string,pair<int,int> > > &A)
{
     // Your code here
     for(int i=0 ; i<A.size() ; i++){
         cout<<A[i].first<<" " << A[i].second.first<<" "<<A[i].second.second<<" ";
     }
}

/* Sorts the vector A based on value x and y*/
void sort_pair(vector<pair<string,pair<int,int> > > &A)
{
     // Your code here
     sort(A.begin(),A.end(),sortComparator);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        vector < pair< string, pair < int,int > > > A;
        int q;
        cin>>q;
        while(q--){
            char c;
            cin>>c;
            if(c=='a'){
                string name;
                cin>>name;
                int x,y;
                cin>>x>>y;
                add_pair(A,name,x,y);
            }
            if(c== 'b'){
                cout<<get_size(A)<<" ";
            }
            if(c== 'c'){
                print_values(A);
            }
            if(c== 'd'){
                sort_pair(A);
            }
        }
    }
}