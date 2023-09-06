#include <iostream>
using namespace std;
int getpivot(int arr[] , int n){
// n is size of array
    int s = 0;
    int e = n-1;
    int mid  = (s+e)/2;
    while(s<e){
        if(arr[0]<arr[mid]){
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid  = (s+e)/2;
    }
    return s;   w


}

int main(){
    int arr[6] = {5,6,1,2,3,4};
    cout<<"My pivot element is->"<<getpivot(arr,6)<<endl;
}