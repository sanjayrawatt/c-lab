#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

class Solution
{
    int solve(int arr[], int i, int j)
    {
        if (i >= j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int mini = INT_MAX;

        for (int k = i; k <= j - 1; k++)
        {
            int temp = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];

            if (mini > temp)
                mini = temp;
        }

        return dp[i][j] = mini;
    }

public:
    int dp[501][501];
    int matrixMultiplication(int N, int arr[])
    {
        int i = 1;
        int j = N - 1;
        memset(dp, -1, sizeof(dp));
        return solve(arr, i, j);
    }
};

int main()
{
    Solution solution;

    int N;
    cout << "Enter the number of matrices: ";
    cin >> N;

    int arr[N + 1];
    cout << "Enter the dimensions of matrices:" << endl;
    for (int i = 0; i <= N; ++i)
    {
        cin >> arr[i];
    }

    int minScalarMultiplications = solution.matrixMultiplication(N, arr);
    cout << "Minimum number of scalar multiplications needed: " << minScalarMultiplications << endl;

    return 0;
}
