

/*
Leetcode 275. H-Index II

Related Topics 
Binary Search 
Similar Questions 
H-Index 

Next challenges: Closest Binary Search Tree Value, 
Smallest Rectangle Enclosing Black Pixels, Find K-th Smallest Pair Distance

Test Cases:
[]
[1,2,3,5,5]
[1,2,4,5,5]

Runtime: 6 ms
Your runtime beats 50.43 % of cpp submissions.

*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        // be aware of corner cases
        if(citations.size()<1)  return 0;
        int b=0,e=citations.size(),s=citations.size(),mid;
        while(b<e-1){
            mid=b+(e-b)/2;
            if(s-mid<citations[mid]){
                e=mid;
            }else{
                b=mid;
            }
        }
        return citations[b]<s-b?s-b-1:s-b;
    }
};
