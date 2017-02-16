class Solution {
public:
    void backtrack(vector<vector<string>> *ans, vector<string> cur, int layer, int n){
        if (layer == n) {
            ans->push_back(cur);
            return;
        }
        for (int i = 0; i < n; ++i) {
            bool flag = false;
            for (int j = layer - 1, k = 1; j >= 0; --j, ++k) {
                if (cur[j][i] == 'Q') {
                    flag = true;
                    break;
                }
                if (i + k < n && cur[j][i + k] == 'Q') {
                    flag = true;
                    break;
                }
                if (i - k >= 0 && cur[j][i - k] == 'Q') {
                    flag = true;
                    break;
                }
            }
            
            if (flag) continue;
            cur[layer][i] = 'Q';
            backtrack(ans, cur, layer+1, n);
            cur[layer][i] = '.';
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');
        vector<string> cur(n, s);
        vector<vector<string>> ans;
        backtrack(&ans, cur, 0, n);
        return ans;
    }
};
