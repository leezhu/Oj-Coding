/*
 *题目描述
 输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
 输出描述:
 对应每个测试案例，输出两个数，小的先输出。
 *
 *
 */


class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        
        int begin=0;
        int end=array.size()-1;
        
        if((end+1)==0)
            return result;
        
        int minNum1=array[end],minNum2=array[end-1];
        
        while(begin<end)
            {
            if((array[begin]+array[end])==sum)
                {
                if((array[begin]*array[end])<(minNum1*minNum2))
                    {
                    minNum1=array[begin];
                    minNum2=array[end];
                }
            }else if((array[begin]+array[end])>sum)
                --end;
            else
                ++begin;
        }
        result.push_back(array[minNum1]);
        result.push_back(array[minNum2]);
        
        return result;
    }
};
