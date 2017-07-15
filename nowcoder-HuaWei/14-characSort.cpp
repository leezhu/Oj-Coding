/*
 *描述:对n个字符串进行按字典排序
 *20170715
 */
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int num;
	int loc;//每次排序最小的位置
	cin>>num;

	string str[1000];
	for(int i=0;i<num;i++)
	{	
		cin>>str[i];
		//cout<<str[i];
	}
	//用冒泡排序法来排序,找到一个最小的然后替换
	for(int i=0;i<num-1;i++)
	{
		loc = i;
		for(int j=i+1;j<num;j++)
		{
			if(str[loc].compare(str[j])>0)//比其小
				loc = j;
		}
		//交换
		//cout<<"loc="<<loc<<endl;
		string temp;
		temp = str[i];
		str[i] = str[loc];
		str[loc] = temp;
	}
	for(int i=0;i<num;i++)
		cout<<str[i]<<endl;
	
	return 0;
}
