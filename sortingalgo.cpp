#include<iostream>
using namespace std;
void selectionsort(int arr[],int n){
    
    for(int i =0; i<n-1 ; i++){
        int minindex = i;
        for(int j= i+1 ; j<n;j++){
            if(arr[minindex]>arr[j]){
                minindex = j;
            }
        }
        swap(arr[i],arr[minindex]);
    }
}
void mergesort(int arr[],int n){

}
void insertionsort(int arr[],int n){
    
}
void bubblesort(int arr[],int n){
    for(int i =1 ; i< n ; i++){


        for(int j = 0 ; j< n-i ; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }

    }
}


int main(){
    int arr[8] = {8,7,6,5,44,3,2,1};
    int n =8;
    bubblesort(arr,n);
    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}