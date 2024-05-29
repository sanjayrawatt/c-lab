#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int knapSack(int W, int wt[], int val[], int n)
    {
        int dp[n + 1][W + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (wt[i - 1] <= j)
                {
                    dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][W];
    }
};

int main()
{
    Solution solution;

    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    int val[n], wt[n];
    cout << "Enter the values of items:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> val[i];
    }
    cout << "Enter the weights of items:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> wt[i];
    }

    int W;
    cout << "Enter the maximum weight of knapsack: ";
    cin >> W;

    int maxValue = solution.knapSack(W, wt, val, n);
    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}
