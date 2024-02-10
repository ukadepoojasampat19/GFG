//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

    void  subset(string& S, vector<string>& ans,string curr,int idx)
    {
        if(idx == S.size())
        {
            ans.push_back(curr);
            return;
        }
        subset(S,ans,curr + " " + S[idx],idx+1);
        subset(S,ans,curr + S[idx],idx+1);
      
        
       
      /*  curr+=S[idx];
        curr+=" ";
        subset(S,ans,curr,idx+1);
      
        curr.pop_back();
        curr.pop_back();
        
        curr += S[idx];*/
       //subset(S,ans,curr,idx+1);
        // curr.pop_back();
        
        
        
        
        
    }
    vector<string> permutation(string S){
        vector<string> ans;
        string curr(1,S[0]);
       // curr=S[0];
        subset(S,ans,curr,1);
       // sort(ans.begin(),ans.end());
        return ans;
       
    }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends