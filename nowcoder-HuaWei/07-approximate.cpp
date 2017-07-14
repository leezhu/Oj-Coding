/*
 *描述:取近似值，分上下取整，利用c语言中的floor(x)向下取整，还有ceil(x)向上取整
 *时间：20170714
 */

#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	float value;
	int temp;
	cin>>value;

	temp=floor(value);
	if((value-temp)>=0.5)
		temp +=1;
	cout<<temp;
	return 0;
}
