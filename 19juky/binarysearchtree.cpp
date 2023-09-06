#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node * right;
    Node* left;
    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
void levelordertranasversal(Node *root){
    queue<Node*>q;
     
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        Node*temp= q.front();
        q.pop();
        

        if(temp==NULL)  {
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            
            if(temp->left){
            q.push(temp->left);
            }
            
           if(temp->right){
            q.push(temp->right);
           }

        }
    }

}
void inordertransversal(Node* root){
    // LNR
    Node* temp = root;
    // basecase
    if(temp==NULL){
        return;
    }
    inordertransversal(temp->left);
    cout<<temp->data<<" ";
    inordertransversal(temp->right);

}
Node *insertintoBST(Node* &root , int d){
// basecase
if(root==NULL){
    root = new Node(d); 
    return root;
}
    if(d>root->data){
     root->right = insertintoBST(root->right,d);
    }
    else if(d<root->data){
        root->left  = insertintoBST(root->left , d);
    }

    return root;
}
void takeInput(Node* &root){
    int d;
    cin>>d;
    while(d!=-1){
        Node*ans= insertintoBST(root,d);
        cin>>d;
    }
    
}
void preOrderTransversal(Node* root){
    // NLR
    Node* temp = root;
    // basecase
    if(temp==NULL){
        return;
    }
    cout<<temp->data<<" ";
    preOrderTransversal(temp->left);
    preOrderTransversal(temp->right);

}
void postOrderTransversal(Node* root){
    // LRN
    Node* temp = root;
    // basecase
    if(temp==NULL){
        return;
    }
    
    postOrderTransversal(temp->left);
    postOrderTransversal(temp->right);
    cout<<temp->data<<" ";

}
Node* minvalue(Node*root){
    Node* temp = root;
   
    while(temp->left!=NULL){
        temp = temp->left;
    }
  
    return temp;

}
Node* maxvalue(Node*root){
    Node* temp = root;
   
    while(temp->right!=NULL){
        temp = temp->right;
    }
  
    return temp;

}
Node* deletefromBST(Node* root , int value){
    if(root==NULL){
        return root;
    }
    else if (root->data==value){
        // 0 child
        if(root->left==NULL&&root->right==NULL){
            delete root;
            return NULL;
        }
        // 1 child
        else if(root->left!=NULL&&root->right==NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else if(root->left==NULL&&root->right!=NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        
        // 2 child
        else{
            int mini = minvalue(root->right)->data;
            root->data = mini;
            root->right = deletefromBST(root->right , mini);
        }

    }
    else if(root->data>value){
        root->left = deletefromBST(root->left , value);
    }
    else{
        root->right = deletefromBST(root->right , value);
    }
}
int main(){
    Node* root=NULL;
    cout<<"Enter data to take input in BST"<<endl;
    takeInput(root);
    cout<<"Printing level order transversal"<<endl;
    levelordertranasversal(root);
    cout<<endl;
    inordertransversal(root);
     cout<<endl;
    preOrderTransversal(root);
    cout<<endl;
    postOrderTransversal(root);
     cout<<endl;
    cout<<"Printing minimum data"<<endl;
    Node* ans = minvalue(root);
    cout<<ans->data<<endl;
    cout<<"Printing maximum data"<<endl;
    Node* ans2 = maxvalue(root);
    cout<<ans2->data<<endl;
    root = deletefromBST(root,20);
    cout<<"Printing data after deletion "<<endl;
    cout<<"Printing level order transversal"<<endl;
    levelordertranasversal(root);
    cout<<endl;
    inordertransversal(root);
     cout<<endl;
    preOrderTransversal(root);
    cout<<endl;
    postOrderTransversal(root);
     cout<<endl;
    cout<<"Printing minimum data"<<endl;
    

  
    return 0;
}