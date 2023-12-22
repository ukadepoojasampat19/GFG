//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        priority_queue <int,vector<int> , greater<int>> minhp;
        vector <int> arr1;
        for(int i=0;i<N;i++)
        {
            minhp.push(A[i]);
        }
       while(!minhp.empty())
       {
           arr1.push_back(minhp.top());
           minhp.pop();
       }
       int a=arr1[K1-1];
       int b=arr1[K2-1];
       int sum=0;
        for(int i=0;i<N;i++)
        {
            if(arr1[i] > a && arr1[i] < b)
            {
                sum +=arr1[i];
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends