/*
 *题目描述
 输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
 *
 * 分两个函数，一个函数遍历找根节点是否相同，一个函数来判断是否结构相同，用递归，出口是子树为空返回真，母数为空返回false
 */

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result = false;
		
        if(pRoot1!=NULL && pRoot2!=NULL)
          {
            if(pRoot1->val == pRoot2->val)//如果相等，判断是否存在相同
                result = DoesTreeHaveTree2(pRoot1,pRoot2);       
            if(!result)	//如果不存在，那么往左子树找。找根节点是否相同
                result =HasSubtree(pRoot1->left,pRoot2);

            if(!result)	//如果不存在，那么往右子树找s
                result =HasSubtree(pRoot1->right,pRoot2);
        }
        return result;
    }
    
    bool DoesTreeHaveTree2(TreeNode* pRoot1, TreeNode* pRoot2)
        {
        
        if(pRoot2==NULL)
            return true;	//为空，但是root1不为空，可以认为之前相同
        
        if(pRoot1==NULL)
            return false;	//为空，但是root2不为空
        
        if(pRoot1->val!=pRoot2->val)
            return false;
        return DoesTreeHaveTree2(pRoot1->left,pRoot2->left) && DoesTreeHaveTree2(pRoot1->right,pRoot2->right);
        }
    
};
