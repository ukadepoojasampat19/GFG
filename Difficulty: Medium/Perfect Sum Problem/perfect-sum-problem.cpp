//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = 1e9 +7;
	/*int fun(int arr[],int n,int sum,int idx,int curr_sum,vector<vector<int>>& dp)
	{
	    if(idx == n)
	    {
	        return ( curr_sum == sum)? 1:0;
	    }
	    if(curr_sum > sum) return 0;
	    
	    if(dp[idx][curr_sum] != -1) return dp[idx][curr_sum];
	    int taken = fun(arr,n,sum,idx+1,curr_sum + arr[idx],dp);
	    int notaken = fun(arr,n,sum,idx+1,curr_sum,dp);
	    
	    return dp[idx][curr_sum] = (taken+notaken) % mod;
	}*/
	int perfectSum(int arr[], int n, int sum)
	{
	    /*vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return fun(arr,n,sum,0,0,dp);*/
        
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        
        dp[0][0] =1;
        
        for(int i=1;i<=n;i++)
        {
            
            for(int j=0;j<=sum;j++)
            {
                //not include 
                dp[i][j] = dp[i-1][j];
                
                //include the element
                if(arr[i-1] <= j)
                {
                    dp[i][j] = (dp[i][j] + dp[i-1][j - arr[i-1]]) % mod;
                }
            }
        }
        return dp[n][sum];
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