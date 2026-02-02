class Solution {
  public:
    int celebrity(vector<vector<int>>& mats) {
        if (mats.size() == 1){
            if (mats[0][0] == 1) return 0;
            else return -1;
        }
        stack <int> stk;
        for (int i = 0; i < mats.size(); i++){
            stk.push(i);
        }
        while (stk.size() != 1){
            int tp1 = stk.top(); stk.pop();
            int tp2 = stk.top(); stk.pop();
            if (mats[tp1][tp2]) stk.push(tp2);
            else stk.push(tp1);
        }
        for (int i = 0; i < mats.size(); i++){
            if (stk.top() != i){
                if (mats[stk.top()][i] == 1 || mats[i][stk.top()] == 0) return -1;
            }
        }
        return stk.top();
    }
};