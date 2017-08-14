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
 * 思想:可以这么考虑，回文，那么必须会有重复，我们可以先将字符串进行按字典排序，可以得到重复的字母个数，然后再接下来扫描原有的字符串来考虑需要删除多少
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
	string inputStr;
	vector<char> vecChar;
	cin>>inputStr;

	for(int i=0;i<inputStr.size();i++)
	{
		vecChar.push_back();
	}
	return 0;
}
