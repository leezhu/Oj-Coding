/*
 *问题:[编程题] 算法基础-字符移位
 时间限制：1秒
 空间限制：32768K
 小Q最近遇到了一个难题：把一个字符串的大写字母放到字符串的后面，各个字符的相对位置不变，且不能申请额外的空间。
 你能帮帮小Q吗？


 输入描述:

 输入数据有多组，每组包含一个字符串s，且保证:1<=s.length<=1000.
   


 输出描述:

 对于每组数据，输出移位后的字符串。

 输入例子1:
 AkleBiCeilD

 输出例子1:
 kleieilABCD
 *
 * 思想:方法一：从后往前替换，当遇到大写字母就往前移动,复杂度为O(n),方法二可以直接先输出大写字母，然后输出小写字母，这样岂不更好
 */

#include<bits/stdc++.h>
using namespace std;

void characterMove(string& str)
{
	int length = str.size();
	int frontUpper=0,backUpper=length-1; //记录前后两个大写的位置
	char tempCharc;

	for(int i=length-1;i>=0;i--)
	{
		if(isupper(str[i]))//如果是大写
		{
			frontUpper = i;
			//进行移动替换
			tempCharc = str[i];//记录当前大写字母
			for(int j=frontUpper;j<backUpper;j++)
			{
				str[j]=str[j+1];	//从前往后复制
			}


			if(frontUpper != backUpper)
			{
				if(isupper(str[backUpper]))	//需要区分最后一个开始是否是小写和大写，比如为Acc，那么最后一个需要替换成大写
				{							//如果仅仅只是AcB，那么只需要替换前一个
					str[backUpper-1]=tempCharc;
						backUpper --;
				}
				else
					str[backUpper]=tempCharc;
			}


		}
	}

	cout<<str<<endl;
}

int main()
{
	string inputStr;

	cin>>inputStr;

	characterMove(inputStr);
	return 0;
}
