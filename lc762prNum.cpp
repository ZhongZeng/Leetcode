
/*

Leetcode 762. Prime Number of Set Bits in Binary Representation



Test Cases:
6
10
10
15
10000
20000

Weekly Contest 67

Runtime: 16 ms

*/

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        vector<int> bn;
        int ct=0, cb=0;
        bool one=false;
        for(int t=L; 0<t; t=t>>1){
            bn.push_back(t%2);
            if(bn.back()!=0)    cb++;
        }
        
        for(int t=L; t<R+1; t++){
            // cout<<cb<<" ";
            if(isPrime(cb)) ct++;
            one=true;
            for(int i=0; i<bn.size(); i++){
                if(bn[i]!=0){// ==1
                    if(one){
                        bn[i]=0;
                        cb--;
                    }else{
                        one=false;
                        break;
                    }
                }else{// ==0
                    if(one){
                        bn[i]=1;
                        cb++;
                    }
                    one=false;
                    break;
                }
            }
            if(one){
                bn.push_back(1);
                cb++;
            }
        }
        
        return ct;
    }

protected:    
    bool isPrime(int n){
        if(n<2) return false;
        if(n<3) return true;
        for(int i=2; i<n/2+1; i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    
    int sqrt(int n){// to be modified if TLE
        return n;
    }
    
};
