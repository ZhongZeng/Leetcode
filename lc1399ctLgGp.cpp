/*
1399. Count Largest Group

Companies	mercari
Related Topics	Array 

Runtime: 8 ms, faster than 66.05% of C++ online submissions for Count Largest Group.
Memory Usage: 6 MB, less than 100.00% of C++ online submissions for Count Largest Group.
Next challenges: Sum of Mutated Array Closest to Target,
Compare Strings by Frequency of the Smallest Character,
Find Winner on a Tic Tac Toe Game
*/

class Solution {
public:
    int countLargestGroup(int n) {
        // brute force
        int max=0, count=0;
        unordered_map<int,int> groups;
        
        for( int i=1; i<=n; i++){
            int sum=calSum(i);
            unordered_map<int,int>::iterator it=groups.find(sum);
            if(it!=groups.end())    it->second+=1;
            else    groups.emplace(sum, 1);
        }
        
        for( unordered_map<int,int>::iterator it=groups.begin(); it!=groups.end(); it++){
            if(max<it->second){
                max=it->second;
                count=1;
            }else if(max==it->second){
                count++;
            }
        }
        
        return count;
    }
    
protected:
    int calSum( int & n){
        int sum=0;
        for( int m=n; 0<m; m=m/10)  sum+=m%10;
        return sum;
    }
};