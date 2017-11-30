
/*
Leetcode 274. H-Index

Related Topics 
Hash Table Sort 
Similar Questions 
H-Index II 

Next challenges: H-Index II

Test Cases:
[3, 0, 6, 1, 5]
[1,1]
[4,4,0,0]

Runtime: 3 ms
Your runtime beats 10.27 % of cpp submissions.

*/


class Solution {
public:
    int hIndex(vector<int>& citations) {
        // h articles with inedx >= h
        // I use hash_table and heap sort
        int i,t,sum=0;
        unordered_map<int,int> um;
        unordered_map<int,int>::iterator umi;
        vector<int> vc;
        for(vector<int>::iterator it=citations.begin();it!=citations.end();it++){
            umi=um.find(*it);
            if(umi!=um.end())   umi->second++;
            else    um.emplace(*it,1);
        }
        
        //heapify
        for(umi=um.begin(); umi!=um.end(); umi++){
            vc.push_back(umi->first);
            i=vc.size()-1;
            while( vc[(i-1)/2]<vc[i] ){
                t=vc[(i-1)/2];
                vc[(i-1)/2]=vc[i];
                vc[i]=t;
                i=(i-1)/2;
            }
        }
        
        //extract
        while(vc.size()!=0){
            umi=um.find(vc[0]);
            sum+=umi->second;
            if(sum<vc[0]){
                vc[0]=*vc.rbegin();                
                vc.pop_back();
                i=0;
                while( i<vc.size() ){
                    if(2*i+2<vc.size()){// 2 children
                        if(vc[i]<vc[2*i+1] && !(vc[i]<vc[2*i+2] && vc[2*i+1]<vc[2*i+2]) ){
                            t=vc[i];
                            vc[i]=vc[2*i+1];
                            vc[2*i+1]=t;
                            i=2*i+1;
                        }else if(vc[i]<vc[2*i+2] && !(vc[i]<vc[2*i+1] && vc[2*i+2]<vc[2*i+1]) ){
                            t=vc[i];
                            vc[i]=vc[2*i+2];
                            vc[2*i+2]=t;
                            i=2*i+2;
                        }else{
                            break;
                        }
                    }else if(2*i+1<vc.size()){// 1 child
                        if(vc[i]<vc[2*i+1]){
                            t=vc[i];
                            vc[i]=vc[2*i+1];
                            vc[2*i+1]=t;
                            break;                            
                        }else{
                            break;
                        }
                    }else{// 0 child
                        break;
                    }
                }
            }else if(vc[0]<sum){
                return (sum-(umi->second)) < vc[0] ? vc[0]:(sum-(umi->second));
            }else{
                cout<<vc[0];
                return sum;
            }            
        }
        
        return sum;
    }
};