/*
 *题目描述
 输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
 *
 * 解法：用中序遍历，指定的值减去当前节点的值，然后递归往下找
 *两个解法，自己的复杂一些，运行出错，但是思想是一直的
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
class Mine {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		//用两个栈来解决，一个栈遍历，一个站存路径，每次到节点为空就判断栈节点内容的值，如果不等于就清空
        vector<vector<int> > result;
        vector<int> rec;
        stack<TreeNode*> tra,path;
        TreeNode* temp;
        int m=0;
        
        
        tra.push(root);
        
        while(!tra.empty())
        {
            
         	temp=tra.top();
            tra.pop();
            path.push(temp);
            if(temp->left!=NULL)
             {
                tra.push(temp->left);
            }else if(temp->right==NULL){
                //判断路径等于值，输入
                rec=checkPathNumber(path,expectNumber);
                if(rec.size()!=0)
                    result[m++]=rec;
                    
            }else
            	tra.push(temp->right);
            
            
        }
        
        return result;
    }
    
    vector<int> checkPathNumber(stack<TreeNode* >& path,int expectNumber)
        {
       			int sum=0;
        		vector<int> rec;
                //rec.clear();
                while(!path.empty())
                    {
                    TreeNode* sta;
                    sta=path.top();
                    path.pop();
                    rec.push_back(sta->val);
                    sum+=sta->val;
                }
                if(sum != expectNumber)
                    rec.clear();
        		return rec;
    }
};


class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> ret;
        vector<int> trace;
        if(root)
            dfs(root,expectNumber,ret,trace);
        return ret;
    }
    void dfs(TreeNode* root,int s,vector<vector<int>> &ret,vector<int> &trace) {
        trace.push_back(root->val);
        if(!root->left&&!root->right) {
            if(s==root->val)
                ret.push_back(trace);
        }
        if(root->left)
            dfs(root->left,s-root->val,ret,trace);
        if(root->right)
            dfs(root->right,s-root->val,ret,trace);
        trace.pop_back();
    }
};
