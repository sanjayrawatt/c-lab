#include <iostream>
#include <string>
#include <cstring> // for memset

using namespace std;

class Solution
{
    int dp[1001][1001];
    int solve(string &s1, string &s2, int n, int m, int i, int j)
    {
        if (i >= n || j >= m)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j])
            return dp[i][j] = solve(s1, s2, n, m, i + 1, j + 1) + 1;
        else
            return dp[i][j] = max(solve(s1, s2, n, m, i + 1, j), solve(s1, s2, n, m, i, j + 1));
    }

public:
    int longestCommonSubsequence(string s1, string s2)
    {
        int n = s1.length();
        int m = s2.length();

        if (n == 0 || m == 0)
            return 0;

        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, n, m, 0, 0);
    }
};

int main()
{
    Solution solution;

    string s1, s2;
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;

    int lcsLength = solution.longestCommonSubsequence(s1, s2);
    cout << "Length of the longest common subsequence: " << lcsLength << endl;

    return 0;
}
