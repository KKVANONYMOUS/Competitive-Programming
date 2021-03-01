#include <bits/stdc++.h>
using namespace std;


class Graph{
public:
	int vertices;
	vector<int> *adj;
	Graph(int V){
		vertices=V;
		adj=new vector <int>[V];
	}

	void addEdge(int x,int y){
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	void printadj(){
		for(int i=1;i<vertices;i++){
			cout<<i<<" ";
			for(auto e:adj[i]){
				cout<<e<<" ";
			}
			cout<<endl;
		}
	}

	//For storing the farthest node
	int farNode;

	//DFS utility function
	void dfsUtil(int src,int count,int &maxCount,vector <bool> &visited){
		count++;
		visited[src]=true;
		for(auto x:adj[src]){
			if(!visited[x]){
				if(count>=maxCount){
					maxCount=count;
					farNode=x;
				}
				dfsUtil(x,count,maxCount,visited);
			}
		}
	}

	//To implement DFS
	void dfs(int src,int &maxCount){
		vector <bool> visited(vertices,false);
		int count=0;
		dfsUtil(src,count + 1,maxCount,visited);
	}

	//To calculate diameter of a tree
	int diameter(){
		int maxCount=INT_MIN;

		//searches for the farthest node from the given src node
		dfs(1,maxCount);

		//searches for the farthest node from the farthest node acquired from the previous function call
		dfs(farNode,maxCount);

		return maxCount;
	}
};

int main(){
	Graph g(6);

	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(4,2);
	g.addEdge(5,2);

	g.printadj();
	cout<<"Diameter of the given tree is "<<g.diameter();
	return 0;
}