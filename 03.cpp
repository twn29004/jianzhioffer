// 该题得目标是找出重复数字，可以使用类似于桶排序得思想可以在O(N)得复杂度内解决，但是空间复杂度也是O(N),
// 如果需要统计所有得数字重复得话，可以考虑使用unorderedmap或者unorderedset来实现
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        vector<bool> flags;
        for(int i = 0; i < nums.size(); i ++) {
            flags.push_back(false);
        }
        for(int i = 0; i < nums.size(); i ++) {
            if(!flags[nums[i]]) {
                flags[nums[i]]  =true;
            } else {
                return nums[i];
            }
        }
        return -1;
    }
};


// 使用unordered_set<int>这一数据结构来实现，但是好像效果不是很明显
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> intSet;
        for(int i = 0; i < nums.size(); i ++) {
            if(intSet.find(nums[i]) != intSet.end()) {
                return nums[i];
            } else {
                intSet.insert(nums[i]);
            }
        }
        return -1;
    }
};