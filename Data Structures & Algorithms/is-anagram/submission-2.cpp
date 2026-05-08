class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> hash(26,0);
        for(auto it: s){
            hash[it - 97] += 1;
        }
        for(auto it: t){
            if(hash[it - 97] == 0) return false;
            hash[it - 97] -= 1;
        }
        return true;
    }
};
