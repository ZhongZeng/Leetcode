/*
5455. Minimum Number of Days to Make m Bouquets

Companies	Google
Related Topics	Array, Binary Search

Test Cases:
[1,10,3,10,2]
3
1
[1,10,3,10,2]
3
2
[7,7,7,7,12,7,7]
2
3
[1000000000,1000000000]
1
1
[1,10,2,9,3,8,4,7,5,6]
4
2

Runtime: 580 ms	Your runtime beats 40.00 % of cpp submissions.
Memory Usage: 63.3 MB
*/

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        // Binary Search, O(n*log(10**9)) time; k sets of non-overlapping consecutive k elements in bloomDay; bloomDay[i] in [1,10**9]
        if(totalBlooms(bloomDay, 1000000000, k)<m)  return -1;
        int b=0, e=1000000000;// (b,e]
        while( b<e-1 ){
            int mid=b+(e-b+1)/2, blm=0;
            if(totalBlooms(bloomDay, mid, k)<m) b=mid;
            else    e=mid;
        }
        return e;
    }
    
protected:
    int totalBlooms( vector<int>& bloomDay, int day, int k){
        // Greedy, O(n) time
        int blm=0;
        for( int i=0, c=0; i<bloomDay.size(); i++){
            if(bloomDay[i]<=day){
                c++;
                if(k==c){
                    blm++;
                    c=0;
                }
            }else{
                c=0;
            }
        }
        return blm;
    }
};