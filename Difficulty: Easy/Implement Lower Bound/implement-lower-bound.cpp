class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
              int n = arr.size();
        int min_idx = n;
        int l = 0;
        int h = n-1;
        int mid;

        while(l <= h){
            mid = (l+h)/2;
            if(arr[mid] >=  target){
                min_idx =  min(min_idx,mid);
                
            }
            if(target > arr[mid]){
                l = mid+1;
            }else{
                h = mid-1;
            }

        } 
        return min_idx;
        
    }
};
