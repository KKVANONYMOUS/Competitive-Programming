#include <bits/stdc++.h>
using namespace std;



class Graph{
    public:
     int vertices;

     map <int,vector <pair<int,int>>> adj;

     Graph(int V){
        vertices=V;
     }

    // adding edges
     void addEdge(int x, int y, int w,bool bidir=true){
        adj[x].push_back({y,w});
        if(bidir){
            adj[y].push_back({x,w});
        }
     }

     void printadj(){
         for(auto x:adj){
            int a=x.first;
            cout<<a<<"->";
            for(auto y:x.second){
                cout<<y.first<<" "<<y.second<<" , ";
            }
            cout<<endl;
         }
     }

     void dijkstra(int src){
        vector <int> dist(vertices+1,INT_MAX);
        vector <bool> visited(vertices+1,0);
        priority_queue <pair<int,int>> q;
        q.push({0,src});
        dist[src]=0;

        while(!q.empty()){
            int a = q.top().second;
            q.pop();
            if(!visited[a]){
                visited[a]=true;
                for(auto e:adj[a]){
                    int b=e.first,w=e.second;
                    dist[b]=min(dist[b],dist[a]+w);
                    q.push({-dist[b],b});
                }
            }
        }

        for(int i=0;i<dist.size();i++){
            cout<<i<<" "<<dist[i]<<endl;
        }

     }
     

    
};

int main(){

    Graph g(5);
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(1,4,7);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    
    g.printadj();
    g.dijkstra(1);

    return 0;
}
