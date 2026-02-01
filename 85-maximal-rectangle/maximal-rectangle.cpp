class Solution {
    int largestRectangle(vector<int>& arr){
        stack<int> stk;
        int ans = 0, pse;
        for (int i = 0; i < arr.size(); i++){
            while (!stk.empty() && arr[stk.top()] > arr[i]){
                int tp = stk.top(); stk.pop();
                pse = !stk.empty() ? stk.top() : -1;
                ans = max(ans, arr[tp] * (i - pse - 1));
            }
            stk.push(i);
        }
        while (!stk.empty()){
            int tp = stk.top(); stk.pop();
            pse = !stk.empty() ? stk.top() : -1;
            ans = max(ans, arr[tp] * ((int)arr.size() - pse - 1));
        }
        return ans;

    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> prefix(m, vector<int> (n));
        for (int i = 0; i < n; i++) prefix[0][i] = matrix[0][i] - '0';
        for (int i = 1; i < m; i++){
            for (int j = 0; j < n; j++){
                prefix[i][j] = matrix[i][j] == '1' ? prefix[i-1][j] + 1 : 0;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) ans = max(ans, largestRectangle(prefix[i]));
        return ans;

    }
};