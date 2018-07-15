

/*
Leetcode 870. Advantage Shuffle

Test Cases:
[2,7,11,15]
[1,10,4,11]
[12,24,8,32]
[13,25,32,11]

Runtime: 132 ms

*/


class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        // greedy, 2-pointer, smallest in A to any possible in B; O(n*log(n)) time 
        vector<int> rt(A.size(), 0), ma(A.size(), 0), mb(A.size(), 0);
        
        vector<pair<int,int>> ra, rb;// vector<int> is actually enough 
        getOrder( A, ra);
        getOrder( B, rb);
        //for(auto e:ra)  cout<<e.first<<","<<e.second<<" ";   cout<<endl;
        //for(auto e:rb)  cout<<e.first<<","<<e.second<<" ";   cout<<endl;
        
        for( int i=0, j=0; i<ra.size(); i++){
            if(rb[j].first<ra[i].first){
                rt[rb[j].second]=ra[i].first;
                mb[rb[j].second]=1;
                ma[ra[i].second]=1;
                j++;
            }
        }
        
        for( int i=0, j=0; i<ra.size()&&j<rb.size(); i++, j++){// filling empty cell in rt
            while(ma[ra[i].second]!=0&&i<ra.size())  i++;
            while(mb[rb[j].second]!=0&&j<rb.size())  j++;
            
            if(i<ra.size()&&j<rb.size())    rt[rb[j].second]=ra[i].first;
        }
        
        return rt;
    }
    
    void getOrder( vector<int>& A, vector<pair<int,int>>& ra){// sort 
        for(int i=0; i<A.size(); i++)   ra.push_back(make_pair(A[i],i));
        
        mergeSort( ra, 0, ra.size());
        
        return ; 
    }
    
    void merge(vector<pair<int,int>>& ra, int b, int mid, int e){
        vector<pair<int,int>> rc;
        for( int i=b; i<mid; i++)   rc.push_back(ra[i]);
        
        for( int i=0, j=mid, k=b; i<rc.size(); k++){
            if(rc[i].first<ra[j].first||j==e)   ra[k]=rc[i++];
            else    ra[k]=ra[j++];
        }
        
        return ;
    }
    
    void mergeSort(vector<pair<int,int>>& ra, int b, int e){// [b,e)
        if(e-b<2)   return ;
        int mid=b+(e-b)/2;
        
        mergeSort( ra, b, mid);
        mergeSort( ra, mid, e);
        merge( ra, b, mid, e);
        
        return ;
    }
};
