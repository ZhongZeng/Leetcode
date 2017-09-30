

/*
Leetcode 667. Beautiful Arrangement II

Related Topics 
Array 
Similar Questions 
Beautiful Arrangement 

Next challenges: Beautiful Arrangement

Runtime: 52 ms
You are here! 
Your runtime beats 3.05 % of cpp submissions.

Runtime: 29 ms
You are here! 
Your runtime beats 32.63 % of cpp submissions.

*/


class Solution {
public:
    vector<int> constructArray(int n, int k) {    
        // I thought there should be many acceptable outcomes. 
        vector<int> vc={1}; 
        int i=k;
        while( i!=0 ){
            vc.push_back( *vc.rbegin()+i-- );
            if( i!=0 ){
                vc.push_back( *vc.rbegin()-i-- );
            }else{
                break;
            }
        }
        
        i=k+2;
        while( i!=n+1 ){
            vc.push_back( i++ );
        }
        
        return vc;
    }
};
