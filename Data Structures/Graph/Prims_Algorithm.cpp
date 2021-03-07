#include <bits/stdc++.h>
using namespace std;

const int vertices=6;

int findMin(vector <int> dist,vector <bool> isIncluded){
    int ans=INT_MAX;
    int index=0;

    for(int i=0;i<dist.size();i++){
        if(isIncluded[i]==false and dist[i]<ans){
            ans=dist[i];
            index=i;
        }
    }

    return index;
}

//TIME COMPLEXITY: O(v^v)
void prims(int graph[][vertices]){
    vector <bool> isIncluded(vertices,false);
    vector <int> dist(vertices,INT_MAX);
    vector <int> parent(vertices,-1);

    dist[0]=0;

    for(int i=0;i<vertices-1;i++){
        int x=findMin(dist,isIncluded);
        isIncluded[x]=true;

        for(int j=0;j<vertices;j++){
            if(isIncluded[j]==false and graph[x][j]<dist[j] and graph[x][j]!=0){
                dist[j]=graph[x][j];
                parent[j]=x;
            }
        }
    }

    for(int i=1;i<parent.size();i++){
        cout<<"("<<parent[i]<<","<<i<<") - "<<graph[parent[i]][i]<<endl;
    }
}

int main(){
  
    int graph[][vertices] = { {0, 4, 6, 0, 0, 0},
						{4, 0, 6, 3, 4, 0},
						{6, 6, 0, 1, 8, 0},
						{0, 3, 1, 0, 2, 3},
						{0, 4, 8, 2, 0, 7},
						{0, 0, 0, 3, 7, 0} };

    prims(graph);    
    return 0;
}
