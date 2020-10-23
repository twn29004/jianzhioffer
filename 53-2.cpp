// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int i = 0;
//         for(; i < nums.size(); i ++) {
//             if(nums[i] != i) {
//                 break;
//             }
//         }
//         return i;
//     }
// };

// 以上方法的复杂度为O(N),由于已经排好序了，考虑使用二分法看能不能解决。

class Solution {
public:
    int binarSearch(vector<int>& nums, int left, int right) {
        if(left >= right) {
            if(left < nums.size() && nums[left] != left) {
                return left;
            } else {
                return nums.size();
            }
        }
        int mid = (left + right) / 2;
        if(mid != nums[mid]) {
            return binarSearch(nums, left, mid);
        } else {
            return binarSearch(nums, mid + 1, right);
        }
    }

    int missingNumber(vector<int>& nums) {
        return binarSearch(nums, 0, nums.size() - 1);
    }
};

// 以上方法使用的是二分法进行查找，时间复杂度为O(log(N)),可能由于数据量较小，在提交的效果上提升并不是很明显。