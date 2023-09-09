#include<unordered_map>
#include<bits/stdc++.h>


void dfs(int node,unordered_map<int,list<int>>&adjlist,unordered_map<int,bool>&visited,vector<int>&component)
{
    component.push_back(node);
    visited[node]= 1;
    // har connected node ke lie recursive call
    for(auto i:adjlist[node]){
        if(!visited[i]){
            dfs(i, adjlist, visited, component);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // prepare adj list
    unordered_map<int,list<int>>adjlist;
    unordered_map <int , bool> visited;
    vector<vector<int>>ans;



    for(int i = 0; i< E; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    
    // preparing of adj list is done
    for(int i =0; i<V;i++){


        if(!visited[i]){
            vector<int>component;
            dfs(i,adjlist,visited,component); 
            ans.push_back(component);

        }
    }
    return ans;


    

}