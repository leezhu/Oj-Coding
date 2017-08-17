/*
 *题目描述
 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
 n<=39
 *
 */

class Solution {
public:
    int Fibonacci(int n) {
		int front=0,back=1;
        int result;
        
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        
        for(int i=2;i<=n;i++)
            {
            result = front+back;
            front = back;
            back = result;
        }
        return result;
    }
};
