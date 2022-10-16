#include <bits/stdc++.h>
using namespace std;


//Top Down Approach
int fibonacci(int n,vector<int> &dpArray){
    // Base Case
    if(n==0 || n==1) {
        return n;
    }

    // Step3 Memorization
    if(dpArray[n]!= -1){
        return dpArray[n];
    }

    // step2 not presesent in dp array
    dpArray[n] = fibonacci(n-1,dpArray)+fibonacci(n-2,dpArray);
    return dpArray[n];
}

// Bottom-Up Approach
int fibonacciBU(int n,vector<int> &dpArray){
    // Base Case

    // Step 2
    dpArray[0]=0;
    dpArray[1]=1;

    // Step3 
    for(int i=2;i<=n;i++){
        dpArray[i] = dpArray[i-1]+dpArray[i-2];
    }

    return dpArray[n];
    

    // step2 not presesent in dp array
    
}

int fibonacciSpaceOptimisation(int n){
    
    int prev1 = 1;
    int prev2 = 0;

    if(n==1 || n==0){
        return n;
    }

    for(int i=2;i<=n;i++){
        int cur = prev1+prev2;
        prev2=prev1;
        prev1= cur;
    }

    return prev1;

}

int main(){
    int n;
    cin>>n;
    vector<int> dpArray(n+1,-1);

    cout<<fibonacciBU(n,dpArray)<<endl;
    // cout<<fibonacciSpaceOptimisation(n)<<endl;
}