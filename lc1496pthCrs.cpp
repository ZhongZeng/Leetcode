/*
1496. Path Crossing
Easy
Companies	Amazon
Related Topics	String

Ranking of Weekly Contest 195  
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (4)	Q3 (6)	Q4 (7)
1318 / 11467	zhongzeng 	7	0:54:37	 0:46:22	 0:54:37	

Test Cases:
"NES"
"NESWW"

Runtime: 4 ms	Your runtime beats 100.00 % of cpp submissions.
Memory Usage: 6.8 MB
*/

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<int,unordered_set<int>> visited={{0,{0}}};
		for( int r=0, c=0, i=0; i<path.size(); i++ ){
			switch(path[i]){
                case 'N':
                    r++;
                    break;
                case 'S':
                    r--;
                    break;
                case 'E':
                    c++;
                    break;
                case 'W':
                    c--;
                    break;
            }
            unordered_map<int,unordered_set<int>>::iterator it=visited.find(r);
            if(it!=visited.end()){
                unordered_set<int>::iterator jt=it->second.find(c);
                if(jt!=it->second.end())    return true;
                else    it->second.emplace(c);
            }else{
                visited[r]={c};
            }
		}
		return false;
    }
};