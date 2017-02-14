class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tt;
    void trace(vector<int>& nums, vector<bool> flag, int n) {
        if (n == nums.size()) {
            ans.push_back(tt);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (flag[i]) continue;
            flag[i] = true;
            tt.push_back(nums[i]);
            trace(nums, flag, n+1);
            flag[i]=false;
            tt.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 0) return ans;
        vector<bool> flag(nums.size(), false);
        trace(nums, flag, 0);
        return ans;
    }
};
