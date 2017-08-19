/*
 *
 *题目描述
 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，
 超过数组长度的一半，因此输出2。如果不存在则输出0。
 *
 * 解法:如果出现是一半，那么采用快速排序的思想，将vector先按照第一个数进行分治，那么比其大的在右边，比它小的在左边，
 * 又因为出现的次数是一半以上的，那么必定中间会是这个数，当然了，还要判断中间个数是否是满足大于一半以上，不然就不存在
 */

class Solution {
public:

    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	if(numbers.size()==0)
            return 0;

        patition(numbers);
        int value =numbers[numbers.size()/2];
        int sum=0;
        for(int i=0;i<numbers.size();i++)
            if(numbers[i]==value)
                sum++;
        if(sum>(numbers.size()/2))
            return value;
        else
            return 0;
    }
    
    void patition(vector<int> numbers)
        {
        int left=0;
        int right=numbers.size()-1;
        int key = numbers[0];
        while(left<right)
            {
            while(left<right && key<numbers[right])
                right--;
            numbers[left]=numbers[right];
            left++;
            while(left<right && key>numbers[left])
             	left++;
            numbers[right]=numbers[left];
            right--;
        }
        numbers[left]=key;
    }
};
