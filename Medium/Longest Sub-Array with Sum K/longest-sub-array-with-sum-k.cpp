//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        unordered_map<int, int> sumMap; // Map to store prefix sum and its corresponding index
        int maxLen = 0;
        int sum = 0;

        for (int i = 0; i < N; i++) {
            sum += A[i];

            if (sum == K) {
                maxLen = i + 1; // Update maxLen if the sum up to the current index is equal to K
            } else if (sumMap.find(sum - K) != sumMap.end()) {
                maxLen = max(maxLen, i - sumMap[sum - K]); // Update maxLen if a sub-array with sum K is found
            }

            if (sumMap.find(sum) == sumMap.end()) {
                sumMap[sum] = i; // Store the current sum and its index if it is not present in the map
            }
        }

        return maxLen;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends