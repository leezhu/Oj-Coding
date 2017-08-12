/*
 *阿里编程测试题,给出一行字符串和关键词，用关键词匹配字符串中的字符，如果全匹配到，那么就输出开始和结束位置，没有就输出-1，匹配的条件是可以有一个字符匹配错误，比如说dress,如果匹配到drass也是可以的
 *20170809
 *思路:可以将关键词错一个的情况下进行讨论，这样需要分三种情况，第一个或者最后一个字符错了，那么只要将余下部分全匹配就行，如果错的是中间一个，那么将关键词分为两个部分进行全匹配，只要中间隔一个错误就行。这样下来，时间的复杂度将会是O(mn)
 */
#include<iostream>
#include<string>
using namespace std;

void QueryWordFromLog(string logString,string queryString)
{
	string frontHalf,lastHalf;	//将关键字符串分为前后两部分

	if(logString.size()==0 || queryString.size()==0 || logString.size() < queryString.size())
	{
		cout<<-1;
		return;
	}

	int queryLength = queryString.size();
	int logLength = logString.size();

	int found;

	for(int i=0;i<queryLength;i++)
	{
		if(i == 0)//只错第一个，留下后半部分
		{
			lastHalf = string(queryString,1,queryLength-1);
		}
	}




}

int main()
{
	string logString,queryString;
	
	cin>>logString>>queryString;

	QueryWordFromLog(logString,queryString);
	return 0;
}
