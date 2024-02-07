//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    
    void bk(vector<vector<int>> &ans , vector<int> &arr , vector<int> &curr , int idx){
        ans.push_back(curr);
        
        
        for(int i = idx ; i < arr.size() ; i++){
            if(i!=idx && arr[i]==arr[i-1]){
                continue;
            }
            curr.push_back(arr[i]);
            bk(ans,arr,curr,i+1);
            curr.pop_back();
        }
    }
    
    public:
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        sort(arr.begin(),arr.end());
        vector<vector<int> > ans;
        vector<int> curr;
        bk(ans , arr , curr ,0);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   



// } Driver Code Ends