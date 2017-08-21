/*
 *
 *题目描述
 统计一个数字在排序数组中出现的次数。
 *
可以用二分法，对于排序数组

 */



class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int count=0;
        int len=data.size();
        
        if(len==0)
            return 0;
        
        for(int i=0;i<len;i++)
            {
            if(data[i]==k)
                count++;
        }
        return count;
    }
};
