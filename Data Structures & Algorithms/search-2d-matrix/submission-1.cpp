class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowl = 0 , rowr = matrix.size()-1;
        int m = matrix.size(), n = matrix[0].size();
        int row = -1;
        while(rowl <= rowr){
            int mid = (rowl + rowr) / 2;
            if(matrix[mid][0] <= target && matrix[mid][n-1] >= target){
                row = mid;
                break;
            }else if(matrix[mid][n-1] < target) rowl = mid + 1;
            else rowr = mid - 1;
        }
        if(row == -1) return false;
        int coll = 0, colr = n-1;
        while(coll <= colr){
            int mid = (coll + colr) / 2;
            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid] > target) colr = mid-1;
            else coll = mid + 1;
        }
        return false;
    }
};
