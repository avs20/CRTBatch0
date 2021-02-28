/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool validateBstHelper(struct TreeNode* tree, long long minValue, long long maxValue )
{
    
    if (tree->val <= minValue || tree->val >= maxValue){
        return false;
    }
    
    if (tree->left != NULL){
        if (!validateBstHelper(tree->left, minValue, tree->val))
            return false;
    }
    
    if (tree->right != NULL){
        if (!validateBstHelper(tree->right, tree->val, maxValue))
            return false;
    }
    
    return true;    
    
}

bool isValidBST(struct TreeNode* root){
    return validateBstHelper(root, -30000000000, 30000000000);
}
