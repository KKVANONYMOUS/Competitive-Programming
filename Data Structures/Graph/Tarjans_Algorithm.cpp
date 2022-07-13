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
    }

    void dfs(int node, int &time, vector<bool> &isInStack, vector<int> &desc_time, vector<int> &low_time, stack<int> &st)
    {
        desc_time[node] = time; // Set the current node descovery time equal to the current time
        low_time[node] = time;  // Set the current node low time equal to the current time
        st.push(node);          // Push the node in the stack
        isInStack[node] = true; // Set isInStack to true

        time++; // Increment the timer for further evaluation

        // Iterate through all the neighbours of the current node
        for (auto x : adj[node])
        {
            if (desc_time[x] == -1) // If the node is not visited earlier do a DFS through it
            {
                dfs(x, time, isInStack, desc_time, low_time, st);  // The DFS call
                low_time[node] = min(low_time[node], low_time[x]); // Update the low value of the current node by comparing to its current neighbouring node
            }
            /*
             If the node is already visited and it is in the stack, that means it makes a back edge and unlike
            cross edges, back edges contribute to Strongly Connected Componenets (SCC)
            */
            else if (isInStack[x])
            {
                // Update the low value of the current node by comparing it with the descovery time of the neighbouring node to which its back edge points
                low_time[node] = min(low_time[node], desc_time[x]);
            }
        }

        // After all the above operation if the low_time and desc_time of the current node are equal that means it is the root of the SCC
        if (low_time[node] == desc_time[node])
        {
            // Looping till we find other node with low_time and desc_time equal, as the nodes between the two will constitute the SCC nodes of the current node
            while (!st.empty() and st.top() != node)
            {
                int curr_node = st.top();
                isInStack[curr_node] = false;
                st.pop();
                cout << curr_node << " ";
            }

            cout << st.top() << "\n";
            isInStack[st.top()] = false;
            st.pop();
        }
    }

    // Time Complexity: O(V+E)
    // Space Complexity: O(V)
    void tarjan_algo()
    {
        vector<bool> isInStack(vertices);    // To see which node values are currently in the stack
        vector<int> desc_time(vertices, -1); // To store the descovery time of a particular node
        vector<int> low_time(vertices);      // To store the lowest of descovery time of all the reachable nodes from the current node
        stack<int> st;                       // To store the nodes in the current path

        int time = 0; // Initialize the timer to 0

        for (int i = 0; i < vertices; i++)
        {
            if (desc_time[i] == -1) // Call DFS on each unvisited node
                dfs(i, time, isInStack, desc_time, low_time, st);
        }
    }
};

int main()
{
    Graph g(11);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 0);
    g.addEdge(2, 6);
    g.addEdge(3, 2);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 6);
    g.addEdge(5, 7);
    g.addEdge(5, 8);
    g.addEdge(5, 9);
    g.addEdge(6, 4);
    g.addEdge(7, 9);
    g.addEdge(8, 9);
    g.addEdge(9, 8);

    g.tarjan_algo();

    return 0;
}