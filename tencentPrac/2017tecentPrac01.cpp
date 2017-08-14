/*
 *问题:[编程题] 构造回文
 时间限制：1秒
 空间限制：32768K
 给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何删除才能使得回文串最长呢？
 输出需要删除的字符个数。

 输入描述:

 输入数据有多组，每组包含一个字符串s，且保证:1<=s.length<=1000.
   


 输出描述:

 对于每组数据，输出一个整数，代表最少需要删除的字符个数。

 输入例子1:
 abcda
 google

 输出例子1:
 2
 2
 *
 * 思想:其实这是求回文后的字符和原有字符之间的最长公共子序列，只要找出来后，就可以减去得到需要删除的。这里需要用到动态规划方式
 * 具体详细解答见有道笔记或者http://www.cnblogs.com/grenet/archive/2010/06/03/1750454.html
 *
 * 有公式一
 * 　　若ai=bj，则LCS(i,j)=LCS(i-1,j-1)+1
 * 　　若ai≠bj，则LCS(i,j)=Max(LCS(i-1,j-1),LCS(i-1,j),LCS(i,j-1))
 */

#include<bits/stdc++.h>
using namespace std;
const int MAX=1001;

int MaxLen[MAX][MAX];//最长公共子序列，动态规划求法

int maxLen(string s1,string s2)
{
	int length1 = s1.size();
	int length2 = s2.size();

	//将第一行和第一列都赋值为0
	for(int i=0;i<length1;++i)
		MaxLen[0][i]=0;

	for(int i=0;i<length2;++i)
		MaxLen[i][0]=0;

	//将整个二维数组进行补全，根据动态规划的公式
	for(int i=1;i<=length1;++i)
	{
		for(int j=1;j<=length2;++j)
		{
			if(s1[i-1]==s2[j-1])//因为二维数组一行一列都是为0，字符串也是从0开始
				MaxLen[i][j] = MaxLen[i-1][j]+1;	//如果最后一个相等
			else
			{
				//如果不相等，判断两者者大小
				MaxLen[i][j] = max(MaxLen[i-1][j],MaxLen[i][j-1]);
			}
		}
	}
	return MaxLen[length1][length2];

}
int main()
{
	//字符串也有迭代器，
	string inputStr;

	while(cin>>inputStr)
	{
		int length = inputStr.size();

		if(length==1)	//只有一个的情况下
		{
			cout<<1<<endl;
			continue;
		}

		string s2=inputStr;
		reverse(s2.begin(),s2.end());	//string也有迭代器，可以逆置
		int maxLength = maxLen(inputStr,s2);
		cout<<length - maxLength<<endl;
	}
	return 0;
}
