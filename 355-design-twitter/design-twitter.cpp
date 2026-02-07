class Twitter {
    unordered_map <int, unordered_set<int>> follows; 
    unordered_map <int, vector<pair<int, int>>> posts;
    int time = 1;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue <vector<int>> pq;
        for (auto x : posts){
            if(x.first == userId || follows[userId].count(x.first)) pq.push({x.second[x.second.size() - 1].first, x.first, (int)x.second.size() - 1});
        }
        int c = 0;
        vector<int> res;
        while (!pq.empty() && c != 10){
            int t = pq.top()[0];
            int user = pq.top()[1];
            int idx = pq.top()[2];
            res.push_back(posts[user][idx--].second);
            pq.pop();
            if (idx >= 0) pq.push({posts[user][idx].first, user, idx});
            c++;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */