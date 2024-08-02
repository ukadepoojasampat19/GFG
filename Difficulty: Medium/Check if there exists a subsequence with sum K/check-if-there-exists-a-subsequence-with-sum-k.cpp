//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    bool recurr(int idx,vector<int>& arr,int sum,int k,vector<vector<int>>& dp)
    {
        if( sum == k) return true;
        if(idx >= arr.size() || sum > k) return false;
        
        if(dp[idx][sum] != -1) return dp[idx][sum];
        
        bool include = recurr(idx+1,arr,sum + arr[idx],k,dp);
        bool exclude = recurr(idx+1,arr,sum,k,dp);
        
        dp[idx][sum] = include || exclude;
        return dp[idx][sum];
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        
        
        vector<vector<int>> dp(n, vector<int>(k+1,-1));
        
        return recurr(0,arr,0,k,dp);
        // Code here
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        bool ans = obj.checkSubsequenceSum(n, arr, k);
        cout<<( ans ? "Yes" : "No")<<"\n";
    }
    return 0;
}
// } Driver Code Ends