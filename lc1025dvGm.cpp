/*
1025. Divisor Game

Companies	Visa
Related Topics	Math, Dynamic Programming

Test Cases:
2
3
196

Runtime: 8 ms
Memory Usage: 9.6 MB
Your runtime beats 39.95 % of cpp submissions. 
*/
class Solution {
public:
    bool divisorGame(int N) {
        // minimax+DP, O(N*N) time; N in [1,1000]
        unordered_map<int,bool> um;
        return divGame( N, um);
    }
    
protected:
    bool divGame( int N, unordered_map<int,bool>& um){
        bool b;
        
        for( int i=1; i<=(N>>1); i++){
            if(N%i==0){
                unordered_map<int,bool>::iterator umi=um.find(N-i);
                if(umi!=um.end()){
                    b=umi->second;
                }else{
                    b=divGame( N-i, um);
                    um.emplace( N-i, b);
                }
                if(b==false)    return true;// b==false means player of next turn loses, equivalent to palyer of this turn wins
            }
        }
        
        return false;
    }
};
/*
// TLE, if we don't use hash table to record visited Ns, it will be TLE. 
class Solution {
public:
    bool divisorGame(int N) {
        // minimax, DFS; N in [1,1000]
        for( int i=1; i<=(N>>1); i++) if(N%i==0&&!divisorGame(N-i))   return true;
        return false;
    }
};
*/