class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> a(m, vector<int>(n));
        if (obstacleGrid[m-1][n-1] == 1) return 0;
        if (m == 1 && n == 1) return 1;
        else a[m-1][n-1] = 0;
        if (n-2 >= 0)
            if (obstacleGrid[m-1][n-2] == 1) a[m-1][n-2] = 0;
            else a[m-1][n-2] = 1;
        if (m-2 >= 0)
            if (obstacleGrid[m-2][n-1] == 1) a[m-2][n-1] = 0;
            else a[m-2][n-1] = 1;
        
        for (int i = m-1; i >= 0; --i) {
            for (int j = n-1; j >= 0; --j) {
                if (obstacleGrid[i][j] == 1) continue;
                if (i != 0 && obstacleGrid[i-1][j] != 1) a[i-1][j] += a[i][j];
                if (j != 0 && obstacleGrid[i][j-1] != 1) a[i][j-1] += a[i][j];
            }
        }
        return a[0][0];
    }
};
