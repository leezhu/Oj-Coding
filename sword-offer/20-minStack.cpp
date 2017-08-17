/*
 *题目描述
 定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
 *
 * 采用两个栈解决，其中每次压入栈时要比较栈顶最小值和当前值，如果当前指更小，那么压入它，如果大于等于，那么压入栈顶同样的最小值
 * 每次出栈，直接min栈也弹出就是
 */

class Solution {
public:
    
    
    void push(int value) {
        int minValue;
        if(!minStack.empty())
            {
            minValue=minStack.top();
            if(value<minValue)
                minStack.push(value);
            else
                minStack.push(minValue);
        }
      	else
            minStack.push(value);
        data.push(value);
    }
    void pop() {
        if(!data.empty() && !minStack.empty())
            {
            data.pop();
            minStack.pop();
        }
    }
    int top(){
        
            return data.top();
       
    }
    int min() {
        
           return minStack.top();
    }
    
    stack<int> data;
    stack<int> minStack;
};
