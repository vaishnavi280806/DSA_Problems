class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long long num = 0;

        while (i < s.size() && s[i] == ' ') i++;
        if (i == s.size()) return 0;
        if (s[i] == '-'){
            sign = -1;
            i++;
        }
        else if (s[i] == '+') i++;
        while (i < s.size()){
            if (s[i] >= '0' && s[i] <= '9'){
                num = num * 10 + (s[i] - '0');
                if (num > INT_MAX && sign == -1) return INT_MIN;
                else if (num > INT_MAX && sign == 1) return INT_MAX;
            }
            else return num * sign;
            i++;
        }
        return num * sign;
    }
};