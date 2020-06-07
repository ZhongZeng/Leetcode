/*
1471. The k Strongest Values in an Array

Medium
Companies	Google
Related Topics	Array, Sort

Test Cases:
[1,2,3,4,5]
2
[1,1,3,5,5]
2
[6,7,11,7,6,8]
5
[6,-3,7,2,11]
3
[-7,22,17,3]
2

Runtime: 796 ms	Your runtime beats 75.00 % of cpp submissions.
Memory Usage: 82.8 MB
*/

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
      // Sort, Two-pointer; O(n*log(n)) time; k in [1,arr.size()]
      int m;
      vector<int> vc;
      
      sort( arr.begin(), arr.end());
      
      m=arr[(arr.size()-1)/2];
      
      for( int i=0, j=arr.size()-1, t=0; t<k; t++){
        if(isStronger(i,j,m,arr)) vc.push_back(arr[i++]);
        else  vc.push_back(arr[j--]);
      }
      
      return vc;
    }
  
protected:
    bool isStronger( int i, int j, int & m, vector<int> & arr){
      int a=abs(arr[i]-m), b=abs(arr[j]-m);
      if( a>b ) return true;
      else if( a<b )  return false;
      else  return i>j;
    }
};