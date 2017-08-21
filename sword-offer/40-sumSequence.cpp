/*
 *输出描述:
 输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
 *
 *
 */

#include<bits/stdc++.h>
using namespace std;

int sumRange(int begin,int end)
        {
        if(begin==end)
            return begin;
        else
       		return (end-begin+1)*begin+(end-begin+1)*(end-begin)/2;
        
    }

 void  FindContinuousSequence(int sum) {
        vector<vector<int> > result;
        
        int begin,end;
        begin=1;
        end=2;
        int m=0;
        
        //if(sum==1)
       //     {
            //result[m++].push_back(1);
            //return result;
        //}
        
   

        
        while(end<=sum && begin<=end)
            {
            if(sumRange(begin,end)==sum)
                {
                for(int i=begin;i<=end;i++)
                    //result[m].push_back(i);
					cout<<i<<" ";
				cout<<endl;
                ++m;
                ++begin;
            }
            else if(sumRange(begin,end)>sum)
                {
                ++begin;
            }else
                ++end;
        }
        
        //return result;
    }
    
    

int main()
{
	FindContinuousSequence(15);
	return 0;
}
