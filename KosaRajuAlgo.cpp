#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
    void dfsTopo(vector<vector<int>> &adj, int u, vector<bool> &visited, stack<int> &st)
    {
        visited[u] = true;

        for (auto v : adj[u])
        {
            if (!visited[v])
            {
                dfsTopo(adj, v, visited, st);
            }
        }

        st.push(u);
    }

    void dfs(vector<vector<int>> &adjReverse, int u, vector<bool> &visited)
    {
        visited[u] = true;

        for (auto v : adjReverse[u])
        {
            if (!visited[v])
            {
                dfs(adjReverse, v, visited);
            }
        }
    }

public:
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        vector<bool> visited(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfsTopo(adj, i, visited, st);
            }
        }

        vector<vector<int>> adjReverse(V);
        for (int u = 0; u < V; u++)
        {
            for (auto v : adj[u])
            {
                adjReverse[v].push_back(u);
            }
        }

        visited = vector<bool>(V, false);
        int count = 0;

        while (!st.empty())
        {
            int u = st.top();
            st.pop();

            if (!visited[u])
            {
                dfs(adjReverse, u, visited);
                count++;
            }
        }

        return count;
    }
};

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "Enter the edges (u v) where u -> v:" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v;
        adj[u].push_back(v);
    }

    Solution solution;
    int result = solution.kosaraju(V, adj);

    cout << "The number of strongly connected components is: " << result - 1 << endl; // total count of SCC is showing one more thats why we are substeracting by 1 at the end

    return 0;
}
