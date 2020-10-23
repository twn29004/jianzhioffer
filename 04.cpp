
// 本题考虑得是由于已经排好序了，肯定使用二分法来查找，但是由于二分法只适用于一维数组，
// 本题中使用得是先利用已经有序这一条件，来寻找满足条件得行进行二分查找，时间复杂度为O(n*log(n))
// 不知道还有没有更加优化的写法
class Solution {
public:

    bool binarySearch(vector<int>& nums, int target, int left, int right) {
        if(left >= right) {
            return left < nums.size() && nums[left] == target;
        }
        int mid = (left + right) / 2;
        if(target == nums[mid]) {
            return true;
        }
        if(target < nums[mid]) {
            return binarySearch(nums, target, left, mid - 1);
        } else {
            return binarySearch(nums, target, mid + 1, right);
        }
    }
    
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        // 看能不能再nlog(n)这个时间内解决问题，但是感觉还是不太行啊
        // 先确定一个小范围
        for(int i = 0; i < matrix.size(); i ++) {
            if(matrix[i].size() > 0 && matrix[i][0] <= target && matrix[i][matrix[i].size() - 1] >= target) {
                if(binarySearch(matrix[i], target, 0, matrix[i].size() - 1)) {
                    return true;
                }
            }
        }
        return false;
    }
};

// 确实有更好的方法，站在矩阵的右上角看，整个矩阵就是一个二叉搜索树，接下来就好办了
class Solution {
public:

    // 首先我们要能够明白，二维数组中的任何位置，都可以从右上角的使用左和下这两个组合来实现
    bool Search(vector<vector<int>>& matrix, int target, int row, int cloumn) {
        if(row >= matrix.size() || cloumn < 0) {
            return false;
        }
        if(target == matrix[row][cloumn]) {
            return true;
        }
        if(target > matrix[row][cloumn]) {
            // 向下走
            return Search(matrix, target, row + 1, cloumn);
        }
        if(target < matrix[row][cloumn]) {
            return Search(matrix, target, row, cloumn - 1);
        }
        return false;
        
    }
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() > 0 && matrix[0].size() > 0) {
            return Search(matrix, target, 0, matrix[0].size() - 1);
        }
        return false;
    }
};