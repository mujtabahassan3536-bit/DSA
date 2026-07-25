#include <iostream>
#include <algorithm>
using namespace std;

int maxSumSubarray(int arr[], int n, int k)
{
    int sum = 0;

    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }

    int maxSum = sum;

    for (int i = k; i < n; i++)
    {
        sum = sum - arr[i - k] + arr[i];
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

int main()
{
    int arr[] = {2, 1, 5, 1, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    cout << "Maximum Sum: " << maxSumSubarray(arr, n, k);

    return 0;
}
