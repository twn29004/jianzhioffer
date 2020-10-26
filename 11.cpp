class Solution {
public:

    int binarySearch(vector<int>& numbers, int left, int right) {
        if(left >= right) {
            if(left < numbers.size() && left >= 0) {
                return numbers[left];
            } else {
                return -1;
            }
        }
        int mid = (left + right) / 2;
        if(numbers[left] > numbers[mid]) {
            return binarySearch(numbers, left + 1, mid);
        }
        if(numbers[right] < numbers[mid]) {
            return binarySearch(numbers, mid + 1, right);
        }
        if(numbers[left] == numbers[mid] || numbers[right] == numbers[mid]) {
            return min(binarySearch(numbers, left, mid - 1), binarySearch(numbers, mid, right - 1));
        }
        // 到这里说明没有旋转
        return binarySearch(numbers, left, mid);
    }
    int minArray(vector<int>& numbers) {
        return binarySearch(numbers, 0, numbers.size() - 1);
    }
};