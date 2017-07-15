/*
 *描述:计算字符串中含有的不同字符的个数
 *思想:用数组的序号存其字符串的整数表达，并且标记
 *时间:20170715
 */

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int arr[128]={0};//将字符转成数字然后存入数组当中
	int num=0;//计算不同的个数
	string str;
	cin>>str;

	for(int i=0;i<str.size();i++)
		arr[str[i]-'\0']=1;//直接用str[i]也可以，是可以被强转的，while(cin>>ch)读取一行字符串，以空格结尾
	for(int i=0;i<128;i++)
		if(arr[i]==1)
			num++;
	cout<<num;
	return 0;
}
