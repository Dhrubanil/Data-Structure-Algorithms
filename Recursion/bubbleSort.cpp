#include<bits/stdc++.h>
using namespace std;

void bubbleSortUsingRecursion(vector<int> &arr){
    if(arr.size()==0 || arr.size()==1){
        return;
    }
    bool alrSorted=true;

    for(int i=0;i<arr.size()-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
            alrSorted = false;
        }
    }
    if(alrSorted){
        return;
    }else{
    bubbleSortUsingRecursion(arr);
    }
}
void bubbleSortUsingLoop(vector<int> &arr){
    for(int i=0;i<arr.size()-1;i++){
        bool alrSorted=true;
        for(int j=0;j<arr.size()-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                alrSorted = false;
            }
        }
        if(alrSorted){
            break;
        }
    }
}

int main(){
   vector<int> arr{5,2,4,7,4,8,6};
    bubbleSortUsingRecursion(arr);
    // bubbleSortUsingLoop(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<endl;
    }
}