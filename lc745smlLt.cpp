

/*

Leetcode 744. Find Smallest Letter Greater Than Target


Related Topics 
Binary Search 

Next challenges: Divide Two Integers, Search in Rotated Sorted Array II, First Bad Version

Runtime: 26 ms
Sorry. We do not have enough accepted submissions to show runtime distribution chart.

*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char cm='{';
        // '{' << static_cast<char>('z'+1) 
        for(vector<char>::iterator it=letters.begin(); it!=letters.end(); it++){
            if(target<*it&&*it<cm)  cm=*it;
        }
        
        if(cm=='{'){
            for(vector<char>::iterator it=letters.begin(); it!=letters.end(); it++){
                if(*it<cm)  cm=*it;
            } 
        }
        
        return cm;
    }
};
