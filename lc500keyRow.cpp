
/*
Leetcode 500. Keyboard Row

Related Topics 
Hash Table 

Next challenges: Maximal RectangleMax Points on a LineMaximum Size Subarray Sum Equals k

Test Cases:
["Hello","Alaska","Dad","Peace"]

Runtime: 3 ms
You are here! 
Your runtime beats 1.30 % of cpp submissions.

Runtime: 0 msYou are here! 
Your runtime beats 52.42 % of cpp submissions.

*/

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> vs;
        vector<int> vc={2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3};        
        string::iterator si;
        int num, grp; 
        cout<<vc.size()<<endl;                     
        for(vector<string>::iterator it=words.begin(); it!=words.end(); it++){
            si=it->begin();
            num = *si - 'A';
            if( 31<num )    num-=32 ;
            grp = vc[num];
            while( ++si!=it->end()){
                num = *si - 'A';
                if( 31<num )    num-=32 ;
                if( vc[num]!=grp ){
                    break;
                }
            }
            
            if( si==it->end() ){
                vs.push_back(*it);
            }            
        }               
        return vs;
    }
    
};
