class Solution {
  public:
    void print_divisors(int n) {
        vector <int> temp;
        for (int i = 1; i*i <= n; i++){
            if (n % i == 0){
                cout << i << " ";
                temp.push_back(n/i);
            }
        }
        reverse(temp.begin(), temp.end());
        for (int x : temp){
            if (x * x != n) cout << x << " ";
        }
    }
};