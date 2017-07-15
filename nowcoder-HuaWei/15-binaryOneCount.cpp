/*
 *描述:求整数二进制1的个数，思想，可以用位运算来做,每次右移一位，然后和1进行与操作
 *20170715
 */
#include<iostream>
using namespace std;

int main()
{
	int value;
	int count=0;
	cin>>value;

	while(value>0)
	{
		if(value & 1 == 1)
			count++;
		value = value>>1;
	//	cout<<"value="<<value<<endl;
	}
	cout<<count;
	return 0;
}
