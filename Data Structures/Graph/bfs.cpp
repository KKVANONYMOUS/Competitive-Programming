#include <iostream>
#include <vector>
#include <queue>
using namespace std;



class Graph{
    public:
     int vertices;

     //Array of vectors of size V, V vectors are there
     vector <int> *adj;

     Graph(int V){
        vertices=V;
        adj= new vector <int>[V];
     }

    // adding edges
     void addEdge(int x, int y, bool bidir=true){
        adj[x].push_back(y);
        if(bidir){
            adj[y].push_back(x);
        }
     }

     void printadj(){
         for(int i=0;i<vertices;i++){
             cout<<i<<"->";
             for(auto x:adj[i]){
                 cout<<x<<",";
             }
             cout<<endl;
         }
     } 

    //Time Complexity: O(V+E)
     void bfs(int src,int destination){
         vector <bool> visited(vertices+1,false);
         vector <int> dist(vertices+1,0);
         vector <int> parent(vertices+1,-1);
         queue <int> q;

         visited[src]=true;
         q.push(src);

         while(!q.empty()){
             int node=q.front();
             cout<<node<<" ";
             q.pop();

             for(auto neighbour:adj[node]){
                 if(visited[neighbour]==false){
                     dist[neighbour]=dist[node]+1;
                     parent[neighbour]=node;
                     visited[neighbour]=true;
                     q.push(neighbour);
                 }
             }
         }

         cout<<"\nMinimum distance between "<<src<<" and "<<destination<<" is "<<dist[destination]<<"\n";
         int temp=destination;
         cout<<"The shortest path is "<<temp<<"->";
         while(parent[temp]!=-1){
             cout<<parent[temp]<<"->";
             temp=parent[temp];
         }
         cout<<"\n";

     }
};

int main(){

    Graph g(6);
    g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(0,4);
	g.addEdge(2,4);
	g.addEdge(3,2);
	g.addEdge(3,5);
	g.addEdge(3,4);
	
    g.printadj();
    g.bfs(0,5);

    return 0;
}
