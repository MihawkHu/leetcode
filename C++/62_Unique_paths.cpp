class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        vector<vector<int>> a(m, vector<int>(n, 0));
        a[m-1][n-1] = 0;
        a[m-1][n-2] = 1;
        a[m-2][n-1] = 1;
        for (int i = m-1; i >= 0; --i) {
            for (int j = n-1; j >= 0; --j) {
                if (i != 0) a[i-1][j] += a[i][j];
                if (j != 0) a[i][j-1] += a[i][j];
            }
        }
        return a[0][0];
    }
};
