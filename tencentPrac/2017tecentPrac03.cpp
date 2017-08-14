/*
 *问题:[编程题] 有趣的数字
 时间限制：1秒
 空间限制：32768K
 小Q今天在上厕所时想到了这个问题：有n个数，两两组成二元组，差最小的有多少对呢？差最大呢？


 输入描述:

  输入包含多组测试数据。

   对于每组测试数据：

    N - 本组测试数据有n个数

	 a1,a2...an - 需要计算的数据

	  保证:

	   1<=N<=100000,0<=ai<=INT_MAX.
	     


	   输出描述:

	   对于每组数据，输出两个数，第一个数表示差最小的对数，第二个数表示差最大的对数。

	   输入例子1:
	   6
	   45 12 45 32 5 6

	   输出例子1:
	   1 2
*思路:先进行排序，最大的必定是第一个和最后一个的差，存在多个的情况是出现了重复数字，差最小就出现在两个相邻数之差。
 *时间:20170814
 */

#include<bits/stdc++.h>
using namespace std;

void MaxAndMinPairNumber(vector<int>& vec)
{
	int minPair=0,maxPair=0;
	int frontRep=1,backRep=1;

	cout<<"yes";
	//先排序
	sort(vec.begin(),vec.end());
	
	int len = vec.size();
	int flagFront=0,flagBack=0;
	for(int i=0,j=len-1;i<j && i<len-2 && j>1;)
	{
		//只需要判断首尾有多少重复数字就可以算出来
		if(vec[i+1]==vec[0])
		{
			frontRep++;
			i++;
		}else
			flagFront=1;

		if(vec[j-1]==vec[len-1])
		{
			backRep++;
			j--;
		}else
			flagFront=1;

		if(flagFront==1 &&flagBack==1)
			break;
	}

	//如果全部都相同，即11111,从中选两个
	cout<<"f="<<frontRep<<" "<<backRep<<endl;
	if((frontRep+backRep)==len)
	{
		maxPair = len*(len-1)/2;
		minPair = maxPair;
		cout<<minPair<<" "<<maxPair;
		return;
	}
	else
	{
		maxPair = frontRep*backRep;
	}

	//查找最小的就是求相邻差最小
	int minValue=vec[1]-vec[0];
	for(int i=1;i<len;i++)
	{
		if(vec[i]-vec[i-1]==minValue)
		{
			minPair++;
		}
		else if(vec[i]-vec[i-1]<minValue)	//如果小于，重置
		{
			minPair=1;
		}
	}

	cout<<minPair<<" "<<maxPair;
}

int main()
{
	int num;
	int value;
	vector<int> inputData;

	cin>>num;

	for(int i=0;i<num;i++)
	{
		cin>>value;
		inputData.push_back(value);
	}
	
	MaxAndMinPairNumber(inputData);
	return 0;
}
