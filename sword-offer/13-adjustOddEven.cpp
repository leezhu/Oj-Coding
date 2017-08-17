/*
 *题目描述
 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
 *
和输出大写字母在后面一样，可以利用辅助内存，输出更方便
 */

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        
        int length = array.size();
        int temp;
        int front,back;
        back = length-1;
        if(length>1)
        	for(int i=length-1;i>=0;i--)
            {
            	if(array[i]%2==0)
            	{
               	 	front = i;  
                
               	 //移动
               		 temp = array[front];
                	for(int j=front;j<back;j++)
                    	array[j]=array[j+1];
               	 if(front!=back)	//不是同一个
                 {
                     if(array[back]%2==0)
                         {
                         array[back-1]=temp;
                         back--;
                     }else
                         array[back]=temp;
                 }
            	}
        	}
        //cout<<"ni";
    }
};

