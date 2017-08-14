/*
 *问题:[编程题] 游戏任务标记
 时间限制：1秒
 空间限制：32768K
 游戏里面有很多各式各样的任务，其中有一种任务玩家只能做一次，这类任务一共有1024个，任务ID范围[1,1024]。请用32个unsigned int类型来记录着1024个任务是否已经完成。初始状态都是未完成。 输入两个参数，都是任务ID，需要设置第一个ID的任务为已经完成；并检查第二个ID的任务是否已经完成。 输出一个参数，如果第二个ID的任务已经完成输出1，如果未完成输出0。如果第一或第二个ID不在[1,1024]范围，则输出-1。 
 输入描述:
 输入包括一行,两个整数表示人物ID.


 输出描述:
 输出是否完成

 输入例子1:
 1024 1024

 输出例子1:
 1
 *思路:其实这个问题，很容易想到利用位来计算，unsign int为32位，没一位进行标记，那么就是32*32=1024，就可以将所有的进行标记记录,
 

 -----------分隔线啊-------
 但是，这个题目只有两个输入，如果两个数不一致，说明那肯定是没有标记的啊，一致说明肯定标记了，晕，这么傻叉的提莫
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
	unsigned int flagArray[32]={0};
	int value1,value2;
	int moveBits=0,index=0;
	cin>>value1>>value2;

	if(value1<1 || value2<1 || value1>1024 || value2>1024)
	{
		cout<<-1;
		return 0;
	}

	if(value1 == value2)
	{
		cout<<1;
		return 0;
	}
	moveBits = value1%32;

	if(moveBits == 0)//标记最高位为1
	{
		
		index = value1/32 -1;
		//判断是否标记了
		if(flagArray[index] & (1<<31) != 1)//没标记
		{
			flagArray[index] = flagArray[index] + (1<<31);//进行标记 
		}
	}
	else
	{
		index = value/32;	//从下一个开始
		if(flagArray[index] & (1<<(moveBits-1)) != 1)//没标记
		{
			flagArray[index] = flagArray[index] + (1<<(moveBits-1));//进行标记 
		}
	}


	return 0;
}
