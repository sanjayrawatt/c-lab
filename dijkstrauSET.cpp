#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int, int>> st;
        vector<int> result(V, INT_MAX);

        result[S] = 0;
        st.insert({0, S});

        while (!st.empty())
        {
            auto it = *st.begin();
            st.erase(it);
            int d = it.first;
            int node = it.second;

            for (auto vec : adj[node])
            {
                int adjNode = vec[0];
                int wt = vec[1];

                if (d + wt < result[adjNode])
                {
                    if (result[adjNode] != INT_MAX)
                    {
                        st.erase({result[adjNode], adjNode});
                    }
                    result[adjNode] = d + wt;
                    st.insert({result[adjNode], adjNode});
                }
            }
        }

        return result;
    }
};

int main()
{
    int V, E, source;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> adj[V];

    cout << "Enter the edges (u, v, w) where u and v are vertices and w is the weight:\n";
    for (int i = 0; i < E; ++i)
    {
        int u, v, w;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // Uncomment the next line if the graph is undirected
        adj[v].push_back({u, w});
    }

    cout << "Enter the source vertex: ";
    cin >> source;

    Solution sol;
    vector<int> result = sol.dijkstra(V, adj, source);

    cout << "The shortest distances from source " << source << " are:\n";
    for (int i = 0; i < V; ++i)
    {
        if (result[i] == INT_MAX)
        {
            cout << "Vertex " << i << ": INF\n";
        }
        else
        {
            cout << "Vertex " << i << ": " << result[i] << "\n";
        }
    }

    return 0;
}
