#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    int vertices;
    unordered_map <int,vector <pair <int,int>>> adj;

    Graph(int n){
        vertices=n;
    }

    void addEdge(int x,int y){
        adj[x].push_back({y,0});
        adj[y].push_back({x,1});
    }

    int bfs(int src,int dest){
        vector <int> dist(vertices,INT_MAX);
        vector <bool> vis(vertices,0);

        priority_queue <pair <int,int>,vector <pair <int,int>>,greater <pair <int,int>>> q;
        q.push({0,src});
        dist[src]=0;

        while(!q.empty()){
            int node=q.top().second;
            q.pop();

            if(!vis[node]){
                vis[node]=1;
                for(auto x:adj[node]){
                    int curr=x.first;
                    int w=x.second;

                    dist[curr]=min(dist[curr],dist[node]+w);
                    q.push({dist[curr],curr});
                }
            }
            

        }

        return dist[dest];
    }
    
    
};

int main(){
    int V = 7;
    vector <vector <int>> edge = {{0, 1}, {2, 1}, {2, 3}, {5, 1},
                     {4, 5}, {6, 4}, {6, 3}};
    
    Graph g(V);
    for(auto x:edge){
        g.addEdge(x[0],x[1]);
    }

    int ans=g.bfs(0,6);
    if(ans==INT_MAX) cout<<-1;
    else cout<<ans; 
    return 0;
}