#include <iostream>
using namespace std;
class Trienode{
    public:
    char data;
    Trienode* childnode[26];
    bool isTerminal;

    Trienode(char ch){
        data = ch;
        for(int i = 0 ; i<26 ; i++){
            childnode[i] = NULL;

        }
        isTerminal = false;
    }


};
class trie{
    public:
    Trienode* root;
    trie(){
       root = new Trienode('\0');
    }
    void insertutil(string word , Trienode* root){
        // base case
        if(word.length()==0){
            root->isTerminal = true;
            return;
        }
        int index = word[0]-'A';
        // assumption word is in CAPS
        // created a variable trienode child so that we can att it into root->children[index] directly
        Trienode* child ;

        // if childnode of trienode is present
        if(root->childnode[index]!=NULL){
            child = root->childnode[index];
        }
        else{
            child  = new Trienode(word[0]);
            root->childnode[index] = child;
            
        }
        // recursion
        insertutil(word.substr(1) , child);

    }
    void insertword(string word){
        insertutil(word,root);
    }
    bool searchWord(string word ){
    return searchutil( root ,word);
}
    bool searchutil(Trienode * root , string word){
    // basecase
    if(word.length()==0){
    return root->isTerminal;
    }
    int index = word[0] -'A';
    Trienode* child;

    if(root->childnode[index] !=NULL){
        child = root->childnode[index];

    }
    else{
        return false;
        
    }
    return searchutil(child , word.substr(1));  




    }
void removeutil(Trienode* root , string word){
    // base case
    if(word.length()==0){
        root->isTerminal  = false;
    }

    Trienode* child;
    int index = word[0] - 'A';

    if(root->childnode[index]!=NULL){
        child = root->childnode[index];
    }
    else{
        return;
    }
    removeutil(child,word.substr(1));

}
//remove word from trie
void removeword(string word){
    removeutil(root,word);
}


};



int main(){
    cout<<"HII"<<endl;
    
   trie * t = new trie ();
   
   t->insertword("PARAS");
   

   cout<<"Present or Not "<<t->searchWord("PARAS")<<endl;
   t->removeword("PARAS");
   cout<<"Present or Not "<<t->searchWord("PARAS")<<endl;

   return 0;
   
}