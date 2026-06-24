class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int x = 0;
        while(x < nums.size()){
            int y = x + 1, z = nums.size()-1;
            while(y < z){
                int here = nums[x] + nums[y] + nums[z];
                if(here == 0){
                    ans.push_back({nums[x], nums[y], nums[z]});
                    y++; z--;
                    while(y < nums.size() && nums[y] == nums[y-1]){
                        y++;
                    }
                    while(z >= 0 && nums[z] == nums[z+1]){
                        z--;
                    }
                }else if(here > 0) z--;
                else y++;
            }
            x++;
            while(x < nums.size() && nums[x] == nums[x-1]){
                x++;
            }
        }

        return ans;
    }
};
