#include<iostream>
using namespace std;
class Node{
    public:
     int data;
    Node*next ;
    // constructor
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
    // destructor

    ~Node(){
        int value = this->data;
        if(this->next != NULL){
                delete next;
                next = NULL;
        }
        cout<<"Memory is free for node with data"<<value<<endl;
    }
    

};
void insertatposition(Node * &tail,int element,int d){
// assuming that  the element is present
// empty list
if(tail == NULL){
    // creating node
    Node* temp = new Node(d);
    tail = temp;
    temp->next = temp;
}
// Non-empty list
else{
    // creating node
    
  
    Node* temp = tail;
      while(temp->data!=element){
        temp = temp->next;
    }
    // element found and temp is repersenting the current element
    Node* toinsert = new Node(d);
    toinsert->next = temp->next;
    temp->next =toinsert;
} 
}
void print(Node*&tail){
    Node*temp = tail;
   do{
    cout<<tail->data<<" ";
    tail = tail->next;
   }
   while(tail!=temp);
   cout<<endl;
}
void deletenode(Node*&tail , int element){
    // the list is empty
    if(tail ==NULL){
        cout<<"The list is empty"<<endl;
        return;
    }
    else{
       Node*curr = tail->next;
       Node*prev = tail;

       while(curr->data!= element){
        prev=curr;
        curr = curr->next ;  
       }
    //    now we have two node current one which have to be deleted and previous one which points towards next of current
        prev->next = curr->next;
        if(tail == curr){
            tail = prev;
        }
        curr->next  = NULL;
        delete curr;
    }
}


int main() {
    
   Node* tail = NULL;
   insertatposition(tail,4,3);
   print(tail);
   insertatposition(tail,3,5);
   print(tail);
   insertatposition(tail,5,6);
   print(tail);
    insertatposition(tail,6,7);
   print(tail);
 insertatposition(tail,7,8);
   print(tail);
 insertatposition(tail,8,9);
   print(tail);
   deletenode(tail,7);
   print(tail);
   deletenode(tail,3);
   print(tail);



    return   0;
}