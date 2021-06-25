#include <bits/stdc++.h>
using namespace std;



class Graph{
    public:
     int vertices;

     map <int,vector <pair<int,int>>> adj;

     Graph(int V){
        vertices=V;
     }

    // adding edges
     void addEdge(int x, int y, int w,bool bidir=true){
        adj[x].push_back({y,w});
        if(bidir){
            adj[y].push_back({x,w});
        }
     }

     void printadj(){
         for(auto x:adj){
            int a=x.first;
            cout<<a<<"->";
            for(auto y:x.second){
                cout<<y.first<<" "<<y.second<<" , ";
            }
            cout<<endl;
         }
     }

     //Backtracking Approach
     bool pathMoreThanKUtil(int src,int k,vector <int> &stackArray){
         if(k<=0) return true;
         
         for(auto x:adj[src]){
             int node=x.first;
             int w=x.second;
             
             //if current node is already in current path then don't include it otherwise it will form a cycle
             if(stackArray[node]) continue; 
             if(w>=k) return true;
             
             stackArray[node]=1;
             if(pathMoreThanKUtil(node,k-w,stackArray)) return true;
             stackArray[node]=0;

         }

         return false;
     }

     void pathMoreThanK(int src,int k){
        vector <int> stackArray(vertices,0);
        stackArray[src]=1;

        if(pathMoreThanKUtil(src,k,stackArray)) cout<<"True\n";
        else cout<<"False\n";
     }
     

    
};

int main(){

    Graph g(9);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    
    //g.printadj();
    g.pathMoreThanK(0,60);

    return 0;
}
