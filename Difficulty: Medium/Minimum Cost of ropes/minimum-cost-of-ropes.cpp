class Solution {
  public:
    int minCost(vector<int>& arr) {
        if (arr.size() == 1) return 0;
        priority_queue <int, vector<int>, greater<int>> pq;
        for (int x : arr){
            pq.push(x);
        }
        int res = 0;
        while (!pq.empty()){
            int tp1 = pq.top(); pq.pop();
            if (pq.empty()) return res;
            int tp2 = pq.top(); pq.pop();
            pq.push(tp1 + tp2);
            res += tp1 + tp2;
        }
        return -1;
    }
};