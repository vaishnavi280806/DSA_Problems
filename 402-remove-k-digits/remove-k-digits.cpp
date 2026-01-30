class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == num.size()) return "0";
        stack<char> stk;
        for (int i = 0; i < num.size(); i++){
            while (!stk.empty() && stk.top() > num[i] && k > 0){
                stk.pop();
                k--;
            }
            stk.push(num[i]);
        }
        string res;
        while (!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        int last = res.size() - 1;
        while (k != 0){
            last--; k--;
        }
        reverse(res.begin(), res.end());
        cout << res;
        int start = 0;
        while (res[start] == '0' && start < last) start++;
        if (start == last + 1) return "0";
        return res.substr(start, last - start + 1);
    }
};