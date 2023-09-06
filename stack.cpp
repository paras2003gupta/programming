#include<iostream>
#include<stack>



using namespace std;
class Stack{
    // data members
    public:
    int top;
    int *arr;
    int size;
    // behaviour
    // constructor
    Stack(int size){
        this->size = size;
        arr  = new int[size]; 
        top = -1;
    }
    void push(int d){
        if(size-top>1){
            top++;
            arr[top] = d;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }
    int peek(){
        if(top>=0){  
         int k = arr[top];
        return k;
        }
        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }
     
    }
    bool isempty(){
        if(top>=0){
            return true;
        }
        else{
            return false;
        }
    }
    


};
    
int main() {
    Stack st(5);
    st.push(4);
    st.push(11);
    st.push(9);
    st.push(3);
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    



    // // creation of stack
    // stack<int>s;
    // // pushing elements in stack
    // s.push(2);
    // s.push(3);
    // // removing top element
    // s.pop();
    // cout<<"Top element is "<<s.top()<<endl;
}