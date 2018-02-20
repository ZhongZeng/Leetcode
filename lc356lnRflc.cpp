
/*
Leetcode 356. Line Reflection

Companies 
Google 
Related Topics 
Hash Table, Math 
Similar Questions 
Max Points on a Line, Number of Boomerangs

Next challenges: Sparse Matrix Multiplication, 
Rearrange String k Distance Apart, Encode and Decode TinyURL

Test Cases:
[[1,1],[0,1]]
[[1,1],[-1,-1]]
[]
[[0,0]]
[[0,0],[1,1],[-1,1]]
[[-1,1],[1,1],[1,1]]
[[1,1],[1,1],[-1,1]]

Runtime: 24 ms
Your runtime beats 44.32 % of cpp submissions.

*/

class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        // the question should be more well defined that 1/multiple points can reflect to 1/multiple points
        if(points.size()<2) return true;
        list<int> ls;
        list<int>::iterator it;
        unordered_map<int, list<int>> um;
        unordered_map<int, list<int>>::iterator umi;
        unordered_map<int, int> ur;
        unordered_map<int, int>::iterator uri, urj;
        int mx, mn, ln;
        
        // store points
        for(int i=0; i<points.size(); i++){
            umi=um.find(points[i].second);
            if(umi!=um.end()){
                umi->second.push_back(points[i].first);
            }else{
                ls={points[i].first};
                um.emplace(points[i].second, ls);
            }    
        }
        
        // find reflection line 
        for( umi=um.begin(), it=umi->second.begin(), mx=*it, mn=*it; it!=umi->second.end(); it++){
            if(*it<mn)  mn=*it;
            else if(mx<*it) mx=*it;
        }
        ln=mx+mn;        
        
        // iterates thru each line parallel to x-axis
        for(umi=um.begin(); umi!=um.end(); umi++){
            ur.clear();
            for( it=umi->second.begin(); it!=umi->second.end(); it++){
                if(2*(*it)!=ln){// points not on the line
                    uri=ur.find(*it);
                    if(uri==ur.end()){// new point
                        urj=ur.find(ln-*it);
                        if(urj!=ur.end()){// has reflection
                            urj->second=0;
                            ur.emplace(*it,0);
                        }else{// has no reflection
                            ur.emplace(*it,1);
                        }
                    }
                }
            }
            
            for(uri=ur.begin(); uri!=ur.end(); uri++)   if(uri->second!=0)  return false;
        }
        
        return true;
    }
};