#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    int find(int i, vector<int> &parent)
    {
        if (i == parent[i])
            return i;
        return parent[i] = find(parent[i], parent);
    }

    void unionNode(int x, int y, vector<int> &parent, vector<int> &rank)
    {
        int parent_x = find(x, parent);
        int parent_y = find(y, parent);

        if (parent_x == parent_y)
            return;

        if (rank[parent_x] > rank[parent_y])
            parent[parent_y] = parent_x;
        else if (rank[parent_y] > rank[parent_x])
            parent[parent_x] = parent_y;
        else
        {
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }

    int kruskal(vector<vector<int>> &vec, int V)
    {
        vector<int> parent(V);
        vector<int> rank(V, 1);

        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
        }

        int sum = 0;

        for (auto temp : vec)
        {
            int u = temp[0];
            int v = temp[1];
            int wt = temp[2];

            int parent_u = find(u, parent);
            int parent_v = find(v, parent);

            if (parent_u != parent_v)
            {
                unionNode(u, v, parent, rank);
                sum += wt;
            }
        }
        return sum;
    }

public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<vector<int>> vec;

        for (int u = 0; u < V; u++)
        {
            for (auto temp : adj[u])
            {
                int v = temp[0];
                int wt = temp[1];
                vec.push_back({u, v, wt});
            }
        }

        auto comparator = [](vector<int> &vec1, vector<int> &vec2)
        {
            return vec1[2] < vec2[2];
        };

        sort(vec.begin(), vec.end(), comparator);

        return kruskal(vec, V);
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
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    Solution sol;
    int result = sol.spanningTree(V, adj);
    cout << "Sum of weights of edges of the Minimum Spanning Tree is: " << result << endl;

    return 0;
}
