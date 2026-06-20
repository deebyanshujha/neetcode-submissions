class Solution {
public:
    int memoization(vector<int>& nums, int i, bool can, vector<vector<int>>& dp){
        if(i == nums.size()){
            return 0;
        }
        if(dp[i][can] != -1) return dp[i][can];
        int take = 0;
        if(can){
            take = nums[i] + memoization(nums,i+1,false,dp);
        }
        int not_take = memoization(nums,i+1,true,dp);
        return dp[i][can] = max(take,not_take);
    }
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2,-1));
        return memoization(nums,0,true,dp);
    }
};
