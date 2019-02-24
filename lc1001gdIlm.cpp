/*
1001. Grid Illumination

Related Topics: Hash Table 

Runtime: 656 ms
Memory Usage: 115.7 MB

Next challenges: Substring with Concatenation of All Words, Sudoku Solver, Basic Calculator IV

Use one hash table to record the positions of lamps and 4 hash tables to record the total number of lighted lamps on each row, column, diagonal, and anti-diagonal. 
To check whether a cell is illuminated, we just need to check the total number of lighted lamps on the corresponding row, column, diagonal, and anti-diagonal in O(1) time. 
To turn the lamp on that cell and adjacent 8 cells, we update the 5 hash tables in approximately O(1) time. 
The total time complexity O(m+k), space complexity is O(m). m=lamps.size(), k=queries.size(). 
Creating a matrix of size of n-by-n is too expensive in both time and space. Using 5 hash tables is better. 
*/

class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector<int> rt;
        unordered_map<int,int> ro, co, di, ad;// row, col, diagonal, anti-diagonal 
        unordered_map<int,unordered_set<int>> lo;// lamps that are on 
        
        for( int i=0; i<lamps.size(); i++){
            auto ui=lo.find(lamps[i][0]);
            if(ui!=lo.end()){
                ui->second.emplace(lamps[i][1]);
            }else{
                unordered_set<int> us;
                us.emplace(lamps[i][1]);
                lo.emplace(lamps[i][0],us);
            }
            
            addLamp(lamps[i][0], ro);
            addLamp(lamps[i][1], co);
            addLamp(lamps[i][0]-lamps[i][1], di);
            addLamp(lamps[i][0]+lamps[i][1], ad);
        }
        
        for( int i=0; i<queries.size(); i++){
            int r=queries[i][0], c=queries[i][1], lp=0;
            // count lamp that could illuminate [r][c]
            auto umi=ro.find(r);
            if(umi!=ro.end()&&0<umi->second)    lp++;
            umi=co.find(c);
            if(umi!=co.end()&&0<umi->second)    lp++;
            umi=di.find(r-c);
            if(umi!=di.end()&&0<umi->second)    lp++;
            umi=ad.find(r+c);
            if(umi!=ad.end()&&0<umi->second)    lp++;
            rt.push_back(0<lp?1:0);
            
            turnOff( r-1, c-1, lo, ro, co, di, ad);
            turnOff( r-1, c, lo, ro, co, di, ad);
            turnOff( r-1, c+1, lo, ro, co, di, ad);
            turnOff( r, c-1, lo, ro, co, di, ad);
            turnOff( r, c, lo, ro, co, di, ad);
            turnOff( r, c+1, lo, ro, co, di, ad);
            turnOff( r+1, c-1, lo, ro, co, di, ad);
            turnOff( r+1, c, lo, ro, co, di, ad);
            turnOff( r+1, c+1, lo, ro, co, di, ad);
        }
        
        return rt;
    }
    
protected:
    void addLamp( int id, unordered_map<int,int>& um){
        auto umi=um.find(id);
        if(umi!=um.end())   umi->second+=1;
        else    um.emplace(id,1);
        return ;
    }
    
    void turnOff( int r, int c, unordered_map<int,unordered_set<int>>& lo, unordered_map<int,int>& ro, 
                 unordered_map<int,int>& co, unordered_map<int,int>& di, unordered_map<int,int>& ad){
        auto ui=lo.find(r);
        if(ui!=lo.end()){
            auto usi=ui->second.find(c);
            if(usi!=ui->second.end()){
                ui->second.erase(c);
                
                ro.find(r)->second-=1;
                co.find(c)->second-=1;
                di.find(r-c)->second-=1;
                ad.find(r+c)->second-=1;
            }
        }
        return ;
    }
};