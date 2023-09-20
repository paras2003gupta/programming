#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    // distructor
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for value with data " << value << endl;
    }
};

void insertattail(Node *&tail, int d)
{
    // Creating new node
    Node *temp = new Node(d);

    tail->next = temp;
    tail = temp;
}
void printll(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}
void insertathead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
int nodelength(Node *&head)
{
    Node *temp = head;
    int cnt = 1;
    while (temp->next != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
void deleteposition(int position, Node *&head)
{
    // first node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;

        temp->next = NULL;

        delete temp;
    }
    // last node or middle node
    else
    {
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
Node *floydalgoloopcheck(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *fast = head;
    Node *slow = head;

    while (fast != NULL && slow != NULL)
    {
        fast = fast->next;
           if(fast->next!=NULL){
            fast = fast->next;
           }
           else{
            return NULL;
           }
        slow = slow->next;

        if (fast == slow)
        {
            cout << "Loop is present at data " << fast->data << endl;
            return fast;
        }
    }

    return NULL;
}
Node *loopstartposn(Node *head)
{
    Node *slow = head;
    Node *intersection = floydalgoloopcheck(head);
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}
void removeloop(Node *&head)
{
    if (head == NULL)
    {
        return;
    }

    Node *startofloop = loopstartposn(head);
    Node *temp = startofloop;

    while (temp->next != startofloop)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}
void insertatmiddle(Node *&head, int position, int d)
{

    if (position == 1)
    {
        insertathead(head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // creating a node for d
    Node *nodetoinsert = new Node(d);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}
Node *reverselinkedlist(Node *&head)
{
    // for empty list or list with one element
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    // list is not empty
    else
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *forward = NULL;

        while (curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
}
void reverselinkedlist2(Node *&head, Node *&curr, Node *&prev)
{
    // base case
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    // recursion
    Node *forward = curr->next;

    reverselinkedlist2(head, forward, curr);
    curr->next = prev;
}
Node *reverselinkedlist3(Node *&head)
{
    // base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *chotahead = reverselinkedlist3(head->next);
    head->next->next = head;
    head->next = NULL;
}
int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    Node *curr = head;
    Node *prev = NULL;
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    printll(head);
    insertattail(tail, 15);
    printll(head);
    insertattail(tail, 10);
    printll(head);
    insertattail(tail, 14);
    printll(head);
    insertattail(tail, 134);
    printll(head);
    insertatmiddle(head, 3, 45);
    printll(head);
    insertatmiddle(head, 1, 5);
    printll(head);

    // insertatmiddle(head ,8,987);
    // printll(head);
    //   deleteposition( 3,head );
    //   printll(head);
    cout << tail->data << endl;
    tail->next = head->next;
    if (floydalgoloopcheck(head) != NULL)
    {
        cout << "Loop is present" << endl;
    }
    else
    {
        cout << "Loop is not present" << endl;
    }

    Node *loop = loopstartposn(head);
    cout << "My loop starts from " << loop->data << endl;
    removeloop(head);
    printll(head);
    cout << tail->next << endl;
    cout << endl;
    cout << tail->next->next << endl;

    return 0;
}