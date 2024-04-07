class Solution {
public:

    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {

        long ans = 0;

        sort(nums.begin(), nums.end());
        int med = nums[nums.size() / 2];

        if (med != k) {
            ans += abs(k - med);
        }

        if (k > med) {
            for (int i = nums.size() / 2 + 1; i <= nums.size() - 1; i++) {
                if (nums[i] < k) {
                    ans += abs(k - nums[i]);
                } else {
                    break;
                }
            }

        } else if (k < med) {
            for (int i = nums.size() / 2 - 1; i >= 0; i--) {
                if (nums[i] > k) {
                    ans += abs(k - nums[i]);
                } else {
                    break;
                }
            }
        }

        return ans;
    }
};