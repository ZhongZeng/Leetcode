/*
1410. HTML Entity Parser

Company	Oracle
Related Topic	String, Stack 

Test Cases:
"&amp; is an HTML entity but &ambassador; is not."
"and I quote: &quot;...&quot;"
"Stay home! Practice on Leetcode :)"
"x &gt; y &amp;&amp; x &lt; y is always false"
"leetcode.com&frasl;problemset&frasl;all"
" &frasl; &quot; &apos; ZooP)x:6~"

Runtime: 224 ms	Your runtime beats 80.00 % of cpp submissions.
Memory Usage: 19.1 MB

https://leetcode.com/problems/html-entity-parser/discuss/575228/Brute-Force-C%2B%2B
*/

class Solution {
public:
    string entityParser(string text) {
        // &quot - "; &apos - '; &amp - &; &gt - >; &lt - <; &frasl - /
        string str;
        for( int i=0; i<text.size(); ){
            if(text[i]=='&'){// hash table also fine 
                if(text.substr(i,6)=="&quot;"){
                    str.push_back('"');
                    i+=6;
                }else if(text.substr(i,6)=="&apos;"){
                    str.push_back('\'');
                    i+=6;
                }else if(text.substr(i,5)=="&amp;"){
                    str.push_back('&');
                    i+=5;
                }else if(text.substr(i,4)=="&gt;"){
                    str.push_back('>');
                    i+=4;
                }else if(text.substr(i,4)=="&lt;"){
                    str.push_back('<');
                    i+=4;
                }else if(text.substr(i,7)=="&frasl;"){
                    str.push_back('/');
                    i+=7;
                }else{
                    str.push_back(text[i]);
                    i+=1;
                }
            }else{
                str.push_back(text[i]);
                i+=1;
            }
        }
        return str;
    }
};