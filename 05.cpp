// 这题时间已经到0ms了，不需要再优化了，但是还需要再了解关于stringstream的用法
// 但是内存占用好像有点高，不知道能不能优化一下
class Solution {
public:
    string replaceSpace(string s) {
        stringstream ss;
        for(int i = 0; i < s.size(); i ++) {
            if(s[i] != ' ') {
                ss << s[i];
            } else {
                ss <<'%';
                ss << '2';
                ss << '0';
            }
        }
        string res = ss.str();
        return res;
    }
};