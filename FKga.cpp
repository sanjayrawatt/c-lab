#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Item
{
    int value;
    int weight;
};

class Solution
{
public:
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        vector<pair<double, int>> valuePerWeight;
        for (int i = 0; i < n; ++i)
        {
            valuePerWeight.push_back({(double)arr[i].value / arr[i].weight, i});
        }
        sort(valuePerWeight.rbegin(), valuePerWeight.rend());

        double totalValue = 0.0;
        int currentWeight = 0;

        for (int i = 0; i < n; ++i)
        {
            int itemIndex = valuePerWeight[i].second;
            if (currentWeight + arr[itemIndex].weight <= w)
            {
                totalValue += arr[itemIndex].value;
                currentWeight += arr[itemIndex].weight;
            }
            else
            {
                int remainingWeight = w - currentWeight;
                totalValue += (double)arr[itemIndex].value / arr[itemIndex].weight * remainingWeight;
                break;
            }
        }

        return totalValue;
    }
};

int main()
{
    int n, w;
    cout << "Enter the number of items: ";
    cin >> n;

    Item arr[n];
    cout << "Enter the weight and value of each item:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i].weight >> arr[i].value;
    }

    cout << "Enter the maximum weight of knapsack: ";
    cin >> w;

    Solution solution;
    double maxValue = solution.fractionalKnapsack(w, arr, n);
    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}
