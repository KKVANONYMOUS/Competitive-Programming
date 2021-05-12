#include <bits/stdc++.h>
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

        void topological_sort_utility(int src,stack <int> &st,vector <int> &visited){
            visited[src]=1;
            for(auto x:adj[src]){
                if(!visited[x]){
                    topological_sort_utility(x,st,visited);
                }
            }

            st.push(src);
            return;
        }
        
        //Time Complexity:O(V+E)
        //Space Complexity:O(V) - due to temporary stack
        void topological_sort(){
            vector <int> visited(vertices,0);
            stack <int> st;

            for(int i=0;i<vertices;i++){
                if(!visited[i]){
                    topological_sort_utility(i,st,visited);
                }
            }

            while(!st.empty()){
                cout<<st.top()<<" ";
                st.pop();
            }
        }
};
int main(){
    Graph g(6);
    g.addEdge(5,0);
    g.addEdge(5,2);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(2,3);
    g.addEdge(3,1);

    g.topological_sort();
    return 0;
}