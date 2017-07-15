/*
 *描述:句子逆序
 *思想:从后往前，用一个标识位记录后一个空格的位置，然后输出其中的字符
 *时间:20170715
 */

#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	int flag;
	getline(cin,str);
	
	flag = str.size()-1;
	for(int i = str.size()-1;i>=0;i--)
	{
		if(str[i]==' ' || i==0)
		{
			int j = (i==0?i:i+1);
			for(;j<=flag;j++)//输出单词
				cout<<str[j];
			if(i!=0)
				cout<<" ";
			flag=i -1;//向前进一位
		}
	}
	return 0;
}
