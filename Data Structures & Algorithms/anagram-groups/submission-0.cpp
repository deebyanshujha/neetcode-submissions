class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> mp;
        for(int i = 0;i<strs.size();i++){
            vector<int> hash(26,0);
            for(auto it : strs[i]){
                hash[it-97]++;
            }
            mp[hash].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
