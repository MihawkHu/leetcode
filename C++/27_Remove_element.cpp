class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = 0, length = nums.size();
        for (int i = 0; i < length; ++i){
            if (nums[i] != val) {
                nums[size++] = nums[i];
            }
        }
        return size;
    }
};
