#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int kthSmallest(int arr[] , int l, int r, int k)
    {
      
      sort(arr,arr+r+1);
        return arr[k-1];
    }

int main() {
    int arr[6] = {7,10,4,3,20,15};
    int l = 0;
    int r = 5;
    int k = 3;
    cout<<kthSmallest(arr,l,r,k)<<endl;

}