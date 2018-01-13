

/*
Leetcode 406. Queue Reconstruction by Height

Related Topics 
Greedy
Similar Questions 
Count of Smaller Numbers After Self

Next challenges: Count of Smaller Numbers After Self

Test Cases:
[[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
[[8,2],[4,2],[4,5],[2,0],[7,2],[1,4],[9,1],[3,1],[9,0],[1,0]]

Runtime: 35 ms
Your runtime beats 71.18 % of cpp submissions.

*/

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		// O(n*n) 
        // k: >=
        vector<pair<int,int>> vc;
        
        sort(people.begin(), people.end(), lessThan);
        // start from largest, so later has no affects
        
        for(int i=0; i<people.size(); i++){
            // cout<<people[i].first<<","<<people[i].second<<" ";
            vc.insert(vc.begin()+people[i].second, people[i]);
        }
        
        return vc;
    }
    
protected:
    static bool lessThan(pair<int,int> & p1, pair<int,int> & p2){
        if(p2.first<p1.first){
            return true;
        }else if(p1.first<p2.first){
            return false;
        }else{
            return p1.second<p2.second;
        }
    }
};


