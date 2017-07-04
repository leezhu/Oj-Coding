/********************
 * ************
 */

#include<iostream>
#include<string>
#include<ctype.h>
#include<math.h>
using namespace std;

int main()
{
	string s;
	int length;
	int result;
	int value;
	

	cin>>s;
	result = 0;
	length = s.size();
	for(int i=2;i<length;i++)
	{
		if(isalpha(s[i]))
		{
			value = s[i]-'A'+10;
		}else{
			value = s[i]-'0';	
		}
		result +=value*pow(16,length-1-i);	
	}
	cout<<std::to_string(result)<<endl;

	return 0;
}
