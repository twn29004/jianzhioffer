class Solution {
public:

    int binarysearch(vector<int>& nums, int left, int right, int target) {
        if(left >= right) {
            // 无论什么时候对数组进行访问，都需要对非法访问进行判断
            if(left < nums.size() && nums[left] == target) {
                return left;
            } else {
                return -1;
            }
        }
        int mid = (left + right) / 2;
        if(nums[mid] == target) {
            return binarysearch(nums, left, mid, target);
        } else {
            if(nums[mid] > target)
                return binarysearch(nums, left, mid - 1, target);
            } else {
                return binarysearch(nums, mid + 1, right, target);
            }
        }
        return -1;           
    }
    int search(vector<int>& nums, int target) {
        // 由于是排序数组，可以使用折半查找的方法
        int loc = binarysearch(nums, 0, nums.size() - 1, target);
        if(loc == -1) {
            return 0;
        }
        int res = 0;
        while(loc < nums.size() && nums[loc] == target) {
            res ++;
            loc ++;
        }
        return res;
    }
};