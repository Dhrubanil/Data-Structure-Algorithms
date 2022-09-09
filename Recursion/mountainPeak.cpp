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

int mountainPeak(vector<int> v,int start,int end){
    int mid = (start+end)/2;
    if(v[mid]>v[mid-1] && v[mid]>v[mid+1]){
        return mid;
    }
    if(v[mid]>v[mid+1]){
        return mountainPeak(v,start,mid-1);
    }else{
        return mountainPeak(v,mid+1,end);
    }
    return -1;
}

int main(){
    vector<int> v{24,69,100,99,79,78,67,36,26,19};
    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     int val;
    //     cin>>val;
    //     v.push_back(val);
    // }
    cout<<mountainPeak(v,0,v.size()-1);
}