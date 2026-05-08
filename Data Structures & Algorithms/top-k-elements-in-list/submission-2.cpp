class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        for(auto it : nums){
            hash[it]++;
        }
        vector<vector<int>> bucket_sort(nums.size()+1);
        for(auto it : hash){
            bucket_sort[it.second].push_back(it.first);
        }
        vector<int> ans;
        for(int i = nums.size(); i>=0;i--){
            for(auto it: bucket_sort[i]){
                ans.push_back(it);
                if(ans.size() == k) return ans;
            }
        }
    }
};
