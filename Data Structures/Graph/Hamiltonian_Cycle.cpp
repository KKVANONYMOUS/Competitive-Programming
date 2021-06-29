#include <bits/stdc++.h>
using namespace std;

const int V=5;

bool isSafe(int v,vector <int> &path,bool graph[][V],int pos){
    if(graph[v][path[pos-1]]==0) return false;

    for(int i=0;i<pos;i++){
        if(path[i]==v) return false;
    }

    return true;
}
bool hamiltonianCycle(bool graph[][V],vector <int> &path,int pos){
    if(pos==V){
        if(graph[path[pos-1]][0]!=0) return true;
        return false;
    }

    for(int i=1;i<V;i++){
        if(isSafe(i,path,graph,pos)){
            path[pos]=i;
            if(hamiltonianCycle(graph,path,pos+1)) return true;
            path[pos]=-1;
        }
    }

    return false;
}
int main(){
    bool graph[V][V] = {{0, 1, 0, 1, 0}, 
                        {1, 0, 1, 1, 1}, 
                        {0, 1, 0, 0, 1}, 
                        {1, 1, 0, 0, 1}, 
                        {0, 1, 1, 1, 0}}; 

    vector <int> path(V,-1);
    path[0]=0;

    if(hamiltonianCycle(graph,path,1)){
        for(auto x:path) cout<<x<<" ";
        cout<<"\nYES";
    }
    else cout<<"NO";
    return 0;
}