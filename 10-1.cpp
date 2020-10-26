class Solution {
private:
    const int M = 1e9 + 7;
public:
    int fib(int n) {
        deque<int> intDeque;
        intDeque.push_back(0);
        intDeque.push_back(1);
        if(n <= 1) {
            return intDeque[n];
        }
        int res = 0;
        for(int i = 2; i <= n; i ++) {
            res = (intDeque[0] + intDeque[1]) % M;
            intDeque.pop_front();
            intDeque.push_back(res); 
        }
        return res;
    }
};