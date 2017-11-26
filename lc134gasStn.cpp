

/*
Leetcode 134. Gas Station

Related Topics 
Greedy 

Next challenges: Wiggle Subsequence, Queue Reconstruction by Height, 
Minimum Number of Arrows to Burst Balloons

Test Cases:
[4]
[5]
[1,2]
[2,1]
[5]
[4]

Runtime: 6 ms
Your runtime beats 18.89 % of cpp submissions.

*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		// Runtime: 6 ms
		// Your runtime beats 18.89 % of cpp submissions.
        // gas:i->i+1; cost:i->i+1
        // bz ans is unique, it must be + in -+
        // DP
		// l=cost.size()+1: 0(l=cost.size()+1 not triggered) or -1(tot<0) will be returned 
        int sum=0, l=0, tot=0;// sum
              
        for(int j=0; j!=cost.size(); j++){
			tot+=gas[j]-cost[j];
            sum+=gas[j]-cost[j];
            if(sum<0){
                sum=0;
                l=j+1;
            }
        }
                
        return tot<0?-1:l;
    }
};

/*
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Runtime: 6 ms
		// Your runtime beats 18.89 % of cpp submissions.		
        // gas:i->i+1; cost:i->i+1
        // bz ans is unique, it must be + in -+
        int sum=0, l=0;// sum
              
        for(int j=0; j!=cost.size(); j++){
            sum+=gas[j]-cost[j];
            if(sum<0){
                sum=0;
                l=j+1;
            }
        }        
        
        for(int j=0; j!=l; j++ ){
            sum+=gas[j]-cost[j];
            if(sum<0)   return -1;
        }
                
        return l;
    }
};
*/

/*
// Brute Force Method
// Runtime: 49 ms
// You are here! 
// Your runtime beats 4.16 % of cpp submissions.

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // gas:i->i+1; cost:i->i+1
        int c;
        bool b;
        for(int i=0; i!=cost.size() ;i++){
            c=0;
            b=true;
            for(int j=i; j!=cost.size(); j++){
                c+=gas[j]-cost[j];
                if( c<0 ){
                    b=false;
                    break;
                }
            }
            if(b!=true) continue;
            for(int j=0; j!=i; j++){
                c+=gas[j]-cost[j];
                if( c<0 ){
                    b=false;
                    break;
                }
            }            
            if(b!=false)    return i;
        }
        return -1;
    }
};

*/