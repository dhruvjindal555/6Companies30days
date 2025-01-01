class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]){
            return a[1] > b[1];
        }else{
            return a[0]<b[0];
        }
    } 
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), cmp);

        int maxEnvelope = 0;
        vector<int> result;
        result.push_back(envelopes[0][1]);
        for(int i=0; i<n; i++){
            if(envelopes[i][1] > result.back()){
                result.push_back(envelopes[i][1]);
            }else{
                int idx = lower_bound(result.begin(), result.end(), envelopes[i][1]) - result.begin();
                result[idx] = envelopes[i][1];
            }
        }
        return result.size();
    }
};