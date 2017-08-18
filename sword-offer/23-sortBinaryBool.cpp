/*
 *题目描述
 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
 *
 *
 * 解决办法，利用递归和二叉搜索树特点，前<中<后，后序遍历最后一个为根节点，然后通过左子树比根节点小，柚子树比根节点大这样的方式找出左右子树，然后递归再判断找
 */

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
		int length=sequence.size();
       
        if(length==0)
            return false;
        
        int root = sequence[length-1];
        
        //在二叉搜索树中左子树的节点小于根节点
       	int i=0;
        for(;i<length-1;i++)
            {
            if(sequence[i]>root)
                break;	
        }
        
        int j=i;	//这个部分主要是判断右子树会不会出现小于情况
        for(;j<length-1;j++)
            {
            if(sequence[j]<root)
                return false;	//右子树都是大于，如果小于，那么就不是
        }
        
        //判断左子树是不是二叉搜索树
        bool left = true;
        if(i>0)	//说明有左子树
            {
             vector<int> leftTree(sequence.begin(),sequence.begin()+i);
             left = VerifySquenceOfBST(leftTree);
        }
        
        //判断柚子树
        bool right = true;
        if(i<length-1)
         {
            vector<int> rightTree(sequence.begin()+i,sequence.end()-1);
            right=VerifySquenceOfBST(rightTree);
        }   
            
        
        return right&&left;
    }
};
