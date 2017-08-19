/*
 *
 *题目描述
 输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,
 *
 *
 * 采用快速排序法中的分割概念，判断查找的中间分割序号是不是第k个，如果是那么就可以打印前面的
 */

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int>& input, int k) {
        vector<int> result;
        if(input.size()==0 || k<=0 || k>input.size())
            return result;
        
        int left=0;
        int right=input.size()-1;
        int index=patition(input,left,right);
        
        while(index!=(k-1)){
            if(index>(k-1))
            	index = patition(input,left,index-1);
            else 
                index = patition(input,index+1,right);
        }
        for(int i=0;i<k;i++)
            result.push_back(input[i]);
        sort(result.begin(),result.end());
        return result;
    }
    
    int patition(vector<int> &numbers,int left,int right)
        {
        
        int key = numbers[left];
        while(left<right)
            {
            while(left<right && key<numbers[right])
                right--;
            numbers[left]=numbers[right];
            //left++;
            while(left<right && key>numbers[left])
             	left++;
            numbers[right]=numbers[left];
            //right--;
        }
        numbers[left]=key;
        return left;
    }
};
