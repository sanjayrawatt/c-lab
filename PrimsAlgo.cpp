#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int sum = 0;
        pq.push({0, 0});

        vector<bool> inMST(V, false);

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int wt = it.first;
            int node = it.second;

            if (inMST[node])
                continue;

            inMST[node] = true;
            sum += wt;

            for (auto v : adj[node])
            {
                int neig = v[0];
                int wwt = v[1];

                if (!inMST[neig])
                    pq.push({wwt, neig});
            }
        }

        return sum;
    }
};

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> adj[V];
    cout << "Enter each edge with its weight (format: u v w):" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    Solution sol;
    int result = sol.spanningTree(V, adj);
    cout << "Sum of weights of edges of the Minimum Spanning Tree is: " << result << endl;

    return 0;
}
