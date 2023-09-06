#include<iostream>
using namespace std;
// heap ek aisa data structure hia jo ek complete binary tree
//  hai and vo
// aur vo max heap order aur min heap order satisfy krta hai
// maxheap order = root sei uske child chote hinge
// minheaporder  = root sei uske child bde honge
// YE JO HAM BNA RHE HAI YE EK ***MAX HEAP*** HAI........

class heap{
    public:
    int size;
    int arr[100];

    heap(){
        arr[0] = -1;
        this->size = 0;
    }
    void insert(int val){
        size = size+1;
        arr[size] = val;
        int index = size;
        while(index>1){
            int parent = index/2;
            if(arr[parent]<arr[index ]){
                swap(arr[parent] , arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }
// ye deletion from heap sei ka correct code hia love babbr nei galat kraya tha

    void deletefromHeap(){
        // Heap sei hmesa root node delete hoti hai
        if(size==0){
            cout<<"Heap is empty "<<endl;
            return;
        }
        arr[1] = arr[size];
        size--;
        int i =1;
       

        
        while(i<size){
        int leftChild = 2*i;
        int rightChild = 2*i +1;
        int j =i;
        if(leftChild<=size&&arr[leftChild]>arr[i]){
           
            i = leftChild;
        }
        else if(rightChild<=size&&arr[rightChild]>arr[i]){
           
            i = rightChild;
        }
        if(i!=j){
            swap(arr[i],arr[j]);
            i = j;

        }
        else{
            return;
        }
        }
    }
    void print(){
        for (int  i = 1; i <= size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        
    }
    

};


int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deletefromHeap();
    h.deletefromHeap();
    
    h.print();
    return 0;
   
}