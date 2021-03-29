/*
1615. Maximal Network Rank

Companies:	Microsoft, Amazon 
Related Topics:	Graph 

Runtime: 420 ms	
Memory Usage: 39.7 MB	Your memory usage beats 19.49 % of cpp submissions.
*/

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        // n in [2,100]; O(n*n) time
        int city1=0, max=0;
        unordered_map<int,unordered_set<int>> road_set;
        for( int i=0; i<roads.size(); i++){
            addRoad( roads[i][0], roads[i][1], road_set);
            addRoad( roads[i][1], roads[i][0], road_set);
        }
        
        for( int i=0; i<n; i++){
            for( int j=i+1; j<n; j++){
                unordered_map<int,unordered_set<int>>::iterator it1=road_set.find(i),
                    it2=road_set.find(j);
                int network=(it1!=road_set.end()?it1->second.size():0)
                            +(it2!=road_set.end()?it2->second.size():0);
                if(it1!=road_set.end()&&it1->second.find(j)!=it1->second.end())
                    network--;
                max=max<network?network:max;
            }
        }
        return max;
        // corner case: 5   [[2,3],[0,3],[0,4],[4,1]]
        /* int max1=0, city2=1, max2=0;
        for( unordered_map<int,unordered_set<int>>::iterator it=road_set.begin();
           it!=road_set.end(); it++){
            if(max1<it->second.size()){
                city2=city1;
                max2=max1;
                city1=it->first;
                max1=it->second.size();
            }else if(max2<it->second.size()){
                city2=it->first;
                max2=it->second.size();
            }
        }
        
        unordered_map<int,unordered_set<int>>::iterator it=road_set.find(city1);
        if(it!=road_set.end()&&it->second.find(city2)!=it->second.end())
            return max1+max2-1;
        else
            return max1+max2;*/
    }
    
protected:
    void addRoad( int a, int b, unordered_map<int,unordered_set<int>> & road_set){
        unordered_map<int,unordered_set<int>>::iterator it=road_set.find(a);
        if(it!=road_set.end())  it->second.emplace(b);
        else    road_set.emplace( a, unordered_set<int> {b});
        return ;
    }
};