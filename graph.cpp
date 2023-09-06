#include<iostream>
#include<unordered_map>
#include<list>
// this code is for char type of map
// if we want to convert it into int type change typname at Line:46 and change input at Line 48
using namespace std;
// this was done to save time if we want to change it into char type of data than we can do that also very easily
template <typename T>

class graph{
    public:
    unordered_map<T,list<T>>adj;
    void addEdge(T u, T v , bool direction){
        // direction == 0->undirected graph
        // direection = 1 -> directed graph
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }


    }
    void printAdjlist(unordered_map<T,list<T>>adj){
        for(auto i: adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }


};

int main(){
    // no of nodes->n;
    // no of edges -> m;

    int n ; 
    cout<<"Enter the no of nodes "<<endl;
    cin>>n;
    int m ; 
    cout<<"Enter the no of edges"<<endl;
    cin>>m;
    graph<char> g;
    for(int i = 0 ; i< m ; i++){
       char u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);

    }
    g.printAdjlist(g.adj);


    return 0;
}