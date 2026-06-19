class Solution {
public:
    int memoization(int m, int n, vector<vector<int>>& dp){
        if(m == 1 && n == 1){return 1;}
        if(m <= 0 || n <= 0){return 0;}

        if(dp[m][n] != -1) return dp[m][n];
        dp[m][n] = memoization(m-1,n,dp) + memoization(m,n-1,dp);
        return dp[m][n];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        return memoization(m,n,dp);
    }
};
