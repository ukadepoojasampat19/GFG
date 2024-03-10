//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k) {
    int i = 0;
    int j = 0;
    bool check = false;

    list<int> myList;
    vector<long long> res;

    while (j < n) {
        if (arr[j] < 0) {
            myList.push_back(arr[j]);
        }

        if ((j - i + 1) == k) {
            if (myList.empty()) {
                res.push_back(0);
            } else {
                res.push_back(myList.front());
                if(arr[i] == myList.front())
                {
                      myList.pop_front();
                }
              
            }

          

            i++;
        }

        j++;
    }

    return res;
}
