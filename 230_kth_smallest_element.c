//Leetcode problem : 230
//Kth smallest element https://leetcode.com/problems/kth-smallest-element-in-a-bst/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeInfo{
    int numNodesVisited ;
    int latestNodeValue ;
} ;

void inOrderTraverse(struct TreeNode* node, int k , struct TreeInfo* treeInfo){
    if (node == NULL || treeInfo->numNodesVisited >= k){
        return; 
    }
    
    inOrderTraverse(node->left, k, treeInfo);
    
    if (treeInfo -> numNodesVisited < k){
        treeInfo -> numNodesVisited += 1;
        treeInfo -> latestNodeValue = node -> val;
        inOrderTraverse(node->right, k, treeInfo);
    }
    
    
}

int kthSmallest(struct TreeNode* root, int k){
    struct TreeInfo *treeInfo = (struct TreeInfo*)malloc(sizeof(struct TreeInfo));
    treeInfo->numNodesVisited = 0;
    treeInfo->latestNodeValue = -1;
    
    inOrderTraverse( root, k, treeInfo);
    return treeInfo->latestNodeValue;
    

}
