class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4) return ans;
        sort(nums.begin(), nums.end());
        int last_value_1 = nums[0];
        int last_value_2 = nums[1];
        
        for (int k = 0; k < nums.size()-3; ++k) {
            if (k != 0 && nums[k] == last_value_1) continue;
            for (int t = k+1; t < nums.size()-2; ++t) {
                if (t != k+1 && nums[t] == last_value_2) continue;
                int i = t+1, j = nums.size()-1;
                while (i < j) {
                    if (nums[i] + nums[j] + nums[k] + nums[t] == target) {
                        vector<int> temp = {nums[k], nums[t], nums[i], nums[j]};
                        ans.push_back(temp);
                        ++i;  --j;
                    }
                    else if (nums[i] + nums[j] + nums[k] + nums[t] < target) {
                        ++i;
                    }
                    else {
                        --j;
                    }
                }
                last_value_2 = nums[t];
            }
            last_value_1 = nums[k];
        }
        
        vector<vector<int>>::iterator iter = unique(ans.begin(), ans.end());
        if (iter != ans.end()) {
            ans.erase(iter, ans.end());
        }
        return ans;
    }
};
