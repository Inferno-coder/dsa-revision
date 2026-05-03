//Range Sum Query – Immutable
class NumArray {
public:
    vector<int>prefixSum;
    NumArray(vector<int>& nums) {
        int sum=0;
        prefixSum.resize(nums.size(),0);
        for(int i=0;i<nums.size();i++){
          prefixSum[i]=sum+nums[i];
          sum+=nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0)return prefixSum[right];
        return prefixSum[right]-prefixSum[left-1];
    }
};

//Find the pivot index of the array

class Solution {
public:
    vector<int>prefix;
    int pivotIndex(vector<int>& nums) {
       int sum=0;
       int n=nums.size();
       prefix.resize(n);
       for(int i=0;i<n;i++){
        prefix[i]=sum+nums[i];
        sum+=nums[i];
       }
       if(sum-nums[0]==0)return 0;
       for(int i=1;i<=n-2;i++){
        int leftSum=prefix[i-1];
        int rightSum=prefix[n-1]-prefix[i];
        if(leftSum==rightSum)return i;
       }
       if(sum-nums[n-1]==0)return n-1;
       return -1;
    }
};

//subarray sum equals k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>countMap;
        countMap[0]=1;
        int tot=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            tot+=countMap[sum-k];
            countMap[sum]++;
        }
        return tot;
    }
};

//binary subarray with sum
class Solution {
public:
    int find(vector<int> nums, int goal) {
        if(goal<0) return 0;
        int currsum = 0, left = 0,count=0;
        for (int i = 0; i < nums.size(); i++) {
            currsum += nums[i];
            while (currsum > goal) {
                currsum -= nums[left];
                left++;
            }
            count += (i - left + 1);
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return find(nums, goal) - find(nums, goal - 1);
    }
};


//count number of nice substrings
class Solution {
public:
    int atMostKOddValues(vector<int>&nums,int k){
        int count=0,odd=0,left=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right] % 2 != 0) odd++; 
            while(odd>k && left<=right){
                if(nums[left]%2!=0)odd--;
                left++;
            }
            count+=right-left+1;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostKOddValues(nums,k)-atMostKOddValues(nums,k-1);
    }
};
