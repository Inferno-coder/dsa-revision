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

// Contiguous Array - maximum length of a contiguous subarray with an equal number of 0 and 1
 int findMaxLength(vector<int>& nums) {
        int pre=0,mx=0;
        map<int,int>sumIndexMap;
        sumIndexMap[0]=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)pre-=1;
            else pre+=1;
            if(sumIndexMap.find(pre)!=sumIndexMap.end()){
                mx=max(mx,i-sumIndexMap[pre]);
            }
            else sumIndexMap[pre]=i;
        }
        return mx;
    }


// XOR queries of subarray
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>pre;
        int xr=0;
        for(int i=0;i<arr.size();i++){
            pre.push_back(arr[i]^xr);
            xr^=arr[i];
        }
        vector<int>res;
        for(auto it:queries){
            int start=it[0];
            int end=it[1];
            if(start == 0)
                res.push_back(pre[end]);
            else
                res.push_back(pre[end] ^ pre[start - 1]);
        }
        return res;
    }
};

// valid triplets for xor
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            int xr = arr[i];
            for(int k = i + 1; k < n; k++) {
                xr ^= arr[k];
                if(xr == 0) {
                    res += (k - i);
                }
            }
        }
        return res;
    }
};

//Range sum query 2D
class NumMatrix {
public:
    vector<vector<int>>pre;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        pre.resize(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int left=j>0 ?pre[i][j-1]:0;
                int top=i>0?pre[i-1][j]:0;
                int common=(i>0 && j>0)?pre[i-1][j-1]:0;
                pre[i][j]=matrix[i][j]+left+top-common;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int left=col1>0?pre[row2][col1-1]:0;
        int top= row1>0?pre[row1-1][col2]:0;
        int common=(row1>0 && col1>0)?pre[row1-1][col1-1]:0;
        return pre[row2][col2]-left-top+common;
    }
};
