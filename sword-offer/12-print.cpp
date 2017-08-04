/*
 *描述:打印1到n位,
 *时间:20170804
 */

#include<iostream>
#include<string.h>
using namespace std;
bool Increment(char * number)	//逐渐的加一，增长
{
	bool isOverflow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);

	for(int i= nLength - 1;i>=0;i--)
	{
		int nSum = number[i]-'0' + nTakeOver;

		if(i == nLength -1)	//最后一个开始相加，+1,如果不是最后一位就不需要加一
			nSum++;

		if(nSum >= 10)	//出现需要进位
		{
			if(i == 0)
				isOverflow = true;
			else
			{
				nSum -=10;	//此时要减为0
				nTakeOver = 1;//前进一
				number[i] = '0' + nSum;
			}
		}
		else
		{
			number[i] = '0' + nSum;
			break;
		}
	}

	return isOverflow;
}

void PrintNumber(char* number)
{
	bool isBeginning0 = true;
	int nLength = strlen(number);

	for(int i=0;i<nLength;++i)
	{
		if(isBeginning0 && number[i] != '0')
			isBeginning0 = false;

		if(!isBeginning0)
			cout<<number[i];
	}
	cout<<" ";
}
 void Print1ToMaxOfNDigits(int n)
{
	if(n<=0)
		return;
	char *number = new char[n+1];
	memset(number,'0',n);

	while(!Increment(number))
	{
		PrintNumber(number);
	}

	delete [] number;
}
int main()
{
	Print1ToMaxOfNDigits(2);	
	return 0;
}
