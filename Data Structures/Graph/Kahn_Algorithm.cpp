#include<bits/stdc++.h>
using namespace std;

/*
Kahn's Algorithm implements Topological sorting using BFS which also detects if a cycle is present or not.
If cycle is present then we cannot find its Topological sort as the nodes present in cycle will mutually depend on each other
*/

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
        //Space Complexity:O(V) - due to temporary queue
        void topological_sort(){
            //Initialize a vector containing indegree value of each node
            vector <int> inDegree(vertices,0);
            vector <int> order;

            //Calculate the indegree of each node
            for(int i=0;i<vertices;i++){
                for(auto y:adj[i]){
                    inDegree[y]++;
                }
            }

            //declare a queue for storing nodes
            queue <int> q;

            //Storing nodes whose indegree is equal to 0
            for(int i=0;i<vertices;i++){
                if(inDegree[i]==0){
                    q.push(i);
                }
            }

            //Perform BFS
            while(!q.empty()){
                int x=q.front();
                order.push_back(x);
                //cout<<x<<" ";
                q.pop();

                for(auto y:adj[x]){
                    //reducing the indegree of all successors of the current node by 1
                    inDegree[y]--;
                    //checking if the current successors's indegree is equal to 0 or not
                    if(inDegree[y]==0) q.push(y);
                }
            }

            if(order.size()!=vertices){
                //cout<<"\n"<<order.size()<<"\n";
                cout<<"Cycle detected";
            }
            else{
                for(auto x:order) cout<<x<<" ";
            }
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
    //g.addEdge(5,2);

    g.topological_sort();
    return 0;
}