/*
1156. Swap For Longest Repeated Character Substring

Test Cases:
"ababa"
"aaabaaa"
"aaabbaaa"
"aaaaa"
"abcdef"
"babbbbbbbbbbbbaababbaabaabaaaaaaaaabbbababba"
*/

class Solution {
public:
    int maxRepOpt1(string text) {
        // O(n) time, O(1) space; array, string
        if(text.size()<2)   return text.size();
        int mx=1, t, l;
        vector<char> vt(3,text[0]);// text char
        vector<int> vl{0,0,1}, vc(26,0);// vl: length; vc: if not only lowercase letters, use hash table 
        for( int i=0; i<text.size(); i++)   vc[text[i]-'a']+=1;
        
        for( int i=0; i<text.size(); i++){
            if(i==text.size()-1||text[i+1]!=vt.back()){
                //for(auto e:vt)  cout<<e<<" ";   cout<<endl;
                //for(auto e:vl)  cout<<e<<" ";   cout<<endl;
                if(vt[0]==vt[2]&&vl[1]==1)  t=vl[0]+vl[2];// swap vt[1] 
                else    t=vl[2];// check vl[2] 
                l=t<vc[vt[2]-'a']?1:0;
                mx=mx<t+l?t+l:mx;
                
                vt[0]=vt[1];
                vt[1]=vt[2];
                vt[2]=text[i+1];
                vl[0]=vl[1];
                vl[1]=vl[2];
                vl[2]=1;
            }else{
                vl.back()+=1;
            }
        }
        
        return mx;
    }
};