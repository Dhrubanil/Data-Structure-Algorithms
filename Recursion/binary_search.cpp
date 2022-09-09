#include<bits/stdc++.h>
using namespace std;

int binarySearchusingWhile(vector<int> v,int e){
    int start=0;
    int end=v.size() - 1;
    int mid=v.size()-1;
    while(start<=end){
        mid=(start+end)/2;
        if(v[mid]== e){
            return mid;
        }
        if(v[mid] < e){
            start=mid+1;
        }
        if(v[mid]>e){
            end=mid-1;
        }
    }
    return -1;  
}
int binarySearchusingRecursion(vector<int> v,int e , int start ,int end){
    int mid= (start+end)/2 ;
    if(start>end){
        return -1;
    };
    if(v[mid] == e){
        return mid;
    };
    if(v[mid] < e){
        return binarySearchusingRecursion(v, e, mid + 1, end);
    }else{
        return binarySearchusingRecursion(v, e, start, mid-1);
    };
    return 0;
}

int main(){
    vector<int> v{3,5,7,8,19};
    int n;
    cin>> n;
    // cout<<binarySearchusingWhile(v,n)<<endl;
    cout<<"g->"<<binarySearchusingRecursion(v,n,0,v.size() - 1)<<endl;
}