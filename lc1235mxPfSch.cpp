/*
1235. Maximum Profit in Job Scheduling

Hard
Companies	Airbnb
Related Topics	Binary Search, Dynamic Programming, Sort

Test Cases:
[1,2,3,4,6]
[3,5,10,6,9]
[20,20,100,70,60]
[1,2,3,3]
[3,4,5,6]
[50,10,40,70]

Runtime: 356 ms, faster than 46.13% of C++ online submissions for Maximum Profit in Job Scheduling.
Memory Usage: 59.9 MB, less than 100.00% of C++ online submissions for Maximum Profit in Job Scheduling.
Next challenges: Shortest Path Visiting All Nodes, Increasing Decreasing String,
Cherry Pickup II
*/

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // Dynamic Programming, Sort; O(n*log(n)) time; startTime.size() in [1,5*10**4]
        vector<pair<int,int>> pf={make_pair(0,0)};// ending time, max profit
        vector<vector<int>> tm;// startTime, endTime, profit
        for( int i=0; i<startTime.size(); i++)
            tm.push_back(vector<int> {startTime[i], endTime[i], profit[i]});
        sort( tm.begin(), tm.end(), lessThan);// sort by endTime
        
        for( int i=0, b, e, mid; i<tm.size(); i++){
            for( b=0, e=pf.size(); 1<e-b;){// tm[i][0] in [b,e)
                mid=b+(e-b)/2;
                if(pf[mid].first<=tm[i][0]) b=mid;
                else    e=mid;
            }
            if(pf.back().second<pf[b].second+tm[i][2])
                pf.push_back(make_pair(tm[i][1], pf[b].second+tm[i][2]));
        }
        
        return pf.back().second;
    }
    
protected:
    static bool lessThan(vector<int> & v1, vector<int> & v2){
        return v1[1]<v2[1];
    }
};

// TLE
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // Dynamic Programming, Sort; O(n*n) time; startTime.size() in [1,5*10**4]
        unordered_map<int,int> pf;// ending time, profit
        vector<vector<int>> tm;// startTime, endTime, profit
        for( int i=0; i<startTime.size(); i++)
            tm.push_back(vector<int> {startTime[i], endTime[i], profit[i]});
        sort( tm.begin(), tm.end(), lessThan);// sort by endTime
        
        for( int i=0; i<tm.size(); i++){
            int mx=tm[i][2];
            for( unordered_map<int,int>::iterator it=pf.begin(); it!=pf.end(); it++){
                if(it->first<=tm[i][0]) mx=mx<it->second+tm[i][2]?it->second+tm[i][2]:mx;
                else    mx=mx<it->second?it->second:mx;
            }
            if(pf[tm[i][1]]==NULL||pf[tm[i][1]]<mx) pf[tm[i][1]]=mx;
        }
        
        return pf[tm.back()[1]];
    }
    
protected:
    static bool lessThan(vector<int> & v1, vector<int> & v2){
        return v1[1]<v2[1];
    }
};