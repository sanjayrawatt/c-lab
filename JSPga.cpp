#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job
{
    int id;
    int dead;
    int profit;
};

class Solution
{
public:
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, [](Job a, Job b)
             { return a.profit > b.profit; });

        int maxDeadline = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i].dead > maxDeadline)
            {
                maxDeadline = arr[i].dead;
            }
        }

        vector<int> timeline(maxDeadline + 1, -1);

        int countJobs = 0;
        int maxProfit = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j > 0; j--)
            {
                if (timeline[j] == -1)
                {
                    timeline[j] = arr[i].id;
                    countJobs++;
                    maxProfit += arr[i].profit;
                    break;
                }
            }
        }

        return {countJobs, maxProfit};
    }
};

int main()
{
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    Job arr[n];
    cout << "Enter the job details (id, deadline, profit):" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].id >> arr[i].dead >> arr[i].profit;
    }

    Solution solution;
    vector<int> result = solution.JobScheduling(arr, n);

    cout << "Number of jobs done: " << result[0] << endl;
    cout << "Maximum profit: " << result[1] << endl;

    return 0;
}
