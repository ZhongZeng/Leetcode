

/*
Leetcode 690. Employee Importance

Related Topics 
Hash Table, Depth-first Search, Breadth-first Search 
Similar Questions 
Nested List Weight Sum 

Next challenges: Nested List Weight Sum

Test Cases:
[[1,2,[2]], [2,3,[]]]
2
[[1,5,[2,3]],[2,3,[4]],[3,4,[]],[4,1,[]]]
1

Runtime: 23 ms
Your runtime beats 47.15 % of cpp submissions.

*/

/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        // hash_table;BFS/DFS
        // return the total importance value of this employee and all his DIRECT and INDIRECT subordinates
        // One employee has at most one direct leader and may have several subordinates.
        // assuming importance is non-zero
        unordered_map<int,pair<Employee*,int>> um; // ID, importance
        pair<Employee*,int> pr;
        for(vector<Employee*>::iterator it=employees.begin();it!=employees.end();it++){
            pr.first=*it;
            pr.second=-1;
            um.emplace((*it)->id,pr);
        }
        
        return dctImp( id, um);
        }
    
        int dctImp(int & id, unordered_map<int,pair<Employee*,int>> & um){
            // recursive function
            unordered_map<int,pair<Employee*,int>>::iterator umi=um.find(id);
            if(umi->second.first->subordinates.empty()) return umi->second.first->importance;
            
            int sum=umi->second.first->importance, ip;
            vector<int> vc=umi->second.first->subordinates;
            for(vector<int>::iterator it=vc.begin();it!=vc.end();it++){  
                //cout<<*it<<" ";
                sum+=dctImp(*it,um);
            }
            return sum;
    }
};
