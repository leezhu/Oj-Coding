/*
 *描述:输入正整数，按照从小到大的顺序输出它的所有质数的因子，最后一个有空格
 *时间:20170714
 */
#include<iostream>
using namespace std;

int main()
{
	int value;
	cin>>value;
	
	for(int i=2;i<=value;i++)
	{
		if(value%i==0)	//能被除尽
		{
			cout<<i<<" ";
			value /=i;
			i--;//还是从i开始算起，因为后面需要i++
		}
	}
	
	return 0;
}
