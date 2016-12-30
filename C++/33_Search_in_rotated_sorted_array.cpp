class Solution {
public:
    int find(vector<int> nums, int s, int t, int target, bool flag) {
        if (s >= t) return -1;
        int mid = (s+t-1)>>1;
        if (nums[mid] == target) return mid;
        if (flag) {
            if (target < nums[s] || target > nums[t-1]) return -1;
            if (target < nums[mid]) return find(nums, s, mid, target, true);
            if (target > nums[mid]) return find(nums, mid+1, t, target, true);
        }
        else {
            if (nums[s] <= nums[mid]) {
                if (target >= nums[s] && target < nums[mid]) return find(nums, s, mid, target, true);
                else return find(nums, mid+1, t, target, false);
            }
            else {
                if (target > nums[mid] && target <= nums[t-1]) return find(nums, mid+1, t, target, true);
                else return find(nums, s, mid, target, false);
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        return find(nums, 0, nums.size(), target, false);
    }
};
