/*686. Repeated String Match

Related Topics: String 
Similiar Questions: Repeated Substring Pattern

Test Cases:
"aaaaaaaaaaaaaaaaaaaaa"
"bacbacbac"
"aabaa"
"aaab"
"baaaabbbba"
"bbaaaabbbbaabaaaabbbbaabaaaabbbbaabaaaabbbbaabaaaabbbbabbaaaabbbbabbaaaabbbbabbaaaabbbbabbaaaabbbbaa"
"ab"
"abab"
"aaac"
"aac"
"abcd"
"cdabcdab"
"ab"
"ab"

Runtime: 4 ms
Your runtime beats 99.45 % of cpp submissions.

*/

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        // KMP, O(m+n) time 
		int i, t, rt=1;
		vector<int> nx(B.size(),-1);
		
		for( i=0, t=-1; i<B.size()-1; ){
			if(t==-1||B[i]==B[t])	nx[++i]=++t;
			else	t=nx[t];
		}
		
		for( i=0, t=0; rt<=2; ){// t: length of match B[0,t) 
			if(t==-1||A[i]==B[t]){
				i++;
				t++;
			}else{
				t=nx[t];
			}
            if(t==B.size())	return rt;// B matched 
            if(i==A.size()){
				i=0;
				rt++;
			}
		}
		
		if(t==0)	return -1;
		for( ; t<B.size(); ){
			if(i==A.size()){
				i=0;
				rt++;
			}
			if(A[i]==B[t]){
				i++;
				t++;
			}else{
				return -1;
			}
		}
		
		return rt;
    }
};