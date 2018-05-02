
/*
Leetcode 826. Most Profit Assigning Work

Companies 
NetEase
Related Topics 
Two Pointer 

Test Cases:
[2,4,6,8,10]
[10,20,30,40,50]
[4,5,6,7]

Runtime: 121 ms

*/

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // O((m+k)*log(m)) time
        int sum=0, len=difficulty.size();
        
        mergeSort( difficulty, profit, 0, difficulty.size() );// O(m*log(m))
        
        //for(int i=0; i<difficulty.size(); i++)  cout<<difficulty[i]<<" ";   cout<<endl;
        
        for(int i=0, j=1; j<difficulty.size(); j++){// O(m), remove not smaller difficulty but not greater profit 
            if(profit[i]<profit[j]){
                difficulty[++i]=difficulty[j];
                profit[i]=profit[j];
            }else{
                len--;
            }
        }
        
        //for(int i=0; i<len; i++)    cout<<difficulty[i]<<" ";   cout<<endl;
        //for(int i=0; i<len; i++)    cout<<profit[i]<<" ";   cout<<endl;
        
        for(int i=0; i<worker.size(); i++){// O(k*log(m))
            if(difficulty[0]<=worker[i])    sum+=profit[binarySearch(difficulty, worker[i], len)];
        }
        
        return sum;
    }
    
    int binarySearch(vector<int>& difficulty, int& w, int& len){// difficulty[b] <= w < difficulty[e]
        int b=0, e=len, mid;
        while(b+1<e){
            mid=b+(e-b)/2;
            if(w<difficulty[mid])   e=mid;
            else    b=mid;
        }
        return b;
    }
    
    void mergeSort(vector<int>& d, vector<int>& p, int b, int e){// merge sort [b,e) 
        if(e<b+2)   return ;
        int mid=b+(e-b)/2;
        mergeSort(d, p, b, mid);
        mergeSort(d, p, mid, e);
        merge(d, p, b, mid, e);
        return ;
    }
    
    void merge(vector<int>& d, vector<int>& p, int b, int mid, int e){
        vector<int> vd, vp;
        for(int i=b; i<mid; i++){
            vd.push_back(d[i]);
            vp.push_back(p[i]);
        }
        
        for(int i=0, j=mid, k=b; i<vd.size(); k++){
            if(j==e||vd[i]<d[j]){
                d[k]=vd[i];
                p[k]=vp[i++];
            }else{
                d[k]=d[j];
                p[k]=p[j++];
            }
        }
        return ;
    }
};
