class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> hsmp;
        
        for (int i = 0; i < strs.size(); ++i) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            hsmp[temp].push_back(strs[i]);
        }
        
        vector<vector<string>> ans(hsmp.size());
        int k = 0;
        map<string, vector<string>>::iterator iter = hsmp.begin();
        for (; iter != hsmp.end(); ++iter, ++k) {
            ans[k].swap(iter->second);
            sort(ans[k].begin(), ans[k].end());
        }
        return ans;
    }
};
