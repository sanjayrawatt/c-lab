#include <vector>
#include<iostream>
using namespace std;

class Solution
{
    bool dfs(vector<int> adj[], int u, vector<bool> &visited, int parent)
    {
        visited[u] = true;

        for (auto v : adj[u])
        {
            if (v == parent)
            {
                continue;
            }

            if (visited[v])
            {
                return true; // Cycle detected
            }

            if (dfs(adj, v, visited, u))
            {
                return true;
            }
        }

        return false; // No cycle found
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(adj, i, visited, -1))
                {
                    return true; // Cycle detected
                }
            }
        }

        return false; // No cycle found
    }
};

int main()
{
    // Example usage of the Solution class
    Solution solution;

    // Number of vertices
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    // Adjacency list representation of the graph
    vector<int> adj[V];
    int E;
    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the edges (u v) one by one:" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }

    // Check if the graph contains a cycle
    if (solution.isCycle(V, adj))
    {
        cout << "The graph contains a cycle." << endl;
    }
    else
    {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}

/*
Enter the number of vertices: 6
Enter the number of edges: 6
Enter the edges (u v) one by one:
Edge 1: 5 5
Edge 2: 0 1
Edge 3: 1 2
Edge 4: 1 4
Edge 5: 2 3
Edge 6: 3 4
Cycle detected.
*/