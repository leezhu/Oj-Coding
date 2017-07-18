/*
 *描述:坐标移动，分为awsd上下左右，主要为字符串的处理
 *分情况讨论
 20170718
 */

#include<iostream>
#include<string>
#include<vector>
#include<string.h>
using namespace std;

int main()
{
	string str;
	vector<string> vs;
	string temp;
	int x,y;
	int num;//记录移动的距离
	int len =0;
	const char* ch;//指向坐标
	char c;//方向字母
	cin>>str;
	x = y=0;

	//将字符串以分号进行分割存入列表当中
	size_t pos = 0;
	size_t found = str.find(';',pos);
	while(found!=string::npos)//没有到末尾
	{
		temp = str.substr(pos,found-pos);
		vs.push_back(temp);
		pos = found + 1;
		found = str.find(';',pos);
	}
	//for(int i=0;i<vs.size();i++)
	//	cout<<vs[i]<<endl;
	for(int i=0;i<vs.size();i++)
	{
		num =0;
		ch = vs[i].c_str();
		if(strlen(ch)<2 || strlen(ch)>=4)
			//cout<<vs[i]<<endl;
			continue;
		else
		{
			//得到字母和数字
			c = ch[0];
			//得到数字
			for(int i=1;i<strlen(ch);i++)
			{
				if(ch[i]>='0' && ch[i]<='9')
					num=num*10+ch[i]-'0';
				else
					num=0;
			}

		}
		//cout<<"ch="<<c<<" "<<"num="<<num<<endl;
		switch(c)
		{
			case 'W':
				y+=num;
				break;
			case 'S':
				y-=num;
				break;
			case 'A':
				x-=num;
				break;
			case 'D':
				x+=num;
				break;
			default:
				break;
		}
	}

	cout<<x<<","<<y;
	return 0;
}
