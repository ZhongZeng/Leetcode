
/*
Leetcode 43. Multiply Strings

Related Topics: Math, String 
Similiar Questions:Add Two Numbers, Plus One, Add Binary, Add Strings


Runtime: 8 ms
Your runtime beats 55.47 % of cpp submissions.

*/

class Solution {
public:
    string multiply(string num1, string num2) {
		// O(m*n) time 
        vector<int> p(num1.size()+num2.size()+1,0);
		string rt;
		char c;
        int sz, l=0;
		
		for( int t, i=num1.size()-1, i0=0; -1<i; i--, i0++){
			for( int j=num2.size()-1, j0=0; -1<j; j--, j0++){
				p[i0+j0]+=(num1[i]-'0')*(num2[j]-'0');
			}
		}
        //for(auto e:p)   cout<<e<<" ";   cout<<endl;
        
        for( sz=p.size()-1; -1<sz&&p[sz]==0; sz--){}
        
		for( int i=0; i<=sz; i++){
			l=p[i]+l;
			rt.push_back((char)(l%10+'0'));
			l=l/10;
		}
        
        for( ; 0<l; l/=10)  rt.push_back((char)(l%10+'0'));
		
		for( int i=0, j=rt.size()-1; i<j; i++, j--){// reverse the result 
			c=rt[i];
			rt[i]=rt[j];
			rt[j]=c;
		}
		
		return rt.empty()?"0":rt;
    }
};
