class Solution {
public:
    string longestPalindrome(string s) {
        int frontP=0,backP=0,currentP=0;//前后指针，可以移动来扩张大回文
        string maxPalStr;
        int maxPalLen=0;
        int sLength=s.length();
        cout<<"length="<<sLength<<"*";
        
        maxPalStr=s.substr(0,1);
        for(;currentP<sLength;){
            backP=currentP+1;
            frontP=currentP-1;
            cout<<currentP<<"#";
            //分三种形式下的扩张，分两头，分左右两头
            if( backP<sLength && frontP>=0 && s[backP]==s[frontP] ){ 
            while(true){
               if( backP<sLength && frontP>=0  && s[backP]==s[frontP]){
                  if((backP-frontP+1) > maxPalLen)    //比最长回文长
                    {
                        maxPalStr=s.substr(frontP,backP-frontP+1);
                        maxPalLen=backP-frontP+1;
                    }
                    backP++;
                    frontP--;  
                   }else{
                   currentP++;
                   break;
                   //cout<<"@"<<currentP;
                    }
                }
                //continue;
            }else if(s[backP]==s[currentP] && backP<sLength){  //考虑后移动相同的情况，前移动不考虑，因为后移动已经考虑过了
              while(true){  
                if(s[backP]==s[currentP] && backP<sLength){ //要考虑两种情况，一种是两端增长，另外一种是只往后增长
                 if((backP-currentP+1) > maxPalLen)    //比最长回文长
                    {
                        maxPalStr=s.substr(currentP,backP-currentP+1);
                        maxPalLen=backP-currentP+1;
                    }
                    backP++;
               }else{
                    if(frontP>=0 && s[backP]==s[frontP]){//其实又回到第一种情况
                        if( backP<sLength && frontP>=0 && s[backP]==s[frontP] ){ 
                            while(true){
                               if( backP<sLength && frontP>=0  && s[backP]==s[frontP]){
                                  if((backP-frontP+1) > maxPalLen)    //比最长回文长
                                    {
                                        maxPalStr=s.substr(frontP,backP-frontP+1);
                                        maxPalLen=backP-frontP+1;
                                    }
                                    backP++;
                                    frontP--;  
                                   }else{
                                   currentP++;
                                   break;
                                   //cout<<"@"<<currentP;
                                    }
                                }
                //continue;
                        }
                    }else{
                        currentP++;
                        break;
                    }     
                }
              }
            }else{  //如果达到末尾了，就需要全部退出。代码需要优化
                currentP++;
            }
            
        }
        return maxPalStr;
    }
};
