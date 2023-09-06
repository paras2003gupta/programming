#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int>pq;
    priority_queue<int,vector<int>,greater<int>>minheap;
    minheap.push(3);
    minheap.push(6);
    minheap.push(1);
    minheap.push(0);
    minheap.push(5);
    minheap.push(7);
    minheap.push(35);
    minheap.push(2);
    pq.push(5);
    pq.push(1);
    pq.push(2);
    pq.push(9);
    pq.push(6);
    pq.push(0);
    cout<<pq.top()<<endl;
    pq.pop();
     cout<<pq.top()<<endl;
    cout<< minheap.top()<<endl;
    while(!minheap.empty()){
        cout<<minheap.top()<<" ";
        minheap.pop();
    }cout<<endl;


    return 0;
}