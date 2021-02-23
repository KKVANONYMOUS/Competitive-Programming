#include <bits/stdc++.h>
using namespace std;



class Graph{
    public:
     int vertices;

     //Vector of tuples, each tuple containe the nodes haiving an edge between them along with theri weights
     vector <tuple<int,int,int>> *adj;

     Graph(int V){
        vertices=V;
        adj= new vector <tuple<int,int,int>>;
     }

    // adding edges
     void addEdge(int x, int y, int w,bool bidir=false){
        (*adj).push_back({x,y,w});
     }

     void printadj(){
         
             for(auto x:(*adj)){
                 cout<<get<0>(x)<<" "<<get<1>(x)<<" "<<get<2>(x)<<",";
             }
             cout<<endl;
        
     }

     void Bellman_Ford(int src){
         vector <int> dist(vertices+1,INT_MAX);
         dist[src]=0;
         for(int i=1;i<=vertices-1;i++){
             for(auto x:(*adj)){
                 int a,b,w;
                 tie(a,b,w)=x;
                 dist[b]=min(dist[b],dist[a]+w);
             }
         }

         for(auto x:(*adj)){
            int a,b,w;
            tie(a,b,w)=x;
            if(dist[a]+w<dist[b]){
                cout<<"Negative cycle encountered\n";
                return;
            }
        }

     }
     
};

int main(){
  
    
    Graph g(6);
    g.addEdge(1,2,4);
    g.addEdge(1,4,5);
    g.addEdge(4,3,3);
    g.addEdge(3,2,-10);
    g.addEdge(2,4,5);

	
    g.printadj();
    g.Bellman_Ford(1);

    
    return 0;
}
