class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        while(i <= j){
            int mid = (i+j)/2;
            if(nums[mid] == target) return mid;
            else{
                if(nums[i] > nums[j] && target > nums[nums.size()-1]){
                    j--;
                }else if(nums[i] > nums[j] && target <= nums[nums.size()-1]){
                    i++;
                }else if(nums[i] < nums[j] && target < nums[mid]){
                    j = mid-1;
                }else{
                    i = mid+1;
                }
            }
        }
        return -1;
    }
};
