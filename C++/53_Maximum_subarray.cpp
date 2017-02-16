class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> sum(nums.size());
        sum[nums.size()-1] = nums[nums.size()-1];
        int ans = sum[nums.size()-1];
        for (int i = nums.size() - 2; i >= 0; --i) {
            sum[i] = max(nums[i], nums[i] + sum[i + 1]);
            ans = max(sum[i], ans);
        }
        return ans;
    }
};
