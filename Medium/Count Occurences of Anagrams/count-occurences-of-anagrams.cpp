//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    
	    int n=txt.length();
	    int m=pat.length();
	    
	    unordered_map<char,int> txtfre;
	    unordered_map<char,int> patfre;
	    
	    for(int i=0;i<m;i++)
	    {
	        txtfre[txt[i]]++;
	        patfre[pat[i]]++;
	        
	    }
	    
	    int count=0;
	    
	    for(int i=m;i<n;i++)
	    {
	        if(txtfre == patfre)
	        {
	            count++;
	        }
	        
	        txtfre[txt[i-m]]--;
	        if( txtfre[txt[i-m]] == 0)
	        {
	            txtfre.erase(txt[i-m]);
	        }
	          txtfre[txt[i]]++;
	        
	    }
	    
	    if(txtfre == patfre)
	    {
	        count++;
	    }
	    return count;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends