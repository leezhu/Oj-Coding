/*
 *描述:将整数以字符串的形式逆序输出
 *思想：用字符串逆序输出
 *20170715
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
