
/*
Leetcode 372. Super Pow

Companies  
Airbnb, Facebook 
Related Topics 
Math 
Similar Questions 
Pow(x, n)

Next challenges: Encode and Decode TinyURL, 4 Keys Keyboard, Transform to Chessboard

Test Cases: 
1564
[3]
1564
[3,3,5,6,1,3,4,9,0,4]
1
[4,3,3,8,5,2]
0
[4,3,3,8,5,2]
2147483647
[2,0,0]

Runtime: 4 ms
Your runtime beats 100.00 % of cpp submissions.

*/

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        // O(n+1337) time; a**b%m=(a%m)**b%m, a*b%m=(a%m)*(b%m)%m 
        int r, ct, i; 
        vector<int> vc;
		unordered_map<int,int> um;
        a=a%1337;
        
		for( r=a, ct=0; um.find(r)==um.end(); ct++){
            //cout<<r<<" ";
			um.emplace(r,ct);
			vc.push_back(r);
			
			r=a*r%1337;
		}
		
        for( i=0, r=0; i<b.size(); i++){ // calculate b%vc.size() 
			r=(r*10+b[i])%vc.size();
		}
        
        return vc[r!=0?r-1:0];
    }
};
