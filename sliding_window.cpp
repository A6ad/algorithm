#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n = arr.size();
        int curr_sum = 0;
        int start = 0;
        vector<int> result;

        for (int end = 0; end < n; end++) {
            curr_sum += arr[end];

            while (curr_sum > target && start <= end) {
                curr_sum -= arr[start];
                start++;
            }

            if (curr_sum == target) {
                result.push_back(start + 1);
                result.push_back(end + 1);
                return result;
            }
        }

        return {-1};
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 7, 5};
    int target = 12;
    vector<int> result = sol.subarraySum(arr, target);

    if (result.size() == 2) {
        cout << "Subarray found from index " << result[0] << " to " << result[1] << endl;
    } else {
        cout << "No subarray found" << endl;
    }

    return 0;
}