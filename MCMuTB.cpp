#include <iostream>
#include <climits>

using namespace std;

class Solution
{
public:
    int matrixMultiplication(int N, int arr[])
    {
        int dp[N][N];

        // Initialize dp array
        for (int i = 0; i < N; ++i)
        {
            dp[i][i] = 0;
        }

        // Iterate over the chain length
        for (int chainLength = 2; chainLength < N; ++chainLength)
        {
            for (int i = 1; i < N - chainLength + 1; ++i)
            {
                int j = i + chainLength - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k <= j - 1; ++k)
                {
                    int temp = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                    dp[i][j] = min(dp[i][j], temp);
                }
            }
        }

        return dp[1][N - 1];
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
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    int minScalarMultiplications = solution.matrixMultiplication(N, arr);
    cout << "Minimum number of scalar multiplications needed: " << minScalarMultiplications << endl;

    return 0;
}
