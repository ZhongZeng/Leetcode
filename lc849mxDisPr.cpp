
/*
Leetcode 849. Maximize Distance to Closest Person

Test Cases:
[1,0,0,0,1,0,1]
[1,0,0,0]
[0,0,0,1]

Runtime: 15 ms

*/

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        // O(n) time, calculate max distance b/t two 1s
        // There is at least one empty seat, and at least one person sitting. 
        int mx, d=0, i;
        
        for( i=0; i<seats.size(); i++){
            if(seats[i]!=1){
                d++;
            }else{
                break;
            }
        }
        mx=d*2;
        d=0;
        
        while( ++i<seats.size() ){
            if(seats[i]!=1){
                d++;
            }else{
                mx=mx<d+1?d+1:mx;
                d=0;
            }
            //cout<<d<<" ";
        }
        mx=mx<d*2?d*2:mx;
        
        return mx/2;
    }
};


/*
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        // O(n*n) time is trivial; O(n) time, 2 passes, O(1) space, Array; similar idea to total tree distance 
        // There is at least one empty seat, and at least one person sitting. 
        int td=0, mx=0, sum=0;// total&max distance, # person 
        
        for( int i=0; i<seats.size(); i++){
            if(seats[i]!=0){
                td+=i;
                seats[i]=sum;// # person to its left 
                sum++;
            }
        }
        cout<<td<<" "<<sum<<endl;
        
        for( int i=1; i<seats.size(); i++){
            td=td+seats[i]-(sum-seats[i]);
            if(seats[i]!=1&&mx<td)  mx=td;
        }
        
        return mx;
    }
};
*/