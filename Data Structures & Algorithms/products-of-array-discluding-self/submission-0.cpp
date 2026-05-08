class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size());
        vector<int> postfix(nums.size());
        int pre = 1;
        for(int i = 0;i<nums.size();i++){
            prefix[i] = pre;
            pre *= nums[i];
        }
        int post = 1;
        for(int i = nums.size()-1;i>=0;i--){
            postfix[i] = post;
            post *= nums[i];
        }
        vector<int> ans(nums.size());
        for(int i = 0;i<nums.size();i++){
            ans[i] = prefix[i] * postfix[i];
        }
        return ans;
    }
};
