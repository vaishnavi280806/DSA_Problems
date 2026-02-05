class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map <char, int> hash;
        for (char x : tasks){
            hash[x]++;
        }
        priority_queue <int> pq;
        for (auto x : hash){
            pq.push(x.second);
        }
        int c = 0;
        queue <pair<int, int>> q;
        while (!pq.empty() || !q.empty()){
            c++;
            if (!pq.empty()){
                int tp = pq.top();
                pq.pop();
                if (tp - 1 != 0) q.push({tp - 1, c + n});
            }
            
            while (!q.empty() && q.front().second == c){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return c;
    }
};