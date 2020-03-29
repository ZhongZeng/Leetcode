/*
1396. Design Underground System

Company	Bloomberg
Related Topics	Design 

Test Case:
["UndergroundSystem","checkIn","checkIn","checkIn","checkOut","checkOut","checkOut","getAverageTime","getAverageTime","checkIn","getAverageTime","checkOut","getAverageTime"]
[[],[45,"Leyton",3],[32,"Paradise",8],[27,"Leyton",10],[45,"Waterloo",15],[27,"Waterloo",20],[32,"Cambridge",22],["Paradise","Cambridge"],["Leyton","Waterloo"],[10,"Leyton",24],["Leyton","Waterloo"],[10,"Waterloo",38],["Leyton","Waterloo"]]

Runtime: 600 ms
Memory Usage: 62.2 MB

https://leetcode.com/problems/design-underground-system/discuss/555797/C%2B%2B-Hash-Table-O(1)-Time-O(n)-space
*/

class UndergroundSystem {
public:
    UndergroundSystem() {
        // assuming no invalid transactions 
    }
    
    void checkIn(int id, string stationName, int t) {
        current.emplace( id, make_pair(stationName, t));
        return ;
    }
    
    void checkOut(int id, string stationName, int t) {
        unordered_map<int,pair<string,int>>::iterator ci=current.find(id);
        string startingStation=ci->second.first;
        int time=t-ci->second.second;
        current.erase(ci);
        
        unordered_map<string, unordered_map<string, pair<int, int>>>::iterator ti=times.find(startingStation);
        if(ti!=times.end()){
            unordered_map<string, pair<int, int>>::iterator ai=ti->second.find(stationName);
            if(ai!=ti->second.end()){
                ai->second.first+=1;
                ai->second.second+=time;
            }else{
                ti->second.emplace(stationName, make_pair(1,time));
            }
        }else{
            unordered_map<string,pair<int,int>> st;
            st.emplace( stationName, make_pair(1,time));
            times.emplace( startingStation, st);
        }
        
        return ;
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<int,int> pr=times.find(startStation)->second.find(endStation)->second;
        return pr.second*1.0/pr.first;
    }
    
protected:
    unordered_map<string, unordered_map<string, pair<int, int>>> times;// # travels, total time
    unordered_map<int, pair<string,int>> current;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */