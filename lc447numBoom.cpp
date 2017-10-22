

/*
Leetcode 447. Number of Boomerangs

Related Topics 
Hash Table 
Similar Questions 
Line Reflection 

Next challenges: Line Reflection

Test Cases:
[[0,0],[1,0],[2,0]]
[[0,0],[1,0],[-1,0],[0,1],[0,-1]]

Runtime: 213 ms
You are here! 
Your runtime beats 81.09 % of cpp submissions.

*/


class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        unordered_map<int, int> us;
        unordered_map<int, int>::iterator usi;
        int sum=0, a, b, c, d, dis;
        
        for(int i=0; i!=points.size(); i++){
            us.clear();            
            for(int j=0; j!=points.size(); j++){
                a = points[i].first;
                b = points[j].first;
                c = points[i].second;
                d = points[j].second;
                dis = a*a+b*b-2*a*b+c*c+d*d-2*c*d;
                usi=us.find( dis );
                if( usi!=us.end() ){
                    usi->second++;
                }else{
                    us.emplace( dis, 1);
                }                                
            }          
            
            for( usi=us.begin(); usi!=us.end(); usi++){
                if( usi->second!=1 ){
                    sum += usi->second*(usi->second-1) ;
                    //cout<<usi->second<<endl;
                }
            }                    
        }
        
        return sum;
    }
    
};
