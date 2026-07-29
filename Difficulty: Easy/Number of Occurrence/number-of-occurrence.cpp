class Solution {
  public:
  void first_occur(int l,int h,vector<int>& arr,int target,int& first_occ){
        while( l<=h){
            int m = (l+h)/2;

            if(arr[m] == target){
                first_occ = m;
                h=m-1;
            }else if(arr[m] < target){
                l=m+1;
            }else{
                h = m-1;
            }
        }
      }
         void last_occur(int l,int h,vector<int>& arr,int target,int& last_occ){
        while( l<=h){
            int m = (l+h)/2;

            if(arr[m] == target){
                last_occ = m;
                l= m+1;
            }else if(arr[m] < target){
                l=m+1;
            }else{
                h = m-1;
            }
        }
      }
    int countFreq(vector<int>& arr, int target) {
        int n = arr.size();
      int l=0;
      int first_occ = -1;
      int last_occ = -1;
      int h=n-1;

      first_occur(l,h,arr,target,first_occ);
      last_occur(l,h,arr,target,last_occ);
    if(first_occ == -1 & last_occ == -1) return 0;
      return (last_occ - first_occ + 1);
        
    }
};
