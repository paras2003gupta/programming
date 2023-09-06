#include<iostream>
using namespace std;
int main() {
  class Node  {
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data ;
        this->next = NULL;
    }
  };
  Node* node1= new Node(8);
   




    
    return 0;
}