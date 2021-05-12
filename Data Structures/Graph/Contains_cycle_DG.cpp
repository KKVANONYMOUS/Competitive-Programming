#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        int vertices;
        vector <int> *adj;

        Graph(int V){
            vertices=V;
            adj=new vector <int>[V];
        }

        void addEdge(int u,int v){
            adj[u].push_back(v);
        }
        
        //Time Complexity:O(V+E)
        //Space Complexity:O(V)
        bool contains_cycle_utility(int src,vector <int> &visited,vector <int> &stackArray){
            visited[src]=1;
            stackArray[src]=1;

            for(auto x:adj[src]){
                if(stackArray[x]==1) return true;
                else if(!visited[x]){
                    bool cycle_found=contains_cycle_utility(x,visited,stackArray);
                    if(cycle_found){
                        return true;
                    }
                }
            }

            stackArray[src]=0;
            return false;
        }
        
        void contains_cycle(){
            vector <int> visited(vertices,0);
            vector <int> stackArray(vertices,0);

            if(contains_cycle_utility(0,visited,stackArray)){
                cout<<"Cycle found";
            }
            else cout<<"No cycle detected";
        }

};

int main(){
    Graph g(6);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,0);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(4,1);
    g.addEdge(4,2);
    g.addEdge(4,5);
    g.addEdge(5,2);

    g.contains_cycle();
    return 0;
}