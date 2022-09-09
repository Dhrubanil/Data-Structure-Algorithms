#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" .";
    }
    cout<<endl;
}
int partition(vector<int> &v,int start,int end){
    int pivot = v[start];
    int count = 0;
    for(int i=start+1;i<=end;i++){
        if(v[i]<=pivot){
            count++;
        }
    }

    // place pivot to the right place
    int pivotIndex = start+count;
    swap(v[start],v[pivotIndex]); //{1,5,3,8,2,4}
    int i=start;
    int j=end;
    while(i<pivotIndex && j>pivotIndex){
        while(v[i]< pivot){
            i++;
        }
        while(v[j]>pivot){
            j--;
        }
        if(i< pivotIndex && j > pivotIndex){
            swap(v[i],v[j]);
            i++;
            j--;
        }
    }
    return pivotIndex;
}
void quickSort(vector<int> &v,int start,int end){
    if(start>=end){
        return;
    }
    int partitionIndex = partition(v,start,end);
    quickSort(v,start,partitionIndex-1);
    quickSort(v,partitionIndex+1,end);
}

int main(){
    vector<int> v{3,5,1,8,2,4};
    quickSort(v,0,v.size()-1);
    print(v);
}