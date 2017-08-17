/*
 *题目描述
 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
 *
 */
class Solution {
public:
    double Power(double base, int exponent) {
    	double result=1.0;
        int flag =0;//标记是否指数小于0
        if(exponent==0)
            result=1;
        else if(exponent<0)
         {   
            flag=1;
            exponent = abs(exponent);
        }
        
        for(int i=0;i<exponent;i++)
            result *=base;
        
        if(flag == 1)
            result = 1.0/result;
        
        return result;
    }
};
