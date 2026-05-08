class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size()-1;
        while(i < j){
            int add = numbers[i] + numbers[j];
            if(add > target) j--;
            else if(add < target) i++;
            else return {i+1,j+1};
        }
        return {-1,-1};
    }
};
