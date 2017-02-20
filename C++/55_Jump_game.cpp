class Solution {
public:
    bool canJump(vector<int>& nums) {
        int length = 0;
        for (int i = 0; i <= length && length < nums.size()-1; ++i) {
            length = max(length, i + nums[i]);
        }
        if (length >= nums.size()-1) return true;
        else return false;
    }
};
