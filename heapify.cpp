#include<iostream>
using namespace std;
// this function is based on 1 based indexing

void heapify(int arr[] , int n , int i ){
    
    
    int largest = i;
    int left = 2*i;
    int right  = 2*i+1;
    // equality ka sign is lie aaya hai because hm 1 based indexing use kar rhe hai
    
        if(left<=n&&arr[left]>arr[largest]){
            
            largest = left;
        }
        if(right<=n&&arr[right]>arr[largest]){
           
            largest = right;
        }
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }



    
}

int main(){
int arr[4] = {-1,45,50,55};
int n = 3;
for(int i = n/2 ; i>0 ; i--){
heapify(arr,n,i);
}
cout<<"Printing the array "<<endl;
for(int i = 1; i<=n ; i++){
cout<<arr[i]<<" ";
}cout<<endl;


    return 0;
}