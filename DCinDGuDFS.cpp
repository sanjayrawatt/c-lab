#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    bool dfs(vector<int> adj[], int u, vector<bool> &visited, vector<bool> &currRecur)
    {
        visited[u] = true;
        currRecur[u] = true;

        for (auto v : adj[u])
        {
            if (visited[v] && currRecur[v])
            {
                return true;
            }
            if (!visited[v])
            {
                if (dfs(adj, v, visited, currRecur))
                {
                    return true;
                }
            }
        }

        currRecur[u] = false;
        return false;
    }

public:
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        vector<bool> currRecur(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(adj, i, visited, currRecur))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    Solution solution;

    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<int> adj[V];
    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the edges (u v) one by one:" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    if (solution.isCyclic(V, adj))
        cout << "Graph contains cycle" << endl;
    else
        cout << "Graph doesn't contain cycle" << endl;

    return 0;
}
