#include<bits/stdc++.h>
using namespace std;

void insertionSortUsingRecursion(vector<int> &arr,int start){
    if(arr.size()==start){
        return;
    }
    int temp=arr[start];
    for(int i =start-1;i>= 0;i--){
        
        if(temp<arr[i]){
            arr[i+1] = arr[i];
            arr[i] = temp;
        }else{
            break;
        }
    }
    insertionSortUsingRecursion(arr,start+1);
}
void insertionSortUsingLoop(vector<int> &arr){
    for(int i=1;i<arr.size();i++){
        int temp= arr[i];
        for(int j=i-1;j>=0;j--){
            if(temp<arr[j]){
                arr[j+1]=arr[j];
                arr[j]=temp;
            }else{
                break;
            }
        }
    }
}

int main(){
   vector<int> arr{5,2,4,7,4,8,6};
    insertionSortUsingRecursion(arr,1);
    // insertionSortUsingLoop(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<endl;
    }
}