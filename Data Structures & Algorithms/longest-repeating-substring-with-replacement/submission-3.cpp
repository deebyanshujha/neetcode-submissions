class Solution {
public:
    
    int characterReplacement(string s, int k) {
        vector<int> hash(26,0);
        int ans = 0;
        int l = 0, r = 0;
        while(r < s.size()){
            hash[s[r] - 'A']++;
            int max_freq = *max_element(hash.begin(), hash.end());
            int replacements = (r-l+1) - max_freq;
            if(replacements <= k) ans = max(ans, (r-l+1));
            else{
                while(l <= r){
                    hash[s[l] - 'A']--;
                    l++;
                    int max_freq = *max_element(hash.begin(), hash.end());
                    int replacements = (r-l+1) - max_freq;
                    if(replacements <= k) break;
                    
                }
                ans = max(ans, (r-l+1));
            }
            r++;
        }
        return ans;
    }
};
