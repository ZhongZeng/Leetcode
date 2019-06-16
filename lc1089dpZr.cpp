/*
1089. Duplicate Zeros

Weekly Contest 141
Rank		Name		Score	Finish Time Q1 (4)		Q2 (5)	Q3 (5)	Q4 (8)
979 / 4125	zhongzeng 	14		1:27:33	 	0:35:38  1	0:58:16	1:17:33	1	

Test Cases:
[8,4,5,0,0,0,0,7]
[1,0,2,3,0,4,5,0]
[1,1,2,3,0,0,0,1,1]
[1,2,3]

Runtime: 16 ms
Memory Usage: 9.3 MB
*/
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        // 2-pointer, O(n) time, O(1) space
        int i, j;
        for( i=0, j=0; j<arr.size(); i++)   j+=arr[i]==0?2:1;// find last i 
        
        if(j==arr.size()+1){// arr[i-1]==0 
            arr[j-2]=0;
            j-=3;
            i-=2;
        }else{// j==arr.size() 
            j--;
            i--;
        }
        
        for( ; -1<i; i--){
            if(arr[i]==0){
                arr[j--]=0;
                arr[j--]=0;
            }else{
                arr[j--]=arr[i];
            }
        }
        
        return ;
    }
};