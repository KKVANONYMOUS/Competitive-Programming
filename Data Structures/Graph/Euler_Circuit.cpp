#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int vertices;
    vector<int> *adj;

    Graph(int n)
    {
        vertices = n;
        adj = new vector<int>[n];
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Traversing all the vertices
    void dfs(int node, vector<bool> &isVisited)
    {
        isVisited[node] = true;
        for (auto x : adj[node])
        {
            if (!isVisited[x])
                dfs(x, isVisited);
        }
    }

    // To check if all the edges of the graph lie in same component or not
    bool isConnected()
    {
        vector<bool> isVisited(vertices, false);

        int node = -1;
        for (int i = 0; i < vertices; i++)
        {
            if (adj[i].size() > 0)
            {
                node = i;
                break;
            }
        }

        if (node == -1)
            return true;

        dfs(node, isVisited);

        for (int i = 0; i < vertices; i++)
        {
            if (!isVisited[i])
            {
                if (adj[i].size() > 0)
                    return false;
            }
        }

        return true;
    }

    int find_Euler()
    {
        if (!isConnected())
            return 0;

        int odd = 0;
        for (int i = 0; i < vertices; i++)
        {
            if (adj[i].size() & 1)
            {
                odd++;
            }
        }

        // if number of vertices with odd degree is more than 2 then its not Euler Graph
        if (odd > 2)
            return 0;

        /*
        if number of vertices with odd degree zero it means it is a Eulerian Graph (with Euler circuit) else if the count is equal to one
        then its a Semi-Eulerian Graph (with only Euler Path)
        */
        return odd == 0 ? 2 : 1;
    }

    // Time Complexity: O(V+E)
    void find_Euler_Circuit()
    {
        int res = find_Euler();

        if (res == 0)
        {
            cout << "Not a Euler Graph\n";
        }
        else if (res == 1)
        {
            cout << "Semi-Eulerian Graph (Contains only Euler Path but not a Euler Circuit)\n";
        }
        else
        {
            cout << "Euler Graph (Eulerian Circuit)\n";
        }
    }
};

int main()
{
    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(0, 3);
    g1.addEdge(0, 4);
    g1.addEdge(1, 2);
    g1.addEdge(3, 4);
    g1.find_Euler_Circuit();

    Graph g2(5);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(0, 3);
    g2.addEdge(1, 3);
    g2.addEdge(1, 2);
    g2.addEdge(3, 4);
    g2.find_Euler_Circuit();

    Graph g3(5);
    g3.addEdge(0, 1);
    g3.addEdge(0, 2);
    g3.addEdge(0, 3);
    g3.addEdge(0, 4);
    g3.addEdge(1, 3);
    g3.addEdge(1, 2);
    g3.addEdge(3, 4);
    g3.find_Euler_Circuit();

    return 0;
}