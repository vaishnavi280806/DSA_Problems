class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        priority_queue<vector<int>> pq;
        pq.push({a[n-1] + b[n-1], n-1, n-1});
        
        set<pair<int, int>> st;
        st.insert({n-1, n-1});
        
        vector<int> res;
        
        for (int x = 0; x < k; x++){
            int sum = pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];
            pq.pop();
            res.push_back(sum);
            
            if (i >= 1 && !st.count({i-1, j})){
                pq.push({a[i-1] + b[j], i-1, j});
                st.insert({i-1, j});
            }
            if (j >= 1 && !st.count({i, j-1})){
                pq.push({a[i] + b[j-1], i, j-1});
                st.insert({i, j-1});
            }
            
        }
        sort(res.begin(), res.end(), greater<int>());
        return res;
        
        
    }
};