class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0;
        vector<vector<int>> ans;
        while(i < nums.size()){
            int j = i+1, k = nums.size()-1;
            while(j < k){
                int add = nums[i] + nums[j] + nums[k];
                if(add == 0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++; k--;
                    while(j < nums.size() && nums[j] == nums[j-1]) j++;
                    while(k >= 0 && nums[k] == nums[k+1]) k--;
                }else if(add > 0){
                    k--;
                }else{
                    j++;
                }
            }
            i++;
            while(i < nums.size() && nums[i] == nums[i-1]) i++;
        }
        return ans;
    }
};
