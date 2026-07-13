class Solution {
    bool check(stack<char>& stk, string& part, int n){
        stack<char> temp = stk;

        for (int i = n-1; i >= 0; i--){
            if (temp.top() != part[i]) return false;
            temp.pop();
        }
        return true;
    }
public:
    string removeOccurrences(string s, string part) {
        stack<char> stk;
        int j = part.size() - 1;
        int n = part.size();
        for(int i = 0; i < s.size(); i++){
            stk.push(s[i]);
            
            if (stk.size() >= n && check(stk, part, n)){
                for (int j = 0; j < n; j++) stk.pop();
            }
        }

        string res = "";
        while (!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};