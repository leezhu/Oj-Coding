/*
 *问题:假定一种编码的编码范围是a ~ y的25个字母，从1位到4位的编码，如果我们把该编码按字典序排序，形成一个数组如下： a, aa, aaa, aaaa, aaab, aaac, … …, b, ba, baa, baaa, baab, baac … …, yyyw, yyyx, yyyy 其中a的Index为0，aa的Index为1，aaa的Index为2，以此类推。 编写一个函数，输入是任意一个编码，输出这个编码对应的Index. 
 输入描述:
 输入一个待编码的字符串,字符串长度小于等于100.


 输出描述:
 输出这个编码的index

 输入例子1:
 baca

 输出例子1:
 16331
 *
 *我的思路:其实就是一个排列组合的问题，从第一字母开始一个个判断，将index进行累加
 */

#include<iostream>
#include<string>
using namespace std;

int getIndex(string& str)
{
	int index=0;

	for(int i=0;i<str.size();i++)
	{
		if(i==0)
		{
			index += (str[i]-'a')*(1+25+25*25+25*25*25)+1;
			cout<<"i=0,index=:"<<index<<endl;
		}
		else if(i==1)
		{
			index += (str[i]-'a')*(1+25+25*25)+1;	
			cout<<"i=1,index=:"<<index<<endl;
		}
		else if(i==2)
		{
			index += (str[i]-'a')*(1+25)+1;
			cout<<"i=2,index=:"<<index<<endl;
		}
		else
			index += (str[i]-'a')*1+1;
	}
	return index-1;//从0开始算的
}
int main()
{
	string inputStr;

	cin>>inputStr;

	cout<<getIndex(inputStr);
	return 0;
}
