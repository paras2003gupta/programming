#include<bits/stdc++.h>
using namespace std;
int fib(int n , vector<int>& dp){
        // base case
        if(n<=1){
                return n;
        }
        // step 3: check if someting is present in dp to prevent numerous calls
        if(dp[n]!=-1){
                return dp[n];
        }
        // step 2: store answer in dp and return it
        dp[n] = fib(n-1,dp)+fib(n-2,dp);
        return dp[n];


}

int main()
{       
        cout<<"Enter your fibonacci n"<<endl;
       int n;
       cin>>n;

//        step:1 create dp
        vector<int>dp(n+1,-1);
       
        int k = fib(n,dp);
        cout<<k<<endl;
        
}