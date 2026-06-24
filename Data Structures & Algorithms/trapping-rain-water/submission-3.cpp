class Solution {
public:
    int trap(vector<int>& height) {
        int L = 0, R = height.size()-1;
        int Lmax = INT_MIN, Rmax = INT_MIN;
        int ans = 0;
        while(L <= R){
            if(height[L] <= height[R]){
                if(Lmax < height[L]){
                    Lmax = height[L];
                }else{
                    ans += Lmax - height[L];
                }
                L++;
            }else{
                if(Rmax < height[R]){
                    Rmax = height[R];
                }else{
                    ans += Rmax - height[R];
                }
                R--;
            }
        }
        return ans;
    }
};
