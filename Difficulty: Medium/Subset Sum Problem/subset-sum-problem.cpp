//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++
 
class Solution{   
public:
    int count_sum(int idx,int k,vector<int> arr,int sum,vector<vector<int>>& dp)
    {
        if( idx == arr.size())
        {
            return (k == sum)? 1: 0;
        }
        
        //if k > sum
        if( k > sum) return 0;
        
        if(dp[idx][k] != -1) return dp[idx][k];
        int l = count_sum(idx+1,k + arr[idx],arr,sum,dp);
        int r = count_sum(idx+1,k,arr,sum,dp);
        
        return dp[idx][k] = l+r;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        
        vector<vector<int>> dp(arr.size()+1, vector<int>(sum+1, -1));
       return count_sum(0,0,arr,sum,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends