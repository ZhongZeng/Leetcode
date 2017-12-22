

/*
Leetcode 443. String Compression

Related Topics 
String
Similar Questions 
Count and Say, Encode and Decode Strings, Design Compressed String Iterator

Next challenges: Encode and Decode Strings, Design Compressed String Iterator

Test Cases:
["a","a","b","b","b","b","b","b","b","b","b","b","b","b","b","b","b","b","c","c","c"]
["a"]
[]

Runtime: 15 ms
Your runtime beats 1.41 % of cpp submissions

Runtime: 6 ms
Your runtime beats 27.21 % of cpp submissions.

*/

class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()<1)  return 0;
        int ct=1, i=0, bg;
        char c=chars[0], d;
        for( int j=1; j<chars.size(); j++){
            if(chars[j]!=c){
                chars[i]=c;
                i++;
                if(1<ct){// ct is guranteed to fit into vector
                    bg=i;
                    while(0<ct){
                        chars[i]=(char)('0'+ct%10);
                        i++;
                        ct=ct/10;
                    }
                    for(int k=bg, l=i-1; k<l; k++, l--){
                        d=chars[k];
                        chars[k]=chars[l];
                        chars[l]=d;
                    }
                }
                ct=1;
                c=chars[j];
            }else{
                ct++;
            }
        }
        
        chars[i]=c;
        i++;
        if(1<ct){// ct is guranteed to fit into vector
            bg=i;
            while(0<ct){
                chars[i]=(char)('0'+ct%10);
                i++;
                ct=ct/10;
            }
            for(int k=bg, l=i-1; k<l; k++, l--){
                d=chars[k];
                chars[k]=chars[l];
                chars[l]=d;
            }
        }
        
        return i;
    }
};
