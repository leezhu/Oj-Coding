/*
 *题目描述
 在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置
 *
 *
 */



class Solution {
public:
    int FirstNotRepeatingChar(string str) {
       int flag[256]={0};
        
        int len=str.size();

        
        if(len==0)
            return -1;
        
        for(int i=0;i<len;i++)
            {
            	flag[str[i]]++;
        }

        for(int i=0;i<len;i++)
            if(flag[str[i]]==1)
                return i;
        return 0;
    }
};
