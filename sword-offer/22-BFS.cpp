/*
 *广度优先遍历二叉树
 *
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
    
    vector<int> PrintFromTopToBottom(TreeNode* root) {
		
        queue<TreeNode*> que;
        TreeNode* temp;
        vector<int> result;
        if(root!=NULL)
            {
            que.push(root);
           
            while(!que.empty())
                {
                temp=que.front();
                que.pop();
                if(temp!=NULL)
                    {
                    result.push_back(temp->val);
                   	que.push(temp->left);
                    que.push(temp->right);
                }
            }
            
            
        }
        return result;
    }
};
