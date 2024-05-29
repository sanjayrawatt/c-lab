#include <iostream>
#include <string>
#include <cstring> // for memset

using namespace std;

class Solution
{
public:
    int dp[1001][1001];
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.length();
        int m = text2.length();
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
};

int main()
{
    Solution solution;

    string text1, text2;
    cout << "Enter the first string: ";
    cin >> text1;
    cout << "Enter the second string: ";
    cin >> text2;

    int lcsLength = solution.longestCommonSubsequence(text1, text2);
    cout << "Length of the longest common subsequence: " << lcsLength << endl;

    return 0;
}
