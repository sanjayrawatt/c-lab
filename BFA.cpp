#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution
{
public:
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        vector<int> result(V, 1e8);
        result[S] = 0;

        for (int i = 0; i < V - 1; i++)
        {
            for (auto &edge : edges)
            {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                if (result[u] != 1e8 && result[u] + wt < result[v])
                {
                    result[v] = result[u] + wt;
                }
            }
        }

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (result[u] != 1e8 && result[u] + wt < result[v])
            {
                return {-1};
            }
        }

        return result;
    }
};

int main()
{
    int V, E, S;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> edges(E, vector<int>(3));
    cout << "Enter the edges (source destination weight):" << endl;
    for (int i = 0; i < E; ++i)
    {
        cout << "Edge " << i + 1 << ": ";
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    cout << "Enter the source vertex: ";
    cin >> S;

    Solution sol;
    vector<int> result = sol.bellman_ford(V, edges, S);

    if (result[0] == -1)
    {
        cout << "Graph contains a negative weight cycle" << endl;
    }
    else
    {
        cout << "Vertex distances from source vertex " << S << ":" << endl;
        for (int i = 0; i < V; ++i)
        {
            if (result[i] == 1e8)
            {
                cout << "Vertex " << i << ": INF" << endl;
            }
            else
            {
                cout << "Vertex " << i << ": " << result[i] << endl;
            }
        }
    }

    return 0;
}
