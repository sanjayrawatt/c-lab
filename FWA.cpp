#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &grid)
    {
        int n = grid.size();

        // Replace -1 with INT_MAX to indicate no path
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == -1)
                    grid[i][j] = INT_MAX;
            }
        }

        // Floyd-Warshall algorithm
        for (int via = 0; via < n; via++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][via] != INT_MAX && grid[via][j] != INT_MAX)
                    {
                        grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
                    }
                }
            }
        }

        // Replace INT_MAX back with -1 to indicate no path
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == INT_MAX)
                    grid[i][j] = -1;
            }
        }
    }
};

int main()
{
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    cout << "Enter the adjacency matrix (use -1 to represent no direct path):" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    Solution sol;
    sol.shortest_distance(grid);

    cout << "The matrix of shortest distances between every pair of vertices is:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == -1)
                cout << "INF ";
            else
                cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
