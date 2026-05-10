class Solution {
public:
    int findMin(vector<int> &nums) {
        int i = 0, j = nums.size()-1;
        while(i <= j){
            int mid = (i+j)/2;
            if(mid-1 >= 0 && nums[mid-1] > nums[mid]) return nums[mid];
            else if(nums[mid] >= nums[j]) i = mid+1;
            else j = mid-1;
        }
        return nums[0];
    }
};
