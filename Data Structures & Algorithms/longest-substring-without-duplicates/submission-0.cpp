class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        unordered_set<char> st;
        int ans = 0;
        while(j < s.length()){
            if(st.empty() || st.find(s[j]) == st.end()){
                st.insert(s[j]);
                ans = max(ans, j - i + 1);
            }else{
                while(i < j && s[i] != s[j]){
                    st.erase(s[i]);
                    i++;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};
