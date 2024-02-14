//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

    void solve(string op,int one,int zero,int N,vector<string>& result)
    {
        if(N == 1)
        {
            result.push_back(op);
          
            return;
        }
       
           
             solve(op + "1",one+1,zero,N-1,result);
       
       if(one >=zero)
       {
           
           solve(op + "0",one,zero+1,N-1,result);
       }
      
       
        
    }
	vector<string> NBitBinary(int N)
	{
	    string op="1";
	    int one=1;
	    int zero=1;
	    vector<string> result;
	    solve(op,one,zero,N,result);
	    return result;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends