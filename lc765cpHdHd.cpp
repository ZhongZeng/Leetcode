

/*
Leetcode 765. Couples Holding Hands

Weekly Contest 67

Test Cases:
[0,2,1,3]
[3, 2, 0, 1]
[0,2,4,6,7,1,3,5]

Runtime: 4 ms

*/


class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        // greedy, hash_table, O(n) time
        unordered_map<int,int> um;
        unordered_map<int,int>::iterator umi, umj;
        int sum=0, t;
        for(int i=0; i<row.size(); i++){
            um.emplace(row[i],i);
        }
        
        for(int i=1; i<row.size(); i+=2){// i+=2 not 1 
            if(!isCp(row[i-1],row[i])){
                umi=um.find(findCp(row[i-1]));
                row[umi->second]=row[i];
                um.find(row[i])->second=umi->second;
                // no need to update value@current postion or postion of its coupon in hash_table
                sum++;
                //cout<<i<<":"<<row[i]<<","<<row[umi->second]<<" ";
                //for(auto e:row) cout<<e<<" ";   cout<<endl;
            }
        }
        
        return sum;
    }
    
protected:
    bool isCp(int a, int b){
        if(b<a) return isCp(b, a);
        return (b-a==1)&&(a%2==0);
    }    
    
    int findCp(int a){
        return a%2!=0?a-1:a+1;
    }
};


/*
// Runtime: 3 ms

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        // greedy, sort
		// O(n*n) time 
        int i, j, t, sum=0;
        for(i=1; i<row.size(); i+=2){
            if(!isCp(row[i-1],row[i])){
                for(j=i+1; j<row.size(); j++){
                    if(isCp(row[i-1],row[j])){
                        break;
                    }
                }
                t=row[i];
                row[i]=row[j];
                row[j]=t;
                //cout<<i<<","<<j<<" ";
                sum++;
            }
        }
        return sum;
    }
    
    bool isCp(int a, int b){
        if(b<a) return isCp(b, a);
        return (b-a==1)&&(a%2==0);
    }
    
};
*/