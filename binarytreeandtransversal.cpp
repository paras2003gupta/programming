#include <iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        this->data = d;
        this->right = NULL;
        this->left = NULL;
    }
};
node* buildtree(node* root){
    cout<<"Enter the data:"<<endl;
    int data;
    cin>>data;
    root  = new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data for inserting in left of "<<data <<endl;
    root->left = buildtree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right = buildtree(root->right);

}
void levelordertranasversal(node *root){
    queue<node*>q;
     
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node*temp= q.front();
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
void inordertransversal(node* root){
    // LNR
    node* temp = root;
    // basecase
    if(temp==NULL){
        return;
    }
    inordertransversal(temp->left);
    cout<<temp->data<<" ";
    inordertransversal(temp->right);

}
void preOrderTransversal(node* root){
    // NLR
    node* temp = root;
    // basecase
    if(temp==NULL){
        return;
    }
    cout<<temp->data<<" ";
    preOrderTransversal(temp->left);
    preOrderTransversal(temp->right);

}
void postOrderTransversal(node* root){
    // LRN
    node* temp = root;
    // basecase
    if(temp==NULL){
        return;
    }
    
    postOrderTransversal(temp->left);
    postOrderTransversal(temp->right);
    cout<<temp->data<<" ";

}

int main(){
node* root = NULL;
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 

root = buildtree(root);
cout<<"printing level order transversal"<<endl;
levelordertranasversal(root);
cout<<endl;
cout<<"printing inorder transversal"<<endl;
inordertransversal(root);
cout<<endl;
cout<<"printing pre order level transversal"<<endl;
preOrderTransversal(root);
cout<<endl;
cout<<"printing post order level transversal"<<endl;
postOrderTransversal(root);
cout<<endl;
return 0;
}