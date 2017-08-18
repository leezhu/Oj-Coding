/*
 *题目描述
 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
 *
 *
 * 解法，用一个辅助栈，每次压入，都把之前的压入辅助栈，如果辅助栈顶不等于需要弹出的，那么再从压入栈中找到，也把找到的之前的压入栈中，然后取栈顶比较
 */

class Solution {
public:
    stack<int> ass;
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        
        bool result=false;
        int pushIndex=0;
        if(pushV.size()==0 && popV.size()==0)
            return result;
        for(int i=0;i<popV.size();i++)
         {
           // int value=popV[i];
            
            //如果为空
            while(ass.empty() || popV[i]!=ass.top())
            {
                if(pushIndex==pushV.size())
                    break;
           		ass.push(pushV[pushIndex]);
                pushIndex++;
            }
            
            if(ass.top()!=popV[i])
                break;
            ass.pop();	//弹出来
        }
        if(ass.empty() && pushIndex==pushV.size() )
            result=true;
        
        return result;
    }
};
