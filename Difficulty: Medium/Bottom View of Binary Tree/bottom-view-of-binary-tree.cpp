/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        map<int, int> ans;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto temp = q.front();
            Node* node = temp.first;
            int x = temp.second;
            q.pop();
            
            ans[x] = node->data;
            
            if (node->left) q.push({node->left, x - 1});
            if (node->right) q.push({node->right, x + 1});
           
        }
        vector<int> res;
        for (auto x : ans){
            res.push_back(x.second);
        }
        return res;
    }
};