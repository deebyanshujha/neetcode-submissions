class Solution {
public:
    bool recurse(int current, int total_sum, int i, vector<int>& nums, vector<vector<int>>& dp){
        if(i >= nums.size()){
            if((total_sum / 2) == current) return true;
            return false;
        }
        if(dp[current][i] != -1) return dp[current][i];
        return dp[current][i] =  recurse(current+nums[i], total_sum,i+1,nums,dp) || recurse(current,total_sum,i+1,nums,dp);
    }
    bool canPartition(vector<int>& nums) {
        int total_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            total_sum += nums[i];
        }
        if(total_sum % 2 != 0) return false;
        vector<vector<int>> dp(total_sum, vector<int>(nums.size(),-1));
        return recurse(0,total_sum,0,nums,dp);
    }
};
