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

     bool containsCycleUtil(int node,vector <bool> &visited,vector <int> &parent){
         visited[node]=true;
         for(auto x:adj[node]){
             if(visited[x]==false){
                 parent[x]=node;
                 if(containsCycleUtil(x,visited,parent)) return true;
             }
             else if(parent[node]!=x) return true;
         }

         return false;

     }
     void containsCycle(){
        vector <bool> visited(vertices+1,false);
        vector <int> parent(vertices+1,-1);

        for(int i=0;i<vertices;i++){
            if(visited[i]==false){
                if(containsCycleUtil(i,visited,parent)){
                    cout<<"The graph contains a cycle\n";
                    return;
                }
            }
        }
        cout<<"The graph does not contain a cycle\n";
     } 

     
};

int main(){

    //Graph g(6);
    //g.addEdge(1,4);
    //g.addEdge(1,3);
    //g.addEdge(3,4);
    //g.addEdge(3,2);
    //g.addEdge(3,5);
    //g.addEdge(2,5);
    Graph g(4);
    g.addEdge(1,2);
    g.addEdge(2,3);
	
    g.printadj();
    g.containsCycle();
    
    return 0;
}
