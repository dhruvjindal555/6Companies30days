class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int s = 0, e = 0, oddCount = 0, res = 0, prefix = 0;

        while (e < n) {
            if (nums[e] % 2 != 0) {
                oddCount++;
                prefix = 0;
            }

            while (oddCount == k) {
                if (nums[s] % 2 != 0) {
                    oddCount--;
                }
                prefix++;
                s++;
            }

            res += prefix;
            e++;
        }
        return res;
    }
};
