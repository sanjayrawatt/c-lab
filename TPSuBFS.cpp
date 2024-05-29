#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> indegree(V, 0);
        vector<int> result;
        queue<int> qt;

        for (int i = 0; i < V; i++)
        {
            for (auto v : adj[i])
            {
                indegree[v]++;
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                qt.push(i);
            }
        }

        while (!qt.empty())
        {
            int u = qt.front();
            qt.pop();
            result.push_back(u);

            for (auto v : adj[u])
            {
                indegree[v]--;
                if (indegree[v] == 0)
                {
                    qt.push(v);
                }
            }
        }

        return result;
    }
};

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
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

    Solution solution;
    vector<int> topoOrder = solution.topoSort(V, adj);

    cout << "Topological Sort of the graph:" << endl;
    for (int i = 0; i < topoOrder.size(); i++)
    {
        cout << topoOrder[i] << " ";
    }
    cout << endl;

    return 0;
}
