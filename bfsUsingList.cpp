#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
    void bfs(vector<int> adj[], int u, vector<bool> &visited, vector<int> &result)
    {
        queue<int> qt;
        qt.push(u);
        visited[u] = true;

        while (!qt.empty())
        {
            int node = qt.front();
            qt.pop();
            result.push_back(node);

            for (auto v : adj[node])
            {
                if (!visited[v])
                {
                    qt.push(v);
                    visited[v] = true;
                }
            }
        }
    }

public:
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        vector<int> result;

        for (int i = 0; i < V; ++i)
        {
            if (!visited[i])
            {
                bfs(adj, i, visited, result);
            }
        }

        return result;
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
    for (int i = 0; i < E; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> bfsTraversal = solution.bfsOfGraph(V, adj);

    cout << "BFS Traversal: ";
    for (int node : bfsTraversal)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

/*
Enter the number of vertices: 6
Enter the number of edges: 6
Enter the edges (u v) one by one:
5 5
0 1
1 2
1 4
2 3
3 4
DFS Traversal: 0 1 2 3 4 5
*/