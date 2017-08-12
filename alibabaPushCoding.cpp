/*
 *阿里编程测试题,给出一行字符串和关键词，用关键词匹配字符串中的字符，如果全匹配到，那么就输出开始和结束位置，没有就输出-1，匹配的条件是可以有一个字符匹配错误，比如说dress,如果匹配到drass也是可以的
 *20170809
 *思路:可以将关键词错一个的情况下进行讨论，这样需要分三种情况，第一个或者最后一个字符错了，那么只要将余下部分全匹配就行，如果错的是中间一个，那么将关键词分为两个部分进行全匹配，只要中间隔一个错误就行。这样下来，时间的复杂度将会是O(mn)
 */
#include<iostream>
#include<string>
using namespace std;

void queryWordFromLog(string& logString,string& queryString)
{
	string frontHalf,lastHalf;	//将关键字符串分为前后两部分

	if(logString.size()==0 || queryString.size()==0 || logString.size() < queryString.size())
	{
		cout<<-1;
		return;
	}

	int queryLength = queryString.size();
	int logLength = logString.size();

	string::size_type found,frontFound,lastFound;

	for(int i=0;i<queryLength;i++)
	{
		if(i == 0)//只错头和尾，留下后半部分
		{
			
			lastHalf = string(queryString,1,queryLength-1);
			 found= logString.find(lastHalf,1);
			 cout<<"i==0 found:"<<found;
			while(found!=string::npos)
			{
				cout<<"头可变:"<<found-1<<" "<<found + queryLength-1;
				found = logString.find(lastHalf,found+1);
			}
		}
		else if(i ==queryLength-1)
		{
			lastHalf = string(queryString,0,queryLength-1);
			 found= logString.rfind(lastHalf,queryLength-1);//从倒数第二个开始查找，留一个位置

			while(found!=string::npos)
			{
				cout<<"尾可变："<<found<<" "<<found + queryLength;
				found = logString.rfind(lastHalf,found-1);
			}

		}
		else
		{
			frontHalf = string(queryString,0,i);
			lastHalf = string(queryString,i+1,queryLength-i);
			
			frontFound = logString.find(frontHalf,0);

			while(frontFound != string::npos)
			{
				lastFound = logString.find(lastHalf,frontFound);

				if((frontFound+i+1)==lastFound)	//找到了，中间一个不一致
				{
					cout<<"中间可变:"<<frontFound<<" "<<frontFound+queryLength;
				}

				frontFound = logString.find(frontHalf,frontFound+1);
			}
		}
	}




}

int main()
{
	string logString="abdbcbdbdressa";
	string queryString="dress";


	cout<<logString<<" "<<queryString;
	queryWordFromLog(logString,queryString);
	return 0;
}
