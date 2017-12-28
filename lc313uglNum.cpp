

/*
Leetcode 313. Super Ugly Number

Related Topics 
Math, Heap
Similar Questions 
Ugly Number II

Next challenges: Find Median from Data Stream, 
Water and Jug Problem, Remove 9

Test Cases:
1
[2,3,5]
200
[2,3,5]
200
[2,3,5,11,31]
100000
[7,19,29,37,41,47,53,59,61,79,83,89,101,103,109,127,131,137,139,157,167,179,181,199,211,229,233,239,241,251]

Runtime: 42 ms
Your runtime beats 45.76 % of cpp submissions. 

*/

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // O(n*k*lg(n*k)) time, k=primes.size()
        // 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
        // The given numbers in primes are in ascending order. They must be prime!
        if(primes[0]==1)    primes.erase(primes.begin());// O(primes.size()) time
        int c=0;
        pair<int, int> t;
        vector<pair<int,int>> hp;
        hp.push_back(make_pair(1, 0));
        
        while(++c<n){
            t=hp[0];
            popHp(hp);
            for(int j=t.second; j<primes.size(); j++){// ensure every # gets pushed into heap only once
                if(t.first<2147483647/primes[j])
                    pushHp(hp, make_pair(t.first*primes[j],j));
            }
        }
        
        return hp[0].first;
    }
    
    void pushHp(vector<pair<int,int>> & hp, pair<int, int> ele){
        int i=hp.size();
        pair<int,int> t;
        hp.push_back(ele);
        while(0<i){
            if(hp[i].first<hp[(i-1)/2].first){
                t=hp[i];
                hp[i]=hp[(i-1)/2];
                hp[(i-1)/2]=t;
                i=(i-1)/2;
            }else{
                return ;
            }
        }
        return ;
    }
    
    void popHp(vector<pair<int,int>> & hp){
        hp[0]=hp.back();
        hp.pop_back();
        int i=0;
        pair<int,int> t;
        while(2*i+2<hp.size()){
            if(hp[2*i+2].first<hp[i].first&&hp[2*i+2].first<hp[2*i+1].first){
                t=hp[2*i+2];
                hp[2*i+2]=hp[i];
                hp[i]=t;
                i=2*i+2;
            }else if(hp[2*i+1].first<hp[i].first){
                t=hp[2*i+1];
                hp[2*i+1]=hp[i];
                hp[i]=t;
                i=2*i+1;
            }else{
                return ;
            }
        }
        
        if(2*i+1<hp.size()&&hp[2*i+1].first<hp[i].first){
            t=hp[2*i+1];
            hp[2*i+1]=hp[i];
            hp[i]=t;
        }
        return ;
    }
};
