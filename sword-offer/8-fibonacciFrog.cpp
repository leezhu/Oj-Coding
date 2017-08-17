/*
 *题目描述
 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

 可以理解为如果最后一个台阶是一级，或者两级，不管一级两级，都是算做一个跳法
 f(n) = f(n-1) + f(n-2)
 */
class Solution {
public:
    int jumpFloor(int number) {
        
       
        if(number==1)
            return 1;
        if(number==2)
            return 2;
        
        return jumpFloor(number-2)+jumpFloor(number-1);
        
    }
};

