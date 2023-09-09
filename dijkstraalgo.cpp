#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int,list<pair<int,int>>>adj;

    for(int i = 0 ; i< edges ; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        pair<int,int> p  = make_pair(v,w);
        adj[u].push_back(p);
        pair<int,int> newp = make_pair(u,w);
        adj[v].push_back(newp);
    }
    // we created adjecentery lsit
    vector<int>dis(vertices);
    for(int i = 0  ; i< vertices ; i++){
        dis[i] = INT_MAX;
    }
    // initialize all elemennts to infnity
    set<pair<int,int>>st; 
    dis[source] = 0;
    st.insert(make_pair(0,source));
    while(!st.empty()){
        // fetch topnode
        auto top = *(st.begin());
        int nodedistance = top.first;
        int topnode = top.second;
        // remove toprecord
        st.erase(st.begin());
        // traverse on neighbours
        for(auto neighbour:adj[topnode]){
            if(nodedistance+neighbour.second<dis[neighbour.first]){
                // finding previous record to delet eit
                auto record = st.find(make_pair(dis[neighbour.first],neighbour.first));
                // if record found then erase it
                if(record!=st.end()){
                    st.erase(record);
                }
                // distance update
                dis[neighbour.first]= nodedistance+neighbour.second;
                // recored push in set
                st.insert(make_pair(nodedistance+neighbour.second,neighbour.first));





            }
        }



    }
    return dis;
}

