#include<bits/stdc++.h>
using namespace std;

int firstOcc(int arr[],int start,int end,int key){
    int mid = (start+end)/2;
    int ans=-1;
    int i=1;
    if(arr[mid]==key && arr[mid-1] != key){
        return mid;
    }
    if(arr[mid]==key && arr[mid-1] == key){
        return firstOcc(arr,start,mid-1,key);
    }
    if(arr[mid] < key){
        return firstOcc(arr,mid+1,end,key);
    }
    if(arr[mid] > key){
        return firstOcc(arr,start,mid-1,key);
    }
    return -1;
};
int lastOcc(int arr[],int start,int end,int key){
    int mid = (start+end)/2;
    int ans=-1;
    int i=1;
    if(arr[mid]==key && arr[mid+1] != key){
        return mid;
    }
    if(arr[mid]==key && arr[mid+1] == key){
        return lastOcc(arr,mid+1,end,key);
    }
    if(arr[mid] < key){
        return lastOcc(arr,mid+1,end,key);
    }
    if(arr[mid] > key){
        return lastOcc(arr,start,mid-1,key);
    }
    return -1;
};

pair <int,int> firstLastOcc(int arr[],int start,int end,int key){
    pair<int,int> p;
    p.first=firstOcc(arr,start,end,key);
    p.second=lastOcc(arr,start,end,key);
    return p;
}

int main(){
    // int n;
    // cin>>n;
    int arr[11]= {1,2,3,3,3,3,3,3,4,5,6};
    // cout<<a<<b<<endl;
    // for(int i=0;i<n;i++){
    // cin>>arr[i];
    // }
    // cout<<firstOcc(arr,0,10,3)<<endl;
    // cout<<lastOcc(arr,0,10,3)<<endl;
    cout<<firstLastOcc(arr,0,10,3).first<<"->" << firstLastOcc(arr,0,10,3).second <<endl;
}