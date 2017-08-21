/*
 *
 *题目描述
 输入一棵二叉树，判断该二叉树是否是平衡二叉树。
 *
 */


class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
		
        if(pRoot==NULL)
            return true;
        return abs(TreeDepth(pRoot->left)-TreeDepth(pRoot->right))>1?false:true;
    }

    int TreeDepth(TreeNode* pRoot)
    {
    	if(pRoot==NULL)
            return 0;
        
        return max(TreeDepth(pRoot->left),TreeDepth(pRoot->right))+1;
        
    }
};
