class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int frontPt;    //前指针
        frontPt  = 0;
        int maxLen;
        int curLen=1; //当前长度
        
        int strSize = s.size();
        if(strSize ==  0)   //初始化长度
            maxLen=0;
        else
            maxLen=1;
         int j;
        for(int i=frontPt+1;i<strSize;i++){
            //循环查找相同字符
            for(j=frontPt;j<i;j++){
                if(s[j]==s[i]){
                    cout<<"j="<<j<<" i="<<i<<endl;
                    frontPt=j+1;  //前指针移动到冲突的下一位
                    if(maxLen<curLen)   //此循环结束，要判定最长长度
                        maxLen = curLen;
                    curLen = i - frontPt +1;    //重新开始的字符串长度
                    break;
                }
            }
            if(j==i)    //说明没有相同字符
                curLen++;
        }
        if(maxLen<curLen && maxLen!=0)   //此循环结束，要判定最长长度
            maxLen = curLen;
        return maxLen;
    }
};
