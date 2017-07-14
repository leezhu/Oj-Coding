/*
 *描述:华为机试第四题，字符串分隔，基本思想就是先补0，然后在换行输出
 *时间:2017年7月3日
 */
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	int i=0;
	char s1[101]={0};
	while(cin>>s){
		i=0;
		while(s[i++]!='\0')
			s1[i]=s[i];
		for(int i=0;i<101;i+=9){
			if(s1[i]!='0')
			{	for(int j=i;j<=i+9;j++)
				{
					cout<<s1[j];
				}
				cout<<endl;
			}else{
				break;
			}
		}
	}
	return 0;
}
