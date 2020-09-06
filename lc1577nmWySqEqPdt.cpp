/*
1577. Number of Ways Where Square of Number Is Equal to Product of Two Numbers

Medium
Related Topics	Hash Table, Math

Test Cases:
[43024,99908]
[1864]
[7,4]
[5,2,8,9]
[1,1]
[1,1,1]
[7,7,8,3]
[1,2,9,7]
[4,7,9,11,23]
[3,5,1024,12,18]

Runtime: 288 ms
Memory Usage: 11.6 MB
*/

class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        // O(n*n+m*m) time; Easy 
        return numTripletsOneWay(nums1, nums2)+numTripletsOneWay(nums2, nums1);
    }
    
protected:
    int numTripletsOneWay(vector<int>& nums1, vector<int>& nums2) {
        int sum=0;
        unordered_map<long,int> squares;
        for( int i=0; i<nums1.size(); i++){
            long square=(long)nums1[i]*nums1[i];
            if(squares.find(square)!=squares.end()) squares[square]+=1;
            else    squares[square]=1;
        }
        for( int i=0; i<nums2.size(); i++){
            for( int j=i+1; j<nums2.size(); j++){
                unordered_map<long,int>::iterator it=squares.find((long)nums2[i]*nums2[j]);
                if(it!=squares.end())
                    sum+=it->second;
            }
        }
        return sum;
    }
};