/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // Function to find the path to a node
    bool findPath(TreeNode* root, int target, vector<TreeNode*>& path) {
        if (!root) return false;

        path.push_back(root);

        if (root->val == target) return true;

        if (findPath(root->left, target, path) || findPath(root->right, target, path)) 
            return true;

        path.pop_back();
        return false;
    }

    // Function to return the path from root to the target node
    vector<TreeNode*> solve(TreeNode* root, int target) {
        vector<TreeNode*> path;
        if (!root) return path;
        findPath(root, target, path);
        return path;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1 = solve(root, p->val);
        vector<TreeNode*> path2 = solve(root, q->val);

        TreeNode* lca = nullptr;
        int n = min(path1.size(), path2.size());

        for (int i = 0; i < n; i++) {
            if (path1[i] == path2[i]) 
                lca = path1[i];
            else 
                break;
        }

        return lca;
    }
};
