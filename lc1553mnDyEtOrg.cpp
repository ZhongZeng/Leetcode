/*
1553. Minimum Number of Days to Eat N Oranges

Hard
Companies	Google
Related Topcis	Dynamic Programming

Test Cases:
10
6
1
56
88637

Runtime: 268 ms
Memory Usage: 35.3 MB

https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/discuss/796261/C++-BFS+Greedy-Dijkstra
*/

class Solution {
public:
    int minDays(int n) {
        // BFS+Greedy, Dijkstra; n>0
        if(n==1)    return 1;
        unordered_map<int,int> eats;
        unordered_set<int> oranges={n};
        int days=1;
        
        for( ; !oranges.empty(); days++){
            unordered_set<int> oranges1;
            for( unordered_set<int>::iterator it=oranges.begin(); it!=oranges.end(); it++){
                if(*it-1==0)    return days;
                if(eats.find(*it-1)==eats.end())    pushOranges(eats, oranges1, *it-1, days);
                if(*it%2==0){
                    if(*it/2==0)    return days;
                    if(eats.find(*it/2)==eats.end())    pushOranges(eats, oranges1, *it/2, days);
                }
                if(*it%3==0){
                    if(*it/3==0)    return days;
                    if(eats.find(*it/3)==eats.end())    pushOranges(eats, oranges1, *it/3, days);
                }
            }
            oranges=oranges1;
        }
        
        return -1;// unreachable, b/c reducing by 1 will always reach 1
    }
    
protected:
    void pushOranges( unordered_map<int,int> & eats, unordered_set<int> & oranges1, int orange, int days){
        eats[orange]=days;
        oranges1.emplace(orange);
        return ;
    }
};

/*TLE*/
class Solution {
public:
    int minDays(int n) {
        // BFS+Greedy, Dijkstra
        if(n==1)    return 1;
        unordered_map<int,int> eats={{1,1}};
        unordered_set<int> oranges={1};
        int days=2;
        
        for( ; !oranges.empty(); days++){
            unordered_set<int> oranges1;
            for( unordered_set<int>::iterator it=oranges.begin(); it!=oranges.end(); it++){
                if(*it+1==n)    return days;
                if(eats.find(*it+1)==eats.end())    pushOranges(eats, oranges1, *it+1, days);
                if(*it*2==n)    return days;
                if(eats.find(*it*2)==eats.end())    pushOranges(eats, oranges1, *it*2, days);
                if(*it*3==n)    return days;
                if(eats.find(*it*3)==eats.end())    pushOranges(eats, oranges1, *it*3, days);
            }
            oranges=oranges1;
        }
        
        return -1;
    }
    
protected:
    void pushOranges( unordered_map<int,int> & eats, unordered_set<int> & oranges1, int orange, int days){
        eats[orange]=days;
        oranges1.emplace(orange);
        return ;
    }
};