
#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
    unordered_map<int,list<pair <int,int>>>adj;
    void addEdge(int u , int v , int weight){
        pair<int,int> p = make_pair(v,weight);
        adj[u].push_back(p);

    }
    void printadj(){
        for(auto i :adj){
           cout<<i.first<<"->";
           for(auto j : i.second){
            cout<<"("<<j.first<<","<<j.second<<"),";
           }
           cout<<endl;
        }
    }
    void dfs(vector<bool>&visited,stack<int>&topo,int node){
        visited[node]= 1;
        for(auto neighbour : adj[node]){
            if(!visited[neighbour.first]){
                visited[neighbour.first]=1;
                dfs(visited,topo,neighbour.first);

            }
        }
        topo.push(node);
    }
    void storedistance(vector<int>&dis,stack<int>s,int src){
        dis[src]= 0;
        while(!s.empty()){
            int top = s.top();
            s.pop();
        // Very imp part of the question basically jaan of the question
            if(dis[top]!=INT_MAX){
                for(auto i : adj[top]){
                    if(dis[top]+i.second<dis[i.first]){
                        dis[i.first] = dis[top]+i.second;
                    }
                }
            }
        }
    }




};

int main(){
    int n = 6;
    graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);
    g.printadj();

    // topological sort
    stack<int>s;
    vector<bool>visited(n,0);
    for(int i = 0 ; i< n ; i++){
        if(!visited[i]){
           g.dfs(visited,s,i);
        }
    }
    // after this we have saved our topological sort into stack s
    vector<int>ans(n);
    for(int i = 0 ; i< n ; i++){
        ans[i] = INT_MAX;
    }
    int src = 1;
    g.storedistance(ans,s,src);
    // now printing answer array
    cout<<" now printing answer array"<<endl;
    for(int i = 0  ; i< n ; i++){
        cout<<ans[i]<<" ";
    }cout<<endl;

    
    


    return 0;

}