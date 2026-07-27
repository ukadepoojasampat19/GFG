class Solution {
  public:
  void upper_bound(int l,int h,int m,int& min_idx,vector<int> arr, int target){
        if(l > h) return;

        m = (l+h)/2;
        if(arr[m] > target){
            min_idx= min(min_idx,m);
           upper_bound(l,m-1,m,min_idx,arr,target);
        }else{
            upper_bound(m+1,h,m,min_idx,arr,target);
        }
     }
    int upperBound(vector<int>& arr, int target) {
        // code here
         int n = arr.size();
        int l =0;
        int h = n-1;
        int min_idx = n;
        int m;
        upper_bound(l,h,m,min_idx,arr,target);

        return min_idx;
    }
};
