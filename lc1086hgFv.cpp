/*
1086. High Five

Companies	Amazon
Related Topics	Array, Hash Table, Sort 

Test Cases:
[[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]
[[1,84],[1,72],[1,47],[1,43],[1,78],[2,79],[2,4],[2,23],[2,88],[2,79],[3,75],[3,80],[3,38],[3,73],[3,4]]
[[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]

Runtime: 16 ms	Your runtime beats 63.25 % of cpp submissions.
Memory Usage: 11.6 MB	Your memory usage beats 75.00 % of cpp submissions.

Next challenges: Median of Two Sorted Arrays, 
Construct Binary Tree from Inorder and Postorder Traversal, Transform to Chessboard

*/

struct greaterThan{// C++ priority queue, default max heap, Compare=less than
    bool operator()(int& p1, int& p2){return p1>p2;}
};

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        // hash table; O(n*log(n)) time, O(n) space 
        vector<vector<int>> rt;
        unordered_map<int,priority_queue<int,vector<int>,greaterThan>> sc;
        unordered_map<int,priority_queue<int,vector<int>,greaterThan>>::iterator sci;
        double d;
        int i;
        
        for( int i=0; i<items.size(); i++){// calculate sum 
            sci=sc.find(items[i][0]);
            if(sci!=sc.end()){
                sci->second.push(items[i][1]);
                if(5<sci->second.size())    sci->second.pop();
            }else{
                priority_queue<int,vector<int>,greaterThan> pq;// min heap, overload compare sign 
                pq.push(items[i][1]);
                sc.emplace( items[i][0], pq);
            }
        }
        
        for( sci=sc.begin(); sci!=sc.end(); sci++){// find top 5 largerest 
            for( i=0, d=0; 0<sci->second.size(); i++, sci->second.pop()) d+=sci->second.top();
            rt.push_back(vector<int> {sci->first, d/i});
        }
        
        sort(rt.begin(), rt.end(), vecLessThan);
        
        return rt;
    }
    
protected:
    static bool vecLessThan( vector<int>& v1, vector<int>& v2){
        return v1[0]<v2[0];// in ascending order of student id 
    }
};