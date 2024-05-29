#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> indegree(V, 0);
        queue<int> qt;
        int count = 0;

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
                count++;
            }
        }

        while (!qt.empty())
        {
            int u = qt.front();
            qt.pop();

            for (auto v : adj[u])
            {
                indegree[v]--;
                if (indegree[v] == 0)
                {
                    qt.push(v);
                    count++;
                }
            }
        }

        if(count == V)
            return false;
        else 
            return true;
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

    if (solution.isCycle(V, adj))
    {
        cout << "Cycle detected" << endl;
    }
    else
    {
        cout << "No cycle detected" << endl;
    }

    return 0;
}
