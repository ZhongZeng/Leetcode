

/*
Leetcode 757. Set Intersection Size At Least Two

Related Topics 
Greedy

Next challenges: Best Time to Buy and Sell Stock II, 
Candy, Best Time to Buy and Sell Stock with Transaction Fee

Test Cases:
[[1,3],[1,4],[2,5],[3,5]]
[[1,2],[2,3],[2,4],[4,5]]
[[1,2],[2,3],[3,4],[4,5]]
[[1,2],[3,4],[7,9],[9,10]]
[[1,2],[3,4],[4,6],[9,10]]
[[8,9],[4,21],[3,19],[5,9],[1,5]]
[[1,3],[4,9],[0,10],[6,7],[1,2],[0,6],[7,9],[0,1],[2,5],[6,8]]
[[16,18],[11,18],[18,20],[10,11]]
[[16,18],[11,18],[15,23],[1,16],[10,16],[6,19],[18,20],[7,19],[10,11],[11,23],[6,7],[23,25],[1,3],[7,12],[1,13],[23,25],[10,22],[23,25],[0,19],[0,13],[7,12],[14,19],[8,17],[7,23],[4,24]]

Runtime: 56 ms

*/


class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // O(n*lg(n)) time 
        // consecutive integers
        int i, sum=2;
        vector<int> lt;//latest elements in set
        
        // sort by interval end (sort by start&traverse from begining is complex)
        sort(intervals.begin(), intervals.end(), lessThan);
        
        // greedy
        lt.push_back(intervals[0][1]-1);
        lt.push_back(intervals[0][1]);
        for(i=1; i<intervals.size(); i++){
            if(lt[0]<intervals[i][0]){ //lt[lt.size()-2]<intervals[i][0]
                if(lt.back()<intervals[i][0]){
                    lt.clear(); //
                    lt.push_back(intervals[i].back()-1);
                    lt.push_back(intervals[i].back());
                    sum+=2;                   
                }else{
                    lt[0]=lt.back(); //
                    lt.back()=intervals[i].back(); //
                    // lt.push_back(intervals[i][1]);
                    sum++;
                }
            }
        }
        // for(int ele:lt) cout<<ele<<" "; cout<<endl;
        return sum;
    }
    
    bool static lessThan(vector<int> & vc1, vector<int> & vc2){
        if(vc1[1]<vc2[1]){
            return true;
        }else if(vc2[1]<vc1[1]){
            return false;
        }else{
            return vc2[0]<vc1[0];// vc1[0]<vc2[0] is WRONG
        }
    }
};


/*
// Wrong Answer - 100 / 113 test cases passed.
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // consecutive integers
        int i;
        bool two=true;
        vector<int> vc, cs;
        // sort by interval start 
        sort(intervals.begin(), intervals.end(), lessThan);
        
        // greedy
        for(i=1, vc=intervals[0]; i<intervals.size(); i++){
            if(two){
                if(vc[1]<intervals[i][0]){
                    cs.push_back(vc[0]);
                    cs.push_back(vc[1]);
                    vc=intervals[i];
                }else if(intervals[i][0]==vc[1]){
                    cs.push_back(vc[0]);
                    cs.push_back(vc[1]);
                    vc=intervals[i];
                    two=false;
                }else if(vc[1]<intervals[i][1]){ // &&intervals[i][0]<vc[1]
                    vc[0]=intervals[i][0];
                }else{// intervals[i][1]<=vc[1]&&intervals[i][0]<vc[1]
                    vc=intervals[i];
                }                
            }else{
                if(vc[1]<intervals[i][0]){
                    cs.push_back(vc[1]);
                    vc=intervals[i];
                    two=true;
                }else if(intervals[i][0]==vc[1]){
                    cs.push_back(vc[1]);
                    vc=intervals[i];
                }else if(vc[1]<intervals[i][1]){ // &&intervals[i][0]<vc[1]
                    if(vc[0]!=intervals[i][0])  two=true;
                    vc[0]=intervals[i][0];
                }else{// intervals[i][1]<=vc[1]&&intervals[i][0]<vc[1]
                    if(vc[0]<intervals[i][0])  two=true;
                    vc=intervals[i];
                }
            }
        }
        if(two){
            cs.push_back(vc[0]);
            cs.push_back(vc[0]+1);
        }else{
            cs.push_back(vc[0]+1);
        }
        //for(auto ele:cs)    cout<<ele<<" "; cout<<endl;
        
        return cs.size();
    }
    
    bool static lessThan(vector<int> & vc1, vector<int> & vc2){
        if(vc1[0]<vc2[0]){
            return true;
        }else if(vc2[0]<vc1[0]){
            return false;
        }else{
            return vc1[1]<vc2[1];
        }
    }
};

*/
