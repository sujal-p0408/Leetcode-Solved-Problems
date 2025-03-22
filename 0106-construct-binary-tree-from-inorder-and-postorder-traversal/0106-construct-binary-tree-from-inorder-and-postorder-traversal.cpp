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
class Solution {
public:
     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
        // Create a map to store indices
        // of elements in the inorder traversal
        map<int, int> inMap;
        
        // Populate the map with indices
        // of elements in the inorder traversal
        for(int i = 0; i < inorder.size(); i++){
            inMap[inorder[i]] = i;
        }
        
        // Call the private helper function
        // to recursively build the tree
        TreeNode* root = buildTree(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, inMap);
        
        return root;
    }

private:
    // Recursive helper function to build the tree
    TreeNode* buildTree(vector<int>& postorder, int postStart, int postEnd, 
            vector<int>& inorder, int inStart, int inEnd, map<int, int>& inMap){
                // Base case: If the start indices 
                // exceed the end indices, return NULL
                if(postStart > postEnd || inStart > inEnd){
                    return NULL;
                }
                
                // Create a new TreeNode with value
                // at the current preorder index
                TreeNode* root = new TreeNode(postorder[postEnd]);
                
                // Find the index of the current root
                // value in the inorder traversal
                int inRoot = inMap[root->val];
                
                // Calculate the number of
                // elements in the left subtree
                int numsLeft = inRoot - inStart;
                
                // Recursively build the left subtree
                root->left = buildTree(postorder, postStart, postStart + numsLeft-1, 
                                inorder, inStart, inRoot - 1, inMap);
                
                // Recursively build the right subtree
                root->right = buildTree(postorder, postStart + numsLeft, postEnd-1, 
                                inorder, inRoot + 1, inEnd, inMap);
                
                // Return the current root node
                return root;
            }
};