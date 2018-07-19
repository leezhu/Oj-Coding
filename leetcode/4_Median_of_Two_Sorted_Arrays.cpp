class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sortArr;
        int size1=nums1.size();
        int size2=nums2.size();
        int i=0,j=0;

        //排序成一个数组
        while(i<size1 || j<size2){
            if(i<size1 && j<size2){
                if(nums1[i]<nums2[j]){  //取小的放入排序队列
                    sortArr.push_back(nums1[i]);
                    i++;    //指针往后走
                }else if(nums1[i]>nums2[j]){
                    sortArr.push_back(nums2[j]);
                    j++;    //指针往后走
                }else{
                    sortArr.push_back(nums2[j]);
                    sortArr.push_back(nums2[j]);
                    j++;
                    i++;
                }
            }else if(i<size1){ //数组2已经到达末尾，只需将此队列加入到末尾就行
                while(i<size1){
                    sortArr.push_back(nums1[i]);
                    i++;
                }
                break;
            }else if(j<size2){
                while(j<size2){
                    sortArr.push_back(nums2[j]);
                    j++;
                }
                break;
            }
        }

        //test

        //求中位数
      int sortSize = size1+size2;
        double value = sortSize%2 == 0? (sortArr[sortSize/2-1]+sortArr[sortSize/2])*1.0/2 : sortArr[(sortSize-1)/2];
        return value;

    }
};
