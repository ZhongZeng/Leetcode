
/*
Leetcode 727. Minimum Window Subsequence

Companies 
Google, eBay 
Related Topics 
Dynamic Programming 
Similar Questions 
Minimum Window Substring, Longest Continuous Increasing Subsequence

Test Cases:
"abcdebdde"
"bde"
"fgrqsqsnodwmxzkzxwqegkndaa"
"fnok"

Runtime: 77 ms
Your runtime beats 74.37 % of cpp submissions.

*/

class Solution {
public:
    string minWindow(string S, string T) {
		int i, j, len=S.size()+1, b, e;
        string rt;
        vector<int> vb, ub; 
		vb.push_back(S[0]!=T[0]?-1:0);
		for( j=1; j<S.size(); j++)	vb.push_back(S[j]!=T[0]?vb.back():j);
        //for(auto e:S)   cout<<e<<" ";   cout<<endl;
        //for(auto e:vb)  cout<<e<<" ";   cout<<endl;
        
		for( i=1; i<T.size(); i++){// begining positions of substring T[:i] in S[:j]
			ub={-1};// begining positions of substring T[:i] in S[:0] while 0<i
			for( j=1; j<S.size(); j++){
				if(T[i]!=S[j])  ub.push_back(ub.back());// T[:i] in S[:j-1] 
				else    ub.push_back(vb[j-1]<ub.back()?ub.back():vb[j-1]);
                // T[:i] in S[:j-1] v.s. T[:i-1] in S[:j-1] 
			}
            //for(auto e:ub)  cout<<e<<" ";   cout<<endl;
			vb=ub;
		}
        
        for( j=0; j<vb.size(); j++){
            if(-1<vb[j]&&j-vb[j]<len){
                b=vb[j];
                e=j;
                len=j-vb[j];
            }
        }
		
		if(len<vb.size()+1) for( i=b; i<=e; i++)    rt.push_back(S[i]);
        
        return rt;
    }
};
