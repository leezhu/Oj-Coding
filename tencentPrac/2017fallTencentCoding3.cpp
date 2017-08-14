/*
 *问题:[编程题] 素数对
 时间限制：1秒
 空间限制：32768K
 给定一个正整数，编写程序计算有多少对质数的和等于输入的这个正整数，并输出结果。输入值小于1000。
 如，输入为10, 程序应该输出结果为2。（共有两对质数的和为10,分别为(5,5),(3,7)） 
 输入描述:
 输入包括一个整数n,(3 ≤ n < 1000)


 输出描述:
 输出对数

 输入例子1:
 10

 输出例子1:
 2
 *
 *思路:只需要判断一半，另一个相减可以得出
 */

#include<bits/stdc++.h>
using namespace std;

bool primeNumber(int number)
{
	for(int i=2;i<number/2;i++)
	{
		if(number%i == 0)
			return false;
	}

	return true;

}

int main()
{
	int inputValue;
	int sum=0;

	cin>>inputValue;

	for(int i=2;i<=inputValue/2;i++)
	{
		if(primeNumber(i) && primeNumber(inputValue-i))
			sum++;
	}
	cout<<sum;
	return 0;
}
