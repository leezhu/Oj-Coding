/*
 *题目描述
 输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
 输入描述:
 输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
 *
 * 解法：就是不断的交换，用递归的方式，第一个和后面都交换了，就确定了第一个，然后是就全是后面再全排序，
 * 需要注意是的需要去重和排序，sort
 */

class Solution {
public:
    vector<string> result;
    vector<string> Permutation(string str) {
        if(str.size()==0 || str.size()>9)
            return result;
        
        getPermu(str,0);
        sort(result.begin(),result.end());
        return result;
    }
    
    void getPermu(string& str1,int begin)
        {
        if(str1.size()-1==begin)
            result.push_back(str1);
        else
        //这个地方要去重
            {
            for(int i=begin;i<str1.size();i++)
                {
               //swap(str1[begin],str1[i]);	//交换当前的，和后面的
               
                char temp;
                if(str1[begin]!=str1[i] || i==begin)
                {
                    
                temp=str1[begin];
                str1[begin]=str1[i];
                str1[i]=temp;
                
                
                getPermu(str1,begin+1);
                
                temp=str1[begin];
                str1[begin]=str1[i];
                str1[i]=temp;
                }
                
            }
        }
        
    }
    
};
