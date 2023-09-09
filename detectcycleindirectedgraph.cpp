#include<bits/stdc++.h>
bool isCyclic(int node,unordered_map<int,list<int>>& adjlist, unordered_map<int , bool>&dfsvisited,unordered_map<int,bool>&visited)
{
    visited[node]=true;
    dfsvisited[node]=true;
    for(auto i:adjlist[node]){
      if(!visited[i]){
        bool cycle =  isCyclic(i, adjlist, dfsvisited, visited);
        if(cycle==true){
          return true;
        }
        
      }
      else if(dfsvisited[i]==true){
        return true;
      }
      
    }
    dfsvisited[node]=false;
    return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int,bool>visited;
  unordered_map<int , bool>dfsvisited;
  unordered_map<int,list<int>> adjlist;

    for(int i = 0 ;i<edges.size() ; i++){
      int u = edges[i].first;
      int v=edges[i].second;

      adjlist[u].push_back(v);


    }

    for(int i = 1 ; i<=n ; i++){
      if(!visited[i]){
        bool cyclefound = isCyclic(i,adjlist,dfsvisited,visited);

        if(cyclefound==true){
          return true;
        }
         
      }
    }
    return false;

}