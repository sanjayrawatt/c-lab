#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    int find(int i, vector<int> &parent)
    {
        if (i == parent[i])
            return i;

        return parent[i] = find(parent[i], parent);
    }

    void unionn(int x, int y, vector<int> &rank, vector<int> &parent)
    {
        int parent_x = find(x, parent);
        int parent_y = find(y, parent);

        if (parent_x == parent_y)
            return;

        if (rank[parent_x] > rank[parent_y])
            parent[parent_y] = parent_x;
        else if (rank[parent_y] > rank[parent_x])
            parent[parent_x] = parent_y;
        else
        {
            parent[parent_y] = parent_x;
            rank[parent_x] += 1;
        }
    }

public:
    // Function to detect cycle using DSU in an undirected graph.
    bool detectCycle(int V, vector<int> adj[])
    {
        vector<int> parent(V);
        vector<int> rank(V, 1);

        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
        }

        for (int i = 0; i < V; i++)
        {
            for (auto v : adj[i])
            {
                if (i < v) // To ensure each edge is only checked once
                {
                    int parent_u = find(i, parent);
                    int parent_v = find(v, parent);

                    if (parent_u == parent_v)
                        return true;

                    unionn(i, v, rank, parent);
                }
            }
        }

        return false;
    }
};

int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<int> adj[V];
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Since the graph is undirected
    }

    Solution sol;
    bool result = sol.detectCycle(V, adj);
    if (result)
    {
        cout << "The graph contains a cycle." << endl;
    }
    else
    {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}
