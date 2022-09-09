#include<bits/stdc++.h>
using namespace std;

int getPartition(vector<int> &v,int start,int end){
    int pivot = v[start];
    int count =start;
    for(int i=start+1;i<=end;i++){
        if(v[i]<pivot){
            count++;
        }
    }

    swap(v[count],v[start]);

    while(start<count && end>count){
        if(v[start]>pivot){
            swap(v[start],v[end]);
            end--;
        }else{
            start++;
        }
    }
    return count;
}

void quickSort(vector<int> &v,int start,int end){
    while(start>=end){
        return;
    }
    int partition = getPartition(v,start,end);
    quickSort(v,start,partition-1);
    quickSort(v,partition+1,end);
}

int main(){
    vector<int> v{300,50,10,80,20,40,1,100};
    quickSort(v,0,v.size()-1);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" "<<endl;
    }
}