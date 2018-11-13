
/*
Leetcode 939. Minimum Area Rectangle

Related Topic:
Hash Table; Suggested: Two Pointer 

Test Case:
[[1,1],[1,3],[3,1],[3,3],[2,2]]

Runtime: 64 ms

*/

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int min=0, ib, jb, ie, je, tm;
		unordered_map<int,vector<int>> um;
		unordered_map<int,vector<int>>::iterator umi, umj;
		
		for( int i=0; i<points.size(); i++){
			umi=um.find(points[i][0]);
			if(umi!=um.end()){
				umi->second.push_back(points[i][1]);
			}else{
				vector<int> vc={points[i][1]};
				um.emplace( points[i][0], vc);
			}
		}
		
		for( umi=um.begin(); umi!=um.end(); umi++)	sort( umi->second.begin(), umi->second.end() );
		
		for( umi=um.begin(); umi!=um.end(); umi++){
			for( umj=umi, umj++; umj!=um.end(); umj++){
				for( ib=0, jb=0; ib<umi->second.size()&&jb<umj->second.size(); ){// O(n) time 
					if(findNextEqual( umi->second, umj->second, ib, jb)){
						ie=ib+1;
						je=jb+1;
						if(findNextEqual( umi->second, umj->second, ie, je)){
							tm=abs(umi->first-umj->first)*(umi->second[ie]-umi->second[ib]);
							if(min!=0)	min=tm<min?tm:min;
							else	min=tm;
						}
						ib=ie;
						jb=je;
					}else{
						break;
					}
				}
			}
		}
		
		return min!=0?min:0;
    }
	
bool findNextEqual( vector<int>& vi, vector<int>& vj, int& i, int& j){
	while( i<vi.size()&&j<vj.size() ){
		if(vi[i]<vj[j])	i++;
		else if(vj[j]<vi[i])	j++;
		else	return true;
	}
	return false;
}
};
