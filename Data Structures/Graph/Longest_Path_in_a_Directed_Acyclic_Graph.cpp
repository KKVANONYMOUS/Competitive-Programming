#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    int vertices;
    unordered_map <int,vector <pair <int,int>>> adj;

    Graph(int n){
        vertices=n;
    }

    void addEdge(int x,int y,int w){
        adj[x].push_back({y,w});
    }

    void dfsTS(int src,unordered_map <int,vector <pair <int,int>>> adj,vector <int> &vis,stack <int> &st){
        vis[src]=1;

        for(auto x:adj[src]){
            if(!vis[x.first]){
                dfsTS(x.first,adj,vis,st);
            }
        }

        st.push(src);
    }
    void longestPath(int src){
        vector <int> vis(vertices,0);

        stack <int> st;

        for(int i=0;i<vertices;i++){
            if(!vis[i]){
                dfsTS(i,adj,vis,st);
            }
        }

        vector <int> dist(vertices,INT_MIN);
        dist[src]=0;

        vector <int> parent(vertices,-1);
        while(!st.empty()){
            int x=st.top();
            st.pop();

            for(auto y:adj[x]){
                if(dist[x]+y.second>dist[y.first]){
                    dist[y.first]=dist[x]+y.second;
                    parent[y.first]=x;
                }
            }
        }

        for(int i=0;i<vertices;i++){
            cout<<"Longest distance of "<<i<<" from "<<src<<" is "<<dist[i]<<"\n";
        }

        cout<<"The corresponding paths are:\n";
        for(int i=0;i<vertices;i++){
            int temp=i;
            while(temp!=-1){
                cout<<temp<<" <-- ";
                temp=parent[temp];
            }
            cout<<"\n";
        }

    }
    
};

int main(){
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.longestPath(1);
    return 0;
}