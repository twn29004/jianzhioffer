class Solution {
private:
    const int M = 1e9+7;
public:
    int cuttingRope(int n) {
        if(n <= 3)  return n-1;     //如果n<=3,数字要求至少分为两部分，实际结果的最大值为n-1
        long long res = 1;
        while(n > 4)
        {
            n = n - 3;
            res = res * 3 % M;
        }
        return res * n % M;
    }
};


/*
    剪绳子的贪心算法
*/
// 快速幂的方法，如果不知道怎么搞可以写几个出来看看结果。
class Solution {
private:
    const int M = 1e9 + 7;
public:
    using ll = long long;
    ll quickPow(int tmpa, int m) {
        ll res = 1;
        ll a = tmpa;
        while(m) {
            if(m % 2) {
                res = (res * a) % M;
            }
            a = (a * a) % M;
            m /= 2;
        }
        return res;
    }
    int cuttingRope(int n) {
        if(n <= 3) {
            return n - 1;
        }
        if(n % 3 == 1) {
            int cnt = n / 3;
            ll res = quickPow(3, cnt - 1);
            return res * 4 % M;
        } else {
            int cnt = n / 3;
            ll res = quickPow(3, cnt);
            if(n % 3 == 2){
                return (res * 2) % M;
            } else { 
                return res;
            }
        }
        return -1;
    }
};