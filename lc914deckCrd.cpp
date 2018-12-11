/*914. X of a Kind in a Deck of Cards

Related Topics: Array, Math 

Test Cases:

[1,2,3,4,4,3,2,1]
[1,1,1,2,2,2,3,3]
[1]
[1,1]
[1,1,2,2,2,2]
[1,1,1,1,2,2,2,2,2,2]

Runtime: 12 ms, faster than 75.06% of C++ online submissions for X of a Kind in a Deck of Cards.

*/

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        // O(n*m) time & O(n) space
		if(deck.size()<2)	return false;
		int c;
        unordered_map<int,int> um;
		unordered_map<int,int>::iterator umi;
		
		for( int i=0; i<deck.size(); i++){
			umi=um.find(deck[i]);
			if(umi!=um.end())	umi->second+=1;
			else	um.emplace(deck[i],1);
		}
		
		// find largest common divider 
		for( umi=um.begin(), c=umi->second; umi!=um.end(); umi++ ){
			c=largestCommonDivider(c,umi->second);
			if(c==1)	return false;
		}
		
		return true;
    }
	
	int largestCommonDivider( int a, int b){// a,b >=1
		int r; 
		while(true){
			if(a<b){
				r=b%a;
				if(r==0)	return a;
				else	b=r;
			}else{
				r=a%b;
				if(r==0)	return b;
				else	a=r;
			}
		}
		return a;
	}
};