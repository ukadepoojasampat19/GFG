//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
int mod = 1e9 + 7;

int sub(int arr[], int sum, int n, int idx, int currSum, vector<vector<int>>& dp) {
    if (idx == n) {
        return (currSum == sum) ? 1 : 0;
    }
    
    if (currSum > sum) return 0;
    
    if (dp[idx][currSum] != -1) return dp[idx][currSum];
    
    int take = sub(arr, sum, n, idx + 1, currSum + arr[idx], dp);
    int notTake = sub(arr, sum, n, idx + 1, currSum, dp);
    
    return dp[idx][currSum] = (take + notTake) % mod;
}

int perfectSum(int arr[], int n, int sum) {
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return sub(arr, sum, n, 0, 0, dp);
}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends