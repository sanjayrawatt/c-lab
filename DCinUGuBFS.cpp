#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
    bool bfs(vector<int> adj[], int u, vector<bool> &visited)
    {
        queue<pair<int, int>> qt;
        visited[u] = true;
        qt.push(make_pair(u, -1));

        while (!qt.empty())
        {
            pair<int, int> node = qt.front();
            qt.pop();

            int n1 = node.first;
            int parent = node.second;

            for (int v : adj[n1])
            {
                if (v == parent)
                {
                    continue;
                }

                if (visited[v])
                {
                    return true;
                }
                else
                {
                    visited[v] = true;
                    qt.push(make_pair(v, n1));
                }
            }
        }

        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (bfs(adj, i, visited))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution solution;

    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<int> adj[V];
    int E;
    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the edges (u v) one by one:" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (solution.isCycle(V, adj))
    {
        cout << "Cycle detected." << endl;
    }
    else
    {
        cout << "No cycle detected." << endl;
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