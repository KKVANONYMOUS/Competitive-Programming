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
                 cout<<"("<<get<0>(x)<<","<<get<1>(x)<<") - "<<get<2>(x)<<"\n";
             }
             cout<<endl;
        
     }

     //TO FIND PARENT OF THE CURRENT NODE
     int findParent(int x ,vector <int> &link){
         while(x!=link[x]) x=link[x];
         return x;
     }

     //TO CHECK IF TWO NODES ARE IN SAME SET OR NOT
     bool isSameSet(int a, int b,vector <int> link){
         return findParent(a,link)==findParent(b,link);
     }

     /*TO UNITES TWO SETS
        more optimized because of the use of size array that keeps sure that the length of the chain is log(n)
     */
     void uniteSet(int a,int b,vector <int> &link,vector <int> &setSize){
         a=findParent(a,link);
         b=findParent(b,link);
         if(setSize[a] <= setSize[b]){
             link[a]=b;
             setSize[b]+=setSize[a];
         }
         else{
             link[b]=a;
             setSize[a]+=setSize[b];
         }
     }

     void Kruskal(){
         vector <pair<int,pair<int,int>>> edges;
         for(auto x:(*adj)){
             edges.push_back({get<2>(x),{get<0>(x),get<1>(x)}});
        }

        sort(edges.begin(),edges.end());

        vector <int> link(vertices);
        vector <int> setSize(vertices,1);

        for(int i=0;i<vertices;i++){
            link[i]=i;
        }

        Graph mst(vertices);

        for(int i=0;i<edges.size();i++){
            int a=edges[i].second.first,b=edges[i].second.second,w=edges[i].first;
            if(!isSameSet(a,b,link)){
                uniteSet(a,b,link,setSize);
                mst.addEdge(a,b,w);
            }
            
        }
        mst.printadj();

     }
     
};

int main(){
  
    
    Graph g(7);
    g.addEdge(1,2,3);
    g.addEdge(1,5,5);
    g.addEdge(2,5,6);
    g.addEdge(2,3,5);
    g.addEdge(5,6,2);
    g.addEdge(3,6,3);
    g.addEdge(3,4,9);
    g.addEdge(4,6,7);

	
    //g.printadj();
    g.Kruskal();

    
    return 0;
}
