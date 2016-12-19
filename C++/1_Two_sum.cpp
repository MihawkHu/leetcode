class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int, int> hsmp;
        for (int i = 0; i < nums.size(); ++i) {
            hsmp[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            map<int, int>::iterator iter = hsmp.find(target-nums[i]);
            if (iter != hsmp.end() && i < (*iter).second) {
                res.push_back(i);
                res.push_back((*iter).second);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
