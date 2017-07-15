/*
 *描述:字符串反转
 *思想:逆序输出
 *时间:20170715
 */
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	cin>>str;
	for(int i=str.size()-1;i>=0;i--)
		cout<<str[i];
	return 0;
}
