class Solution {
public:
    bool checkOnesSegment(string s) {
        int c = 0;
        int i = 0;
        while (i < s.size()){
            if (s[i] == '0') break;
            i++;
        }
        while (i < s.size()){
            if (s[i] == '1') return false;
            i++;
        }
        return true;
    }
};