#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
private:
    void dfs(vector<int> adj[], int u, vector<bool> &visited, stack<int> &st)
    {
        visited[u] = true;

        for (auto v : adj[u])
        {
            if (!visited[v])
            {
                dfs(adj, v, visited, st);
            }
        }

        st.push(u);
    }

public:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(adj, i, visited, st);
            }
        }

        vector<int> result;
        while (!st.empty())
        {
            result.push_back(st.top());
            st.pop();
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
