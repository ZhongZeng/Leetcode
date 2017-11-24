
/*
Leetcode 599. Minimum Index Sum of Two Lists

Related Topics 
Hash Table 
Similar Questions 
Intersection of Two Linked Lists 

Next challenges: Minimum Window Substring, 
Copy List with Random Pointer, 4Sum II

Test Case:
["Shogun","Tapioca Express","Burger King","KFC"]
["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]

Runtime: 93 ms
You are here! 
Your runtime beats 87.20 % of cpp submissions.

*/

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {        
        unordered_map<string, int> us;
        unordered_map<string, int>::iterator usi;
        int sum=list1.size()+list2.size();
        vector<string> vs;
        for(int i=0; i!=list1.size(); i++){
            us.emplace( list1[i], i);
        }
        
        for(int i=0; i!=list2.size(); i++){
            usi=us.find(list2[i]);
            if(usi!=us.end()){
                if(i+usi->second<sum){
                    vs.clear();
                    sum=i+usi->second;
                    vs.push_back(list2[i]);
                }else if(!(sum<i+usi->second)){
                    vs.push_back(list2[i]);
                }
            }
        }
        
        return vs;
    }
};
