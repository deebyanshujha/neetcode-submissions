class Solution {
public:
    int trap(vector<int>& height) {
        int left_max = INT_MIN;
        int l = 0;
        int right_max = INT_MIN;
        int r = height.size()-1;
        int ans = 0;
        while(l < r){
            if(height[l] <= height[r]){
                if(left_max < height[l]){
                    left_max = height[l];
                }else{
                    ans += left_max - height[l];
                }
                l++;
            }else{
                if(right_max < height[r]){
                    right_max = height[r];
                }else{
                    ans += right_max - height[r];
                }
                r--;
            }
        }
        return ans;
    }
};
