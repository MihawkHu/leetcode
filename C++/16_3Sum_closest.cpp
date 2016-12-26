class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 0;
        if (nums.size() <= 3) {
            for (int i = 0; i < nums.size(); ++i) {
                ans += nums[i];
            }
            return ans;
        }
        ans = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        int last_value = nums[0];
        for (int k = 0; k < nums.size()-2; ++k) {
            if (k != 0 && nums[k] == last_value) continue;
            int i = k+1, j = nums.size()-1, tt = nums[k];
            while (i < j) {
                if (nums[i] + nums[j] + tt == target) {
                    return target;
                }
                else if (nums[i] + nums[j] + tt < target) {
                    if (abs(nums[i] + nums[j] + tt - target) < abs(target - ans)) {
                        ans = nums[i] + nums[j] + tt;
                    }
                    ++i;
                }
                else {
                    if (abs(nums[i] + nums[j] + tt - target) < abs(target - ans)) {
                        ans = nums[i] + nums[j] + tt;
                    }
                    --j;
                }
            }
            last_value = nums[k];
            
        }
        return ans;
    }
};
