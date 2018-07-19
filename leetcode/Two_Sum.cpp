class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> nuMap;
        int nSize=nums.size();
        
        for(int i=0;i<nSize;i++)
        {
            nuMap.insert(pair<int,int>(nums[i],i));
        }
        
        int value;
        vector<int> result;
        for(int i=0;i<nSize;i++)
        {
            value=target-nums[i];
            auto search=nuMap.find(value);
            if(search !=nuMap.end() && search->second!=i)    //不能是其本身，例如target=0,值也为0
                {
                result.push_back(i);
                result.push_back(search->second);
                    return result;
            }
        }

    }
};
