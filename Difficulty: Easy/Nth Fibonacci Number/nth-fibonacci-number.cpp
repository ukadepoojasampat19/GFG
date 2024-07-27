//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
   int fib(int n, vector<long long>& memo)
   {
       if(n == 1 || n == 2) return 1;
       if(memo[n]!= -1) return memo[n];
       
       memo[n] = (fib(n-1,memo)+fib(n-2,memo)) % 1000000007;
       return memo[n];
   }
    int nthFibonacci(int n){
        //iterative
       /* if(n ==1 || n==2) return 1;
       long long a=1,b=1;
       for(int i=3;i<=n;i++)
       {
           long long sum = (a+b) % 1000000007;
           a=b;
           b=sum;
       }
       return b;*/
       //recursive
       vector<long long> memo(n+1,-1);
       return fib(n,memo);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends