#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> result(V, INT_MAX);

        result[S] = 0;
        pq.push(make_pair(0, S));

        while (!pq.empty())
        {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (vector<int> vec : adj[node])
            {
                int adjNode = vec[0];
                int wt = vec[1];

                if (d + wt < result[adjNode])
                {
                    result[adjNode] = d + wt;
                    pq.push(make_pair(result[adjNode], adjNode));
                }
            }
        }

        return result;
    }
};

int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj[V];
    cout << "Enter the edges (u v w) where u and v are vertices and w is the weight:" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v >> w;
        adj[u].push_back(vector<int>{v, w});
        adj[v].push_back(vector<int>{u, w}); // Uncomment this line if the graph is undirected
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    Solution sol;
    vector<int> distances = sol.dijkstra(V, adj, source);

    cout << "Shortest distances from vertex " << source << ":" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << "Vertex " << i << ": " << distances[i] << endl;
    }

    return 0;
}
