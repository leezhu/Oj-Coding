/*
 *2017网易秋招内推笔试编程第2题
 *题目:小易能住最久的一天
 *思路:题目不难，关键考虑的问题就是大树问题，超过了int型的容量，需要用long long才会全部通过
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	long long x,f,d,p;

	cin>>x>>f>>d>>p;

	if((d/x)<=f)
		cout<<d/x;
	else	
		cout<<(f*p+d)/(p+x);
	return 0;
}
