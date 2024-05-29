// activity selection use greedy algorithm

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int, int>> activities;
        for (int i = 0; i < n; i++)
        {
            activities.push_back({end[i], start[i]});
        }

        sort(activities.begin(), activities.end());

        int count = 1;
        int lastEndTime = activities[0].first;

        for (int i = 1; i < n; i++)
        {
            if (activities[i].second > lastEndTime)
            {
                count++;
                lastEndTime = activities[i].first;
            }
        }

        return count;
    }
};

int main()
{
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    vector<int> start(n), end(n);
    cout << "Enter the start times of the activities: ";
    for (int i = 0; i < n; i++)
    {
        cin >> start[i];
    }

    cout << "Enter the end times of the activities: ";
    for (int i = 0; i < n; i++)
    {
        cin >> end[i];
    }

    Solution solution;
    int result = solution.activitySelection(start, end, n);
    cout << "Maximum number of activities: " << result << endl;

    return 0;
}
