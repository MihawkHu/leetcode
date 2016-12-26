class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() < 3) return ans;
        sort(nums.begin(), nums.end());
        int last_value = nums[0];
        for (int k = 0; k < nums.size()-2; ++k) {
            if (k != 0 && nums[k] == last_value) continue;
            int i = k+1, j = nums.size()-1, tt = nums[k];
            while (i < j) {
                if (nums[i] + nums[j] + tt == 0) {
                    vector<int> temp = {tt, nums[i], nums[j]};
                    ans.push_back(temp);
                    ++i;  --j;
                }
                else if (nums[i] + nums[j] + tt < 0) {
                    ++i;
                }
                else {
                    --j;
                }
            }
            last_value = nums[k];
            
        }
        vector<vector<int>>::iterator iter = unique(ans.begin(), ans.end());
        if (iter != ans.end()) {
            ans.erase(iter, ans.end());
        }
        return ans;
    }
};
