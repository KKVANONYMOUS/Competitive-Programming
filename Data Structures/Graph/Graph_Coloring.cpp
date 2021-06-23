#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    int vertices;
    unordered_map <int,vector <int>> adj;

    Graph(int n){
        vertices=n;
    }

    void addEdge(int x,int y,int bidir=true){
        adj[x].push_back(y);
        if(bidir){
            adj[y].push_back(x);
        }
    }

    void findChromaticNumber(){
        vector <int> colored(vertices,-1);
        vector <bool> selectedColor(vertices,false);

        int chromaticNumber=1;
        colored[0]=0;

        for(int i=1;i<vertices;i++){
            for(auto x:adj[i]){
                if(colored[x]!=-1){
                    selectedColor[colored[x]]=true;
                }
            }

            int color;
            for(color=0;color<vertices;color++){
                if(selectedColor[color]==false){
                    break;
                }
            }

            colored[i]=color;
            chromaticNumber=max(chromaticNumber,color+1);

            for(auto x:adj[i]){
                if(colored[x]!=-1){
                    selectedColor[colored[x]]=false;
                }
            }
        }

        cout<<"Chromatic Number is "<<chromaticNumber<<"\n";
        for(int i=0;i<vertices;i++){
            cout<<"Vertex "<<i<<" ---> Color "<<colored[i]<<"\n";
        }
    }
    
};

int main(){
    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);

    g1.findChromaticNumber();

    cout<<"\n";
    
    Graph g2(5);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(1, 2);
    g2.addEdge(1, 4);
    g2.addEdge(2, 4);
    g2.addEdge(4, 3);
    g2.findChromaticNumber();
    return 0;
}