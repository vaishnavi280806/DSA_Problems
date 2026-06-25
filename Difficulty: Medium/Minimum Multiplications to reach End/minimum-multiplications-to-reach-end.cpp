class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        if (start == end) return 0;
        int n = arr.size();
        vector<int> dist(1000, INT_MAX);
        //priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        queue<pair<int, int>> q;
        q.push({0, start});
        
        while(!q.empty()){
            int steps = q.front().first;
            int node = q.front().second;
            q.pop();
            
            for (int i = 0; i < n; i++){
                int newn = (node * arr[i]) % 1000;
                if (steps + 1 < dist[newn]){
                    dist[newn] = steps + 1;
                    q.push({steps + 1, newn});
                }
            }
        }
        
        if (dist[end] != INT_MAX) return dist[end];
        return -1;
    }
};