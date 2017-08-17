/*
 *
 *题目描述
 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
 */

class Solution {
public:
     int  NumberOf1(int n) {
         int number=0;
         int unsigned flag=1;
         int unsigned temp;
         for(int i=0;i<32;i++)
             {
             flag=1;
             temp = n&(flag<<i);
             if(temp>0)
                 number++;
         }
         return number;
     }
};
