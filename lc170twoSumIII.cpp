
/*
Leetcode 170. Two Sum III - Data structure design

Companies 
Linkedin
Related Topics 
Hash Table, Design 
Similar Questions 
Two Sum, Unique Word Abbreviation, Two Sum IV - Input is a BST

Next challenges: Unique Word AbbreviationTwo Sum IV - Input is a BST

Test Cases；
["TwoSum","add","add","add","find","find"]
[[],[1],[3],[5],[4],[7]]
["TwoSum","add","find"]
[[],[0],[0]]

Runtime: 179 ms
Your runtime beats 20.67 % of cpp submissions.

*/


class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        // O(1) time
        unordered_map<int,int>::iterator usi=us.find(number);
        if(usi==us.end())   us.emplace(number,1);
        else    usi->second+=1;
        return ;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        // O(n) time
        for(unordered_map<int,int>::iterator usi=us.begin(), usj; usi!=us.end(); usi++){
            usj=us.find(value-usi->first);
            if(usj!=us.end()&&(usj!=usi||1<usi->second))    return true;
        }
        return false;
    }
    
    unordered_map<int,int> us;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */