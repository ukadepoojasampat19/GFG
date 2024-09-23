//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    unordered_map<char,int> mp;
    int l=0;
    int r=0;
    int max_len = INT_MIN;
    while(r < S.length())
    {
         mp[S[r]]++;
        while(mp[S[r]] > 1)
        {
           
                mp[S[l]]--;
                l++;
            
        }
       
        max_len = max(max_len, r-l+1);
        r++;
        
    }
    
    return max_len;
}