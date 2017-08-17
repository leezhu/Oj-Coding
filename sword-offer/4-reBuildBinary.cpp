/*
 *重建二叉树，第四题
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		if(pre.size()>0 && vin.size()>0)
          {
              TreeNode* node = new TreeNode(pre[0]);
             
              node->left = NULL;
              node->right = NULL;
            
              int midNum;
              for(midNum=0;vin[midNum]!=pre[0];midNum++);
            
              vector<int> leftPre(pre.begin()+1,pre.begin()+midNum+1);
            vector<int> rightPre(pre.begin()+midNum+1,pre.begin()+pre.size());
            vector<int> leftVin(vin.begin(),vin.begin()+midNum);
            vector<int> rightVin(vin.begin()+midNum+1,vin.begin()+vin.size());
            
             
              node->left = reConstructBinaryTree(leftPre,leftVin);
              node->right = reConstructBinaryTree(rightPre,rightVin);
            return node;
          }
        else
            return NULL;
    }
};
