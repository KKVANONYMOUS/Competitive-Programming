#include <bits/stdc++.h>
using namespace std;

//Cycle Detection in an undirected graph using DSU
class Graph{
    public:
        int vertices;
        //Edge List Representation
        vector <pair<int,int>> edge;
        
        Graph(int V){
            vertices=V;
        }

        void addEdge(int u,int v){
            edge.push_back({u,v});
        }

        //Find operation
        //Time Complexity:O(N)
        int findSet(int i,vector <int> &parent){
               //base case
               if(parent[i]==-1) return i;
               //recursive call
               return findSet(parent[i],parent);
        }

        //Find operation - Path Compression
        //Time Complexity:O(log(N))
        int findSetOptimised(int i,vector <int> &parent){
               //base case
               if(parent[i]==-1) return i;
               //path compression optimization
               return parent[i]=findSetOptimised(parent[i],parent);
        }

        //Union operation
        //Time Complexity:O(N)
        void union_set(int a,int b,vector <int> &parent){
            int s1=findSet(a,parent);
            int s2=findSet(b,parent);

            if(s1!=s2){
                parent[s2]=s1;
            }
        }

        //Union operation - Union by rank
        //Time Complexity:O(log(N))
        void union_setOptimised(int a,int b,vector <int> &parent,vector <int> &rank){
            int s1=findSetOptimised(a,parent);
            int s2=findSetOptimised(b,parent);

            if(s1!=s2){
                if(rank[s1]<rank[s2]){
                    parent[s1]=s2;
                    rank[s2]+=rank[s1];
                }
                else{
                    parent[s2]=s1;
                    rank[s1]+=rank[s2];
                }
            }
        }

        bool contains_cycle(){
            //parent and rank vector 
            vector <int> parent(vertices,-1);
            vector <int> rank(vertices,1);

            //iterate over edge list
            for(auto x:edge){
                int a=x.first;
                int b=x.second;

                int s1=findSetOptimised(a,parent);
                int s2=findSetOptimised(b,parent);

                //if parent same then cycle is found else we do union of the two sets
                if(s1!=s2) union_setOptimised(a,b,parent,rank);
                else{
                    return true;
                }
            }

            return false;
        }

};

int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,3);
    g.addEdge(2,3);
    //g.addEdge(3,0);

    if(g.contains_cycle()) cout<<"Cycle found";
    else cout<<"No cycle detected";

    return 0;
}