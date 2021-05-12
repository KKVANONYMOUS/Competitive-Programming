#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        int vertices;
        vector <int> *adj;
        vector <int> *rev_adj;

        Graph(int V){
            vertices=V;
            adj=new vector <int> [V];
            rev_adj=new vector <int> [V];
        }

        void addEdge(int u,int v){
            adj[u].push_back(v);
            rev_adj[v].push_back(u);
        }

        void dfs(int node,vector <int> &visited,stack <int> &st){
            visited[node]=1;
            for(auto x:adj[node]){
                if(!visited[x]){
                    dfs(x,visited,st);
                }
            }
            st.push(node);
        }

        void dfs2(int node,vector <int> &visited){
            visited[node]=1;
            cout<<node<<" ";
            for(auto x:rev_adj[node]){
                if(!visited[x]){
                    dfs2(x,visited);
                }
            }
        }

        void kosaraju(){
            vector <int> visited(vertices,0);
            stack <int> st;

            for(int i=0;i<vertices;i++){
                if(!visited[i]){
                    dfs(i,visited,st);
                }
            }

            fill(visited.begin(),visited.end(),0);
           
            char component_name='A';
            while(!st.empty()){
                int i=st.top();
                st.pop();
                if(!visited[i]){
                    cout<<"Component "<<component_name<<" --> ";
                    dfs2(i,visited);
                    cout<<"\n";
                    component_name++;
                }
            }
        }

};
int main(){
    Graph g(7);
    g.addEdge(1,0);
    g.addEdge(0,2);
    g.addEdge(2,1);
    g.addEdge(0,3);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.addEdge(6,3);

    g.kosaraju();
    return 0;
}