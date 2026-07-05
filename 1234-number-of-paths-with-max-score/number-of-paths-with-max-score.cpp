class Solution {
    int n;
    int mod = 1e9 + 7;
    vector<string> board;
    pair<int, int> helper(int r, int c, vector<vector<pair<int, int>>>& dp){
        if (r < 0 || c < 0) return {-1, 0};
        if (board[r][c] == 'X') return {-1, 0};
        if (r == 0 && c == 0) return {0, 1};

        if (dp[r][c].first != -2 && dp[r][c].second != -1) return dp[r][c];

        auto up = helper(r-1, c, dp);
        auto left = helper(r, c-1, dp);
        auto dia = helper(r-1, c-1, dp);

        int maxi = max({up.first, left.first, dia.first});
        if (maxi == -1) return dp[r][c] = {-1, 0};

        int ways = 0;
        if (up.first == maxi) ways = (ways + up.second) % mod;
        if (left.first == maxi) ways = (ways + left.second) % mod;
        if (dia.first == maxi) ways = (ways + dia.second) % mod;

        int data;
        if (board[r][c] == 'S' || board[r][c] == 'E') data = 0;
        else data = board[r][c] - '0';
        return dp[r][c] = {maxi + data, ways};
    }
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        this->board = board;
        int n = board.size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>> (n, {-2, -1}));
        auto res = helper(n-1, n-1, dp);
        if (res.first == -1) return {0, 0};
        return {res.first, res.second};
    }
};