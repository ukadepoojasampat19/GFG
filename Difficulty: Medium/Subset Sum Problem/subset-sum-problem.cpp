//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool idExists(int idx,int k,vector<int>arr,int sum,vector<vector<int>> & dp)
    {
        if( sum == k) return true;
        
        if( k > sum || idx == arr.size()) return false;
        
        if(dp[idx][k] != -1) return dp[idx][k];
        
        bool include = idExists(idx+1,k + arr[idx],arr,sum,dp);
        bool exclude = idExists(idx+1,k,arr,sum,dp);
        
        
        dp[idx][k] = include || exclude;
        return dp[idx][k];
    }
    bool isSubsetSum(vector<int>arr, int sum){
        vector<vector<int>> dp(arr.size()+1,vector<int>(sum+1,-1));
        return idExists(0,0,arr,sum,dp);
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