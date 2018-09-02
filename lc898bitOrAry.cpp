


/*
Leetcode 898. Bitwise ORs of Subarrays

Related Topics 
Dynamic Programming, Bit Manupulation 

Test Cases:
[0]
[1,1,2]
[1,2,4]

Runtime: 1104 ms

*/

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        // DP 
        unordered_set<int> us, u1, u2;
        unordered_set<int>::iterator usi;
        
        for( int i=0, t; i<A.size(); i++){
            u2.clear();
            if(u1.find(0)==u1.end()) u1.emplace(0);
            for( usi=u1.begin(); usi!=u1.end(); usi++){
                t=(*usi)|A[i];
                //cout<<t<<" ";
                if(u2.find(t)==u2.end())    u2.emplace(t);
                if(us.find(t)==us.end())    us.emplace(t);
            }
            u1=u2;
            //cout<<endl;
        }
        
        return us.size(); 
    }
};

/*
// previously thought about bit manipulatioin 
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        // DP; 0 <= A[i] <= 10^9; 1 <= A.length <= 50000
        int sum=0, len, i, j;
        
        vector<int> vc(32,0);
        vector<vector<int> vv;
        vv.push_back(vc);
        
        for( i=0; i<A.size(); i++){
            vc.clear();
            for( j=0, t=A[i]; j<32; j++, t=t>>1)    vc.push_back( t-(t>>1<<1) );
            
            for( len=vv.size(), j=0; j<len; j++){
                for( int k=0;)
                
            }
        }
        
        return vv.size();
    }
    
    
    
};

*/