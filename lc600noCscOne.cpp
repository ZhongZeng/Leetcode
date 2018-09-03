
/*
Leetcode 600. Non-negative Integers without Consecutive Ones

Companies   
Pocket Gems
Related Topics 
Dynamic Programming 
Similar Questions 
House Robber, House Robber II, Ones and Zeroes

Test Cases:
1
2
3
4
5
10
16

Runtime: 4 ms
Your runtime beats 100.00 % of cpp submissions.

Next challenges: Ones and Zeroes

*/

class Solution {
public:
    int findIntegers(int num) {
        // DP, O(32) time&space 
        num++;
        int sum=0;
        vector<int> bn, vc={1};
        for( int t=num; 0<t; t=t>>1)    bn.push_back(t-(t>>1<<1));
        
        for( int i=1, one=1, zero=0, t; i<bn.size(); i++){// # w/ ==i+1 digits 
            vc.push_back(one+zero);
			t=zero;
			zero=zero+one;
            one=t;
        }
        for( int i=1; i<vc.size(); i++) vc[i]+=vc[i-1];// # w/ <=i+1 digits 
        //for(auto e:vc)  cout<<e<<" ";   cout<<endl;
        
        sum+=vc.back();
		for( int i=bn.size()-2; -1<i; i--){
            if(bn[i+1]==1){
                if(bn[i]==1){
                    sum+=vc[i];
                    break;
                }
            }else{
                if(bn[i]==1)    sum+=vc[i];
            }
        }
		
        return sum;
    }
};
