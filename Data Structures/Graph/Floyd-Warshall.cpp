#include <bits/stdc++.h>
using namespace std;



class Graph{
    public:
     int vertices;

     int adj[100][100];

     Graph(int V){
        vertices=V;
     }

    // adding edges
     void addEdge(int x, int y, int w,bool bidir=true){
        adj[x][y]=w;
        if(bidir){
            adj[y][x]=w;
        }
     }

     void printadj(){
         for(int i=1;i<vertices;i++){
            for(auto x:adj[i]){
                cout<<x<<" ";
            }
            cout<<"\n";
         }
     }

     void floydWarshall(){
        vector <vector<int>> dist(vertices,vector <int> (vertices));
        for(int i=1;i<vertices;i++){
            for(int j=1;j<vertices;j++){
                if(i==j) dist[i][j]=0;
                else if (adj[i][j]) dist[i][j]=adj[i][j];
                else dist[i][j]=1e7;
            }
        }

        for(int k=1;k<vertices;k++){
            for(int i=1;i<vertices;i++){
                for(int j=1;j<vertices;j++){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        for(int i=1;i<vertices;i++){
            for(int j=1;j<vertices;j++){
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }
     }
     

};

int main(){

    Graph g(6);
    g.addEdge(1,5,1);
    g.addEdge(1,4,9);
    g.addEdge(1,2,5);
    g.addEdge(5,4,2);
    g.addEdge(4,3,7);
    g.addEdge(3,2,2);
    
    //g.printadj();
    g.floydWarshall();

    return 0;
}
