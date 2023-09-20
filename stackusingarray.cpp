#include<iostream>
using namespace std;
#define MAXSIZE  1000;
class stack{
    private:
    int arr [40000];
    int top;
    public:
    stack(){
        top = -1;

    }
    void push(int data);
    void pop();
    void traverse();

};
void stack::pop(){
    if(top==-1){
        cout<<"Your stack is empty"<<endl;
        return;
    }
   
    cout<<"Popped element is-> "<<arr[top--]<<endl;

}
void stack::push(int data){
    if(top==4000-1){
        cout<<"Stack overflow"<<endl;

    }
    top++;
    arr[top] = data;

}
void stack::traverse(){{

}}

int main(){
    return 0;
}
   
