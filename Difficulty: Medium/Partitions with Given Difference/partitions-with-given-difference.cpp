//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    const int MOD = 1e9 +7;
    int countPartitions(int n, int d, vector<int>& arr) {
       int total_sum = 0;
       for(auto& n: arr)
       {
           total_sum += n;
       }
       int curr_sum = total_sum - d;
       if( curr_sum % 2 != 0 || curr_sum < 0) return 0;
       int target = curr_sum /2;
       
       vector<vector<int>> dp(n+1,vector<int>(target+1,0));
       dp[0][0] =1;
       
       for(int i=1;i<=n;i++)
       {
           for(int j=0;j<=target;j++)
           {
               //not include
               dp[i][j] = dp[i-1][j];
               
               //include
               if(j >= arr[i-1])
               {
                   dp[i][j] = (dp[i][j] + dp[i-1][j - arr[i-1]]) % MOD;
               }
           }
       }
       return dp[n][target];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends