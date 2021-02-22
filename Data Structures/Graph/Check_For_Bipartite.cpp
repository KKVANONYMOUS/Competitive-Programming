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

      bool isBipartiteUtil(int node,vector <bool> &visited,vector <char> &color){
          visited[node]=true;
          for(auto x:adj[node]){
              if(!visited[x]){
                  color[x]=color[node]=='R'?'B':'R';
                  if(!isBipartiteUtil(x,visited,color)) return false;
              }
              else if(color[x]==color[node]) return false;
          }
          return true;
      }

      bool isBipartite(){
        vector <bool> visited(vertices+1,false);
        vector <char> color(vertices+1,'B');

        for(int i=0;i<vertices;i++){
            if(!visited[i]){
                if(!isBipartiteUtil(i,visited,color)){
                    return false;
                }
            }
        }
      
        return true;
          
      }

     
};

int main(){

    Graph g(7);
    g.addEdge(1,4);
    g.addEdge(1,5);
    g.addEdge(5,2);
    g.addEdge(5,6);
    g.addEdge(3,2);
    g.addEdge(3,6);
    //g.addEdge(1,2);

	
    g.printadj();

    if(g.isBipartite()){
        cout<<"Bipartite\n";
    }
    else{
        cout<<"Not Bipartite\n";
    }
    
    return 0;
}
