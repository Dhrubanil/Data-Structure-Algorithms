#include<bits/stdc++.h>
using namespace std;

int findUnique(int *arr,int n){
    int ans=0; 
    for (int i = 0; i < n; i++)
    {
    ans=ans^arr[i];
    cout<<ans<<" ";
        /* code */
    }
    return ans;
}

int main(){
int *arr=new int[0];
int n;
cin>>n;
for (int i = 0; i < n; i++)
{
    cin>>arr[i];
    /* code */
}

int a=findUnique(arr,n);
}