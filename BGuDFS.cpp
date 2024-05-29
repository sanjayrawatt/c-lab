#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    bool dfs(vector<int> adj[], int u, vector<int> &color, int colorOfu)
    {
        color[u] = colorOfu;
        for (auto v : adj[u])
        {
            if (color[v] == colorOfu)
                return false;

            if (color[v] == -1)
            {
                int colorOfv = 1 - colorOfu;
                if (!dfs(adj, v, color, colorOfv))
                    return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (!dfs(adj, i, color, 1)) // Initial color can be 0 or 1
                {
                    return false;
                }
            }
        }

        return true;
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
    bool result = sol.isBipartite(V, adj);
    if (result)
    {
        cout << "The graph is bipartite." << endl;
    }
    else
    {
        cout << "The graph is not bipartite." << endl;
    }

    return 0;
}
