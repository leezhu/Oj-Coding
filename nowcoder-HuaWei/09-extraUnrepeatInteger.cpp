/*
 *描述:输入一个int整数，从右到左阅读顺序，返回不含重复数字的新的整数
 *思路:第一种思想，可将整数进行分开存入数组当中，按序号存，最后一一取出来,第二种思想，将新的数字进行组成整数，这样复杂度会降低到O(n)
 *时间:20170714
 */

#include<iostream>
using  namespace std;

int main()
{
	int value;
	int temp;
	int m=0;
	int array[10];//初始化为-1
	cin>>value;
	

	for(int i=0;i<10;i++)
		array[i]=-1;
	while(value%10!=0)
	{
		temp = value %10;	
		int i=0;
		for(;array[i]!=-1;i++)
		{
			if(temp == array[i])
				break;
		}
		if(array[i]==-1)
			array[m++] = temp;
		value /=10;
	}

	for(int i=0;i<m;i++)
		cout<<array[i];

	return 0;
}
