

/*
Leetcode 299 Bulls and Cows

Runtime: 6 ms
You are here! 
Your runtime beats 20.76 % of cpp submissions.

Related Topics 
Hash Table 

Next challenges: Fraction to Recurring Decimal, Count Primes, Set Mismatch


*/

class Solution {
public:
    string getHint(string secret, string guess) {
        int a=0, b=0;
        string s;
        unordered_map<char, int> um;
        unordered_map<char, int>::iterator umi;
        for(string::iterator it=secret.begin(); it!=secret.end(); it++){
            umi=um.find( *it );
            if( umi!=um.end()){
                umi->second++;
            }else{
                um.emplace(*it, 1);
            }
        }
        
        for(int i=0; i!=secret.size(); i++){
            if( secret[i]==guess[i] ){
                a++;        
                umi=um.find(guess[i]);
                umi->second--;
            }                        
        }
        
        for(int i=0; i!=secret.size(); i++){
            if( secret[i]!=guess[i] ){
                umi=um.find(guess[i]);
                if(umi!=um.end() && umi->second!=0 ){                    
                    b++;                    
                    umi->second--;                    
                }
            }                       
        }        
        
        s=to_string(a);
        s.push_back('A');
        s.append(to_string(b));
        s.push_back('B');
        return s;
    }
};
