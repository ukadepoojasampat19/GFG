//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    
    void  permute(string S,int st,set<string>& res)
    {
        if(st == S.length())
        {
            res.insert(S);
            return;
        }
        
        for(int i=st;i<S.length();i++)
        {
            swap(S[st],S[i]);
            permute(S,st+1,res);
            swap(S[st],S[i]);
        }
    }
	public:
		vector<string>find_permutation(string S)
		{
		    set<string> res;
		   
		    permute(S,0,res);
		    vector<string> result(res.begin(), res.end());
		    return result;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends