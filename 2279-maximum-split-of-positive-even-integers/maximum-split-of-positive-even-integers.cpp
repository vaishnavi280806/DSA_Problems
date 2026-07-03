class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2) return {};
        vector<long long> res;
        stack<long long> stk;
        long long num = 2;
        long long sum = 0;
        while (finalSum != sum){
            if (finalSum - sum < num){
                long long n = stk.top();
                stk.pop();
                stk.push(n + finalSum - sum);
                break;
            }
            else{
                sum += num;
                stk.push(num);
                num += 2;
            }
        }

        while (!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};