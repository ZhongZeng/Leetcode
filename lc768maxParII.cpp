
/*
768. Max Chunks to Make Sorted (ver. 2)


[5,4,3,2,1]
[2,1,3,4,4]
[4,3,2,1,0]
[1,0,2,3,4]
[4,1,3,2,6,5,8,7]
[0,1,2]
[0]
[1,2,0,2,3]
[0,2,1]

*/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // greedy
		// key diff w/ 769. Max Chunks To Make Sorted (ver. 1): duplicates allowed
        if(arr.size()<2)    return 1;
        int p;
        vector<int> vb;
        vb.push_back(arr[0]);
        
        for(int i=1; i<arr.size(); i++){
            if(vb.back()<=arr[i]){
                vb.push_back(arr[i]);
            }else{
                while(1<vb.size()&&arr[i]<vb[vb.size()-2]){
                    vb[vb.size()-2]=vb.back();
                    vb.pop_back();
                }
            }
        }
        
        return vb.size(); 
    }
};