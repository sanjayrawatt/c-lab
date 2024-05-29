#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    int solve(int n, vector<int> &dp)
    {
        if (n <= 1)
            return n;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }

public:
    int fib(int n)
    {
        if (n <= 1)
            return n;

        vector<int> dp(n + 1, -1);

        return solve(n, dp);
    }
};

int main()
{
    Solution solution;

    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Fibonacci number at position " << n << " is: " << solution.fib(n) << endl;

    return 0;
}
