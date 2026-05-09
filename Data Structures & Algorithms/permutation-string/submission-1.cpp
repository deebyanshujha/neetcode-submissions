class Solution {
public:
    bool match(vector<int>& hash, vector<int>& r_hash){
        for(int i = 0; i<26; i++){
            if(hash[i] != r_hash[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        vector<int> hash(26,0);
        for(auto it : s1){
            hash[it - 97]++;
        }
        vector<int> r_hash(26,0);
        int i = 0, j = 0;
        while(j < s2.length()){
            r_hash[s2[j] - 97]++;
            if(j - i + 1 > s1.length()){
                r_hash[s2[i] - 97]--;
                i++;
            }if(j - i + 1 == s1.length()){
                bool val = match(hash,r_hash);
                if(val) return true;
            }
            j++;
        }
        return false;
    }
};
