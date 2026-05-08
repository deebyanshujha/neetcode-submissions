class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i = 0;i<nums.size();i++){
            int needed = target - nums[i];
            if(mp.find(needed) != mp.end()){
                int idx = mp[needed];
                return {idx,i};
            }
            mp[nums[i]] = i;
        }
        return {-1};
    }
};
