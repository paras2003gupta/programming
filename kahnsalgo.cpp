// this is donw using topological sorting technique using bfs(bredth first search) technique

#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int,list<int>>adj;
    vector<int>indegree(v);
    // creating adj list
    for(int i = 0 ; i<e ; i++){
        int u = edges[i][0];
        int v= edges[i][1];
        
        adj[u].push_back(v);
    }
    // adj list created successfully
    for(auto i: adj){
        
        for(auto j: i.second){
            indegree[j]++;
        } 
    } 
    // 0 indegree walo ko push krdoo
    queue<int>q;
    for(int i = 0 ; i< v ; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>ans;
    
    while(!q.empty()){
        int front = q.front();
        ans.push_back(front);
        
        q.pop();
        
        for(auto neighbour : adj[front]){
            indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                    
                }
                
            
        }
        
    }
    return ans;
        
    
    
}