#include <bits/stdc++.h> 
#include<stack>
#include<vector>
#include<unordered_map>
#include<list> 
void dfs(int node,unordered_map<int,list<int>>&adj,vector<bool>&visited,stack<int>&s)
{   

    visited[node] = 1;

    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            dfs(neighbour,adj,visited,s);
            
        }
    }
    // important call
    s.push(node);
    

}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // create adj lst
    unordered_map<int,list<int>>adj;
    vector<bool>visited(v,false);
    vector<int>ans;
    stack<int>s;
    for(int i = 0 ; i<e ; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }
    for(int i = 0 ; i< v ; i++){
        if(!visited[i]){
            dfs(i,adj,visited,s);
        }
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans; 




}