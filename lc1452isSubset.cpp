/*
1452. People Whose List of Favorite Companies Is Not a Subset of Another List

Medium
Companies	Google
Related Topics	String, Sort

Test Cases:
[["leetcode","google","facebook"],["google","microsoft"],["google","facebook"],["google"],["amazon"]]

Runtime: 612 ms, faster than 69.11% of C++ online submissions for People Whose List of Favorite Companies Is Not a Subset of Another List.
Memory Usage: 75.3 MB, less than 24.37% of C++ online submissions for People Whose List of Favorite Companies Is Not a Subset of Another List.
Next challenges: Smallest Range Covering Elements from K Lists, Index Pairs of a String, Design A Leaderboard
*/


class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        // Brute Force; Bit Mask requires limited # of companies
        vector<int> idx;
        vector<unordered_set<int>> comp;
        unordered_map<string,int> um;
        int unq=0;
        
        for( int i=0; i<favoriteCompanies.size(); i++){
            unordered_set<int> us;
            for( int j=0; j<favoriteCompanies[i].size(); j++){
                if(um.find(favoriteCompanies[i][j])!=um.end()){
                    us.emplace(um[favoriteCompanies[i][j]]);
                }else{
                    um[favoriteCompanies[i][j]]=++unq;
                    us.emplace(unq);
                }
            }
            comp.push_back(us);
        }
        
        for( int i=0; i<comp.size(); i++){
            int b=true;
            for( int j=0; j<comp.size(); j++){
                if(i==j)    continue;
                if(favoriteCompanies[j].size()<comp[i].size()) continue;
                if(isSubset(comp[i],comp[j])){
                    b=false;
                    break;
                }
            }
            if(b)   idx.push_back(i);
        }
        return idx;
    }
    
protected:
    bool isSubset( unordered_set<int> & us1, unordered_set<int> & us2){
        for( unordered_set<int>::iterator it=us1.begin(); it!=us1.end(); it++)
            if(us2.find(*it)==us2.end())   return false;
        return true;
    }
};

// TLE
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        // Brute Force; Bit Mask requires limited # of companies
        vector<int> idx;
        for( int i=0; i<favoriteCompanies.size(); i++){
            int b=true;
            for( int j=0; j<favoriteCompanies.size(); j++){
                if(i==j)    continue;
                if(favoriteCompanies[j].size()<favoriteCompanies[i].size()) continue;
                if(isSubset(favoriteCompanies[i],favoriteCompanies[j])){
                    b=false;
                    break;
                }
            }
            if(b)   idx.push_back(i);
        }
        return idx;
    }
    
protected:
    bool isSubset( vector<string> & vc1, vector<string> & vc2){
        unordered_set<string> us;
        for( int i=0; i<vc2.size(); i++)    us.emplace(vc2[i]);
        for( int i=0; i<vc1.size(); i++)    if(us.find(vc1[i])==us.end())   return false;
        return true;
    }
};