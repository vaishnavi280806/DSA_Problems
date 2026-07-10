class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == k) return "0";
        stack<char> stk;

        for (int i = 0; i < num.size(); i++){
            while (!stk.empty() && stk.top() > num[i] && k > 0){
                stk.pop();
                k--;
            }
            stk.push(num[i]);
        }
        while (k){
            stk.pop();
            k--;
        }
        string res = "";
        while (!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        int l = 0;
        while (res[l] == '0') l++;
        res = res.substr(l, (int)res.size() - l);
        if (res != "") return res;
        return "0";
    }
};