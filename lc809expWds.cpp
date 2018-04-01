
/*
Leetcode 809. Expressive Words

Weekly Contest 78  

Test Cases:
"heeellooo"
["hello", "hi", "helo","heeellooo"]
"zzzzzyyyyy"
["zzyy","zy","zyy"]
"abcd"
["abc"]
"dddiiiinnssssssoooo"
["dinnssoo","ddinso","ddiinnso","ddiinnssoo","ddiinso","dinsoo","ddiinsso","dinssoo","dinso"]

Runtime: 6 ms

*/

class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        // S and all words in words consist only of lowercase letters
        // string 
        int sum=0, i, j, k, c;
        string ms;
        vector<int> mc;
        reduceStr(S, ms, mc);
        //for(auto e:ms)  cout<<e<<" ";   cout<<endl;
        //for(auto e:mc)  cout<<e<<" ";   cout<<endl;
        
        for( i=0; i<words.size(); i++){
            //cout<<words[i]<<": ";
            for( j=1, k=0, c=1; j<words[i].size(); j++){
                //cout<<words[i][j-1]<<" "<<ms[k];
                if(words[i][j]!=words[i][j-1]){
                    // length equal || extendable to 3 or more 
                    if(!( words[i][j-1]==ms[k]&&( c==mc[k]||(2<mc[k]&&c<mc[k]) ) ) )    break;
                    k++;
                    c=1;
                }else{
                    c++;
                }
            }
            //cout<<endl;
            if(j==words[i].size()&&k==ms.size()-1){
                if( words[i][j-1]==ms[k]&&( c==mc[k]||(2<mc[k]&&c<mc[k]) ) )   sum++;
            }
        }
        
        return sum;
    }
    
    void reduceStr(string& s, string& ms, vector<int>& mc){
        int i, c=1;
        string rs;
        
        for( i=1; i<s.size(); i++){
            if(s[i]!=s[i-1]){
                ms.push_back(s[i-1]);
                mc.push_back(c);
                c=1;
            }else{
                c++;
            }
        }

        if(s[i]!=s[i-1]){
            ms.push_back(s[i-1]);
            mc.push_back(c);
            c=1;
        }else{
            c++;
        }  
        
        return ;
    }
};
