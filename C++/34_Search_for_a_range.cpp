class Solution {
public:
    int find(vector<int>& nums, int s, int t, int target) {
        if (s >= t) return -1;
        if (target < nums[s] || target > nums[t-1]) return -1;
        int mid = (s+t-1)>>1;
        if (nums[mid] == target) return mid;
        else if (target < nums[mid]) return find(nums, s, mid, target);
        else return find(nums, mid+1, t, target);
    }
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int idx = find(nums, 0, nums.size(), target);
        if (idx == -1) {
            ans.push_back(-1);
            ans.push_back(-1);
        }
        else {
            int i = idx, j = idx;
            while (i >= 0 && nums[i] == target) --i;
            while (j < nums.size() && nums[j] == target) ++j;
            ans.push_back(++i);
            ans.push_back(--j);
        }
        return ans;
    }
};
