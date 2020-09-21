/*
1592. Rearrange Spaces Between Words

Ranking of Weekly Contest 207  
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (4)	Q3 (5)	Q4 (6)
5463 / 12923	zhongzeng 	3	0:29:14	 0:24:14  1		

Easy
Companies	Google
Related Topics	String

Test Cases:
"  this   is  a sentence "
" practice   makes   perfect"
"hello   world"
"  walks  udp package   into  bar a"
"a"

Runtime: 4 ms
Memory Usage: 6.4 MB
*/

class Solution {
public:
    string reorderSpaces(string text) {
        if(text.size()<1)   return "";
        int spaces=0, words=0, gap, end;
        string str;
        
        for( int i=0; i<text.size(); ){
            if(text[i]==' '){
                words+=1;
                int t=i;
                i=findNextNonSpace( i, text);
                spaces+=i-t;
            }else{
                i++;
            }
        }
        if(text[0]==' ')    words-=1;
        if(text.back()!=' ')    words+=1;
        if(1<words){
            gap=spaces/(words-1);
            end=spaces%(words-1);
        }else{
            gap=0;
            end=spaces;
        }
        
        for( int i=findNextNonSpace( 0, text), w=0; i<text.size(); ){
            if(text[i]!=' '){
                str.push_back(text[i]);
                i++;
            }else{
                if(w<words-1){
                    w++;
                    for( int j=0; j<gap; j++)   str.push_back(' ');
                    i=findNextNonSpace( i, text);
                }else{
                    break;
                }
            }
        }
        for( int j=0; j<end; j++)
            str.push_back(' ');
        
        return str;
    }

protected:
    int findNextNonSpace( int i, string & text){
        for( ; i<text.size()&&text[i]==' '; i++){}
        return i;
    }
};