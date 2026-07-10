class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map <char, int> hash;
        unordered_set <char> st;
        for (char it : s) hash[it]++;

        stack<char> stk;
        for (int i = 0; i < s.size(); i++){
            hash[s[i]]--;
            if (st.count(s[i])) continue;
            else st.insert(s[i]);
            while (!stk.empty() && stk.top() >= s[i] &&hash[stk.top()] > 0){
                st.erase(stk.top());
                stk.pop();
            }
            stk.push(s[i]);
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