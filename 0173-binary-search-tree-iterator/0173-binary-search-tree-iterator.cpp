/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    
    vector<int> v;
    int i=0;
     void generateInorder(TreeNode* root)
    {
       if(root==nullptr)  return; 
       generateInorder(root->left);
       v.push_back(root->val);
       generateInorder(root->right);
       return;
    }
    BSTIterator(TreeNode* root) {
        generateInorder(root);
    }
    
    int next() {
        return v[i++];
    }
    
    bool hasNext() {
        return i<v.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */