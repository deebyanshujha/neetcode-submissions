class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int ans = 0;
        for(auto it: nums){
            if(st.find(it-1) == st.end()){
                int curr = it+1;
                int len = 1;
                while(st.find(curr) != st.end()){
                    len++;
                    curr++;
                }
                ans = max(ans,len);
            }
        }
        return ans;
    }
};
