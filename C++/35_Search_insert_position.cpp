class Solution {
public:
    int find(vector<int>& nums, int s, int t, int target) {
        if (s >= t) return s+1;
        if (target < nums[s]) return s;
        if (target > nums[t-1]) return t;
        int mid = (s+t-1)>>1;
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) return find(nums, s, mid, target);
        else return find(nums, mid+1, t, target);
        
    }
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
        return find(nums, 0, nums.size(), target);
    }
};
