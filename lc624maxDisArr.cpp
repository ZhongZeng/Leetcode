
/*
Leetcode 624. Maximum Distance in Arrays

Companies 
Yahoo
Related Topics 
Array, Hash Table 

Next challenges: Median of Two Sorted Arrays, 
Construct Binary Tree from Inorder and Postorder Traversal, Transform to Chessboard

Test Cases:
[[1,2,6],[4,5]]
[[1,3,15],[6,7]]

Runtime: 24 ms
Your runtime beats 65.25 % of cpp submissions.

*/

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int i=-1, mx, mn, ix, im, mx2, mn2;
        while(++i<arrays.size()){
            if(0<arrays[i].size()){
                mn=arrays[i][0];
                mx=arrays[i].back();
                ix=im=i;
                break;
            }
        }
        
        for( i++; i<arrays.size(); i++){
            if(0<arrays[i].size()){
                if(arrays[i][0]<mn){
                    mn=arrays[i][0];
                    im=i;
                }                
                if(mx<arrays[i].back()){
                    mx=arrays[i].back();
                    ix=i;
                }
            }
        }

        if(ix!=im)  return mx-mn;
        
        // ix==im
        for( i=0; i<arrays.size(); i++){
            if(i!=im&&0<arrays[i].size()){
                mn2=arrays[i][0];
                break;
            }
        }
        for( i=0; i<arrays.size(); i++){
            if(i!=ix&&0<arrays[i].size()){
                mx2=arrays[i].back();
                break;
            }
        }        
        for( i=0; i<arrays.size(); i++){
            if(0<arrays[i].size()){
                if(i!=im&&arrays[i][0]<mn2) mn2=arrays[i][0];
                if(i!=ix&&mx2<arrays[i].back()) mx2=arrays[i].back();
            }
        }        
        return mx-mn2<mx2-mn?mx2-mn:mx-mn2;
    }
};

/*
// 2017/7/3
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int max1, max2, min1, min2, s=arrays.size();
		if( *arrays[0].begin()<*arrays[1].begin() ){
			max1=1;
			max2=0;
		}else{
			max1=0;
			max2=1;			
		}
		
		if( *arrays[0].rbegin()<*arrays[1].rbegin() ){
			min1=0;
			min2=1;
		}else{
			min1=1;
			min2=0;		
		}
		
		
		for(int i=0; i!=s; i++){
			if(){
				
			}else if(){
				
			}
			
		}
		
		return 
    }
};
*/
