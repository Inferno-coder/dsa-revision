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
