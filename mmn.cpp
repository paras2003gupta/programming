#include<iostream>
using namespace std;
 
int mini = 32767;
int maxi = -32768;

int main(){
    int arr[5] = {4,3,6,1,7};
    
    for(int i = 0; i<5;i++) {
        if(mini>arr[i])
        mini = arr[i];


        if(maxi <arr[i])
        maxi = arr[i];


    }
    cout<<mini<<endl;
    cout<<maxi<<endl;

    return 0;
}