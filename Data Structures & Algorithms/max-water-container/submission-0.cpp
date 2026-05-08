class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size()-1;
        int ans = 0;
        while(i < j){
            int amt = (j-i)*min(heights[i],heights[j]);\
            ans = max(ans, amt);
            if(heights[i] >= heights[j]){
                j--;
            }else{
                i++;
            }
        }
        return ans;
    }
};
