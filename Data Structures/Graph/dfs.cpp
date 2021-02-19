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

     void dfsUtility(int src, vector <bool> &visited){
         cout<<src<<" ";
         visited[src]=true;
         for(auto x: adj[src]){
             if(visited[x]==false){
                 visited[x]=true;
                 dfsUtility(x,visited);
             }
         }
     }
     void dfs(int src){
         vector <bool> visited(vertices+1,false);
         dfsUtility(src,visited);

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
    g.dfs(2);

    return 0;
}
