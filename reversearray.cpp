#include<iostream>
using namespace std;
void reverse(int arr[],int size){
    int s= 0, e=size-1;
    while(s<=e){
        swap(arr[s++],arr[e--]);
    }
}
 

int main(){
    int arr[5] = {1,4,7,3,2};
    int size = 5;
    reverse (arr,5);
    for(int i = 0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
  
    




    return 0;
}