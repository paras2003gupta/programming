#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    // next node address
    Node* next;
    // prev node address
    Node* prev;
   
   // constructor
   Node(int d ){
        this->data = d ;
        this->next  = NULL;
        this->prev = NULL;

   }
//    destructor
   ~Node(){
    int val = this->data;
    if(next !=NULL){
        delete next;
        next  = NULL;
    }
    cout<<"memory free for the node with data"<<val<<endl;
   }

   
};
// transversing a linked list

        void print(Node* &head){
        Node * temp = head;
         
        while(temp!=NULL){
            cout<<temp->data<<"  ";
            temp = temp->next;
            }
            cout<<endl;
            
        }

        void insertatstart (Node*&tail,Node*&head , int d){
            // empty list
                if(head == NULL){
                    Node* temp  = new Node(d);
                    head = temp; 
                    tail = temp;   
                }
                else{
                Node*  temp = new Node(d);
                

                temp->next = head ;
                head->prev = temp;
                
                head = temp;
                }
        }
        void insertattail(Node* &tail ,Node*&head,int d){
            if(tail==NULL){
                Node * temp = new Node(d);
                tail = temp;
                head = temp;
            }
            else{
            Node * temp = new Node(d);
            tail->next = temp;
            temp-> prev = tail;
            tail = temp;
            }


        }
        void insertmiddle(Node*&tail,Node*&head,int position , int d){

            if(position ==1){
                insertatstart(tail,head,d);
            }
            else{
                            // creating node
            Node * middleinsert= new Node (d);
            int cnt = 1;

            Node* temp = head;
            while(cnt<position-1){
             temp = temp->next;   
             cnt++;
            }
            if(temp->next ==NULL){
                
                insertattail(tail,head,d);
            }
            else{
            middleinsert->next = temp->next;
            temp->next->prev = middleinsert;
            temp->next  = middleinsert; 
            middleinsert->prev = temp; 
            }

        
        }
        }
        int getlength(Node*&head){
            Node* temp = head;
            int  cnt = 0;
            while(temp!=NULL){
                cnt++;
                temp = temp->next;
            }
            return cnt;
        }      
        void deleteNode(int position, Node* & head) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp ->next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr;

    }

            }
        
       
int main() {
    // Node* node1 = new Node(4);
    Node* head = NULL;
    Node* tail = NULL;
     
    print(head);
   
    insertatstart(tail,head , 0);
    print(head);
    insertattail(tail,head,23);
    print(head);
    insertattail(tail,head,53);
    print(head);
      
     
    insertmiddle(tail,head ,3, 12);
    print(head);
    insertmiddle(tail,head ,4, 22);
    print(head);
     insertmiddle(tail,head ,5, 36);
    print(head);
     insertmiddle(tail,head ,2, 53);
    print(head);
     insertmiddle(tail,head ,12, 3);
    print(head);
    deleteNode(3,head);
    print(head);
    cout<<"Length of DDL is ->"<<getlength(head)<<endl;
    return 0;
}
