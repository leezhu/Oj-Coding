/******************
 **思路：本题的难点就是在于换行还有补充0，首先直接输出全部的，如果遇到满足换行的就换行，不满足的就输出，最后再考虑末尾直接补充0
 ****************/

#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

void segme(string& s)
{
	int num;	//补充0的个数
	int length;
	length = s.size();
	num = length%8;
	if (num > 0)
		num = 8 -num;
	for(int i=0;i<length;i++)
	{
		cout<<s[i];
		if((i+1)%8==0 && (i+1)< length)
			cout<<endl;	//需要换行
	}
	for(int i=0;i<num;i++)//直接在末尾补0
		cout<<'0';
	cout<<endl;
}
int main()
{
	string temp1;
	string temp2;
	cin>>temp1>>temp2;
	segme(temp1);
	segme(temp2);
	return 0;
}
