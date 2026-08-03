#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    mp[0] = 1;

    int currentSum = 0;
    int answer = 0;

    for (int i = 0; i < nums.size(); i++) {
        currentSum += nums[i];

        int required = currentSum - k;

        answer += mp[required];

        mp[currentSum]++;
    }

    return answer;
}

int main() {
    vector<int> nums = {1, -1, 1, -1, 1};
    int k = 0;

    cout << subarraySum(nums, k);

    return 0;
}
