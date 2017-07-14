/*
 *描述:合并表记录，对相同键值对的数值进行值求和，并且按着key值升序输出
 思路:采用map，map存储的方式就是按照key顺序存储
 *时间:20170714
 */
#include<iostream>
#include<map>
using namespace std;

int main()
{
	//第一种思路
	int nu;
	int key,value;
	map<int,int> mvalue;
	cin>>nu;

	for(int i=0;i<nu;i++)
	{
		cin>>key>>value;
		if(mvalue.find(key) != mvalue.end())//存在,也可以直接判断if(mvalue[key])
			mvalue[key] += value;	
		else
			mvalue[key] = value;	
	}
	//本身按照顺序存储
	for(map<int,int>::iterator it=mvalue.begin();it!=mvalue.end();++it)
		cout<<it->first<<" "<<it->second<<endl;
	return 0;
}
