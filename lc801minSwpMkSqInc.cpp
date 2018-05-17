
/*
Leetcode 801. Minimum Swaps To Make Sequences Increasing

Companies 
Facebook, Amazon
Related Topics 
Dynamic Programming

Test Cases:
[1,3,5,4]
[1,2,3,7]
[0,7,8,10,10,11,12,13,19,18]
[4,4,5,7,11,14,15,16,17,20]

Next challenges: Unique Binary Search Trees II, Coin Change, Sentence Screen Fitting

Runtime: 15 ms
Your runtime beats 71.24 % of cpp submissions.

*/

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int a=0, b=1, t; // no, swap @ i
		
		for(int i=1; i<A.size(); i++){
			if(A[i-1]<A[i]&&B[i-1]<B[i]){// no swap 
				if(B[i-1]<A[i]&&A[i-1]<B[i]){// swap 
					if(a<b)	b=a;
					else	a=b;
					b+=1;
				}else{
					b+=1;
				}
			}else{// B[i-1]<A[i]&&A[i-1]<B[i] must be true 
				t=a;
				a=b;
				b=t+1;
			}
		}
		
		return a<b?a:b;
    }
};
