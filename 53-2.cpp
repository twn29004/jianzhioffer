class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        for(; i < nums.size(); i ++) {
            if(nums[i] != i) {
                break;
            }
        }
        return i;
    }
};

// 以上方法的复杂度为O(N),由于已经排好序了，考虑使用二分法看能不能解决。