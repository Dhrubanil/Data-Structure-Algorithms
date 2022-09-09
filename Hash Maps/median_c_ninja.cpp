#include <bits/stdc++.h>
using namespace std;

int findMedian(vector<vector<int>> &arr, int n, int m){
    int min=INT_MAX;
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i][0]<min){
            min=arr[i][0];
        }
        if(arr[i][m-1]>max){
            max=arr[i][m-1];
        }
    }
    int desired = (n * m + 1) / 2;
    while (min < max)
    {
        int mid = min + (max - min) / 2;
        int place = 0;
 
        // Find count of elements smaller than or equal to mid
        for (int i = 0; i < n; ++i){
            place+=upper_bound(arr[i].begin(), arr[i].end(), mid)-arr[i].begin();
        }
        if (place < desired)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}

int main(){
    vector<vector<int>>v{{1,3,5},{2,6,8},{3,6,9}};
   int mid = 5;
   int c= 3;
//    cout<< ans<<endl;
    // 1 3 5 
    // 2 6 9
    // 3 6 9
    int res = findMedian(v,3,3);
    cout<<"result is--->"<<res<<endl;

}