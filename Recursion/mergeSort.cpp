#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &v,int n){
    for(int i=0;i<n;i++){
        cout<<v[i]<<" .";
    }
    cout<<endl;
}
void merge(vector<int> &v1,int start,int end){
    int mid = (start+end)/2;
    int len1 = mid-start+1;
    int len2 = end-mid;

    vector<int> first;
    vector<int> second;
    // int *first=new int[len1];
    // int *second=new int[len2];
    print(v1,v1.size());

    int mainindex=start;
    for(int i=0 ; i<len1;i++){
        first.push_back(v1[mainindex++]);
    }
    mainindex=mid+1;
    for(int i=0 ; i<len2;i++){
        second.push_back(v1[mainindex++]);
    }
    int index1=0;
    int index2=0;
    mainindex=start;
    while(index1 <len1 && index2<len2){
        if(first[index1]<second[index2]){
            v1[mainindex++] = first[index1++];
        }else{
            v1[mainindex++] = second[index2++];
        }
    }
    while(index1 <len1){
        v1[mainindex++] = first[index1++];
    }
    while(index2 <len2){
        v1[mainindex++] = second[index2++];
    }
    first.clear();
    second.clear();

}

void mergeSort(vector<int> &v1,int start,int end){
    // print(v1,end+1);
    if(start>=end){
        return;
    }
    int mid=(start+end)/2;
    mergeSort(v1,start,mid);
    mergeSort(v1,mid+1,end);
    merge(v1,start,end);
}

int main(){
    vector <int> v1{2,7,4,3,9,100,50,57,37};
    // int n=sizeof(v1)/sizeof(int);
    mergeSort(v1,0,v1.size()-1);
    print(v1,v1.size());
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;

// void print(int *v,int n){
//     for(int i=0;i<n;i++){
//         cout<<v[i]<<" .";
//     }
//     cout<<endl;
// }
// void merge(int *v1,int start,int end){
//     int mid = (start+end)/2;
//     int len1 = mid-start+1;
//     int len2 = end-mid;

//     int *first=new int[len1];
//     int *second=new int[len2];

//     int mainindex=start;
//     for(int i=0 ; i<len1;i++){
//         first[i]=v1[mainindex++];
//     }
//     mainindex=mid+1;
//     for(int i=0 ; i<len2;i++){
//         second[i]=v1[mainindex++];
//     }
//     int index1=0;
//     int index2=0;
//     mainindex=start;
//     while(index1 <len1 && index2<len2){
//         if(first[index1]<second[index2]){
//             v1[mainindex++] = first[index1++];
//         }else{
//             v1[mainindex++] = second[index2++];
//         }
//     }
//     while(index1 <len1){
//         v1[mainindex++] = first[index1++];
//     }
//     while(index2 <len2){
//         v1[mainindex++] = second[index2++];
//     }

// }

// void mergeSort(int *v1,int start,int end){
//     // print(v1,end+1);
//     if(start>=end){
//         return;
//     }
//     int mid=(start+end)/2;
//     mergeSort(v1,start,mid);
//     mergeSort(v1,mid+1,end);
//     merge(v1,start,end);
// }

// int main(){
//     int v1[]={2,7,4,3,9,100,50,57,37};
//     int n=sizeof(v1)/sizeof(int);
//     mergeSort(v1,0,n-1);
//     print(v1,n);
//     return 0;
// }