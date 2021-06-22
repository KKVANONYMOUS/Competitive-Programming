#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    int vertices;
    vector <pair<int,int>> *adj;

    Graph(int n){
        vertices=n;
        adj=new vector <pair <int,int>> [n]; 
    }

    void addEdge(int x,int y,int w,int bidir=true){
        adj[x].push_back({y,w});
        if(bidir){
            adj[y].push_back({x,w});
        }
    }

    //Time Complexity:O(ElogV) - Greedy Algo
    void Prim(int src){
        vector <bool> visited(vertices+1,0);
        vector <int> parent(vertices+1,0);

        priority_queue <pair<int,int>,vector <pair<int,int>>,greater <pair<int,int>> > pq;
        pq.push({0,src});

        int cost=0;
        while(!pq.empty()){
            pair<int,int> x=pq.top();
            pq.pop();

            if(!visited[x.second]){
                visited[x.second]=1;
                cost+=x.first; //Inlcude cost when the node is removed from queue which means when the node is selected
                for(auto y:adj[x.second]){
                    if(!visited[y.first]){ //check if the node is already included in ans set or not
                        parent[y.first]=x.second; // to store the edged formed in the resulting MST
                        pq.push({y.second,y.first});
                    }
                }
            }
        }

        cout<<"Cost for MST is "<<cost<<"\n";
        for(int i=1;i<vertices;i++){
            cout<<i<<" - "<<parent[i]<<"\n";
        }


    }
};

int main(){
    Graph g(7);
    g.addEdge(1,2,3);
    g.addEdge(1,5,5);
    g.addEdge(2,5,6);
    g.addEdge(2,3,5);
    g.addEdge(5,6,2);
    g.addEdge(3,6,3);
    g.addEdge(3,4,9);
    g.addEdge(4,6,7);

    g.Prim(1);
    return 0;
}