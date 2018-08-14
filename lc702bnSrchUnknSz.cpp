
/*
Leetcode 702. Search in a Sorted Array of Unknown Size

Companies   
Google
Related Topics 
Binary Search 
Similar Questions 
Binary Search

Test Cases:
[-1,0,3,5,9,12]
9
[-1,0,3,5,9,12]
2

Next challenges: Russian Doll Envelopes, 
Max Sum of Rectangle No Larger Than K, Preimage Size of Factorial Zeroes Function

Runtime: 36 ms
Your runtime beats 22.51 % of cpp submissions.

*/

// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        // array[-9999, 9999]; ArrayReader.get return 2147483647, if out of bounds 
        int b=0, e=INT_MAX, mid;// actually unique array[-9999, 9999], e=20001
        
        while( b+1<e ){// [b,e) 
            mid=b+(e-b)/2;
            if(target<reader.get(mid))  e=mid;
            else    b=mid;
        }
        
        return reader.get(b)!=target?-1:b;
    }
};


/*
Runtime: 48 ms
Your runtime beats 4.76 % of cpp submissions.

// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        // array[-9999, 9999]; ArrayReader.get return 2147483647, if out of bounds 
        int b=0, e=20001, mid;
        
        while( b+1<e ){// [b,e) 
            mid=b+(e-b)/2;
            if(target<reader.get(mid))  e=mid;
            else    b=mid;
        }
        
        return reader.get(b)!=target?-1:b;
    }
};

*/