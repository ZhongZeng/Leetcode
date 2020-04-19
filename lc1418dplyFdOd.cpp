/*
1418. Display Table of Food Orders in a Restaurant

Company	JP Morgan
Related Topics	Hash Table

Test Cases:
[["David","3","Ceviche"],["Corina","10","Beef Burrito"],["David","3","Fried Chicken"],["Carla","5","Water"],["Carla","5","Ceviche"],["Rous","3","Ceviche"]]
[["James","12","Fried Chicken"],["Ratesh","12","Fried Chicken"],["Amadeus","12","Fried Chicken"],["Adam","1","Canadian Waffles"],["Brianna","1","Canadian Waffles"]]
[["Laura","2","Bean Burrito"],["Jhon","2","Beef Burrito"],["Melissa","2","Soda"]]

Runtime: 444 ms	Your runtime beats 27.27 % of cpp submissions.
Memory Usage: 65.5 MB
*/

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        unordered_map<string,unordered_map<string,int>> tables;// table number, food item, count 
        unordered_set<string> items_set;
        vector<string> items_vec;
        vector<int> tables_vec;
        vector<vector<string>> display;
        
        // convert to hash table 
        for( int i=0; i<orders.size(); i++){
            items_set.emplace(orders[i][2]);
            unordered_map<string,unordered_map<string,int>>::iterator it=tables.find(orders[i][1]);
            if(it!=tables.end()){
                unordered_map<string,int>::iterator jt=it->second.find(orders[i][2]);
                if(jt!=it->second.end())    jt->second+=1;
                else    it->second.emplace(orders[i][2],1);
            }else{
                unordered_map<string,int> um({{orders[i][2],1}});
                tables.emplace(orders[i][1], um);
            }
        }
        
        // first row 
        for(unordered_set<string>::iterator it=items_set.begin(); it!=items_set.end(); it++)
            items_vec.push_back(*it);
        sort( items_vec.begin(), items_vec.end());
        items_vec.insert(items_vec.begin(),"Table");
        display.push_back(items_vec);
        
        // table id&item-count rows
        for(unordered_map<string,unordered_map<string,int>>::iterator it=tables.begin(); it!=tables.end(); it++)
            tables_vec.push_back(stringToInt(it->first));
        sort( tables_vec.begin(), tables_vec.end());
        
        for( int i=0; i<tables_vec.size(); i++){
            vector<string> vs={to_string(tables_vec[i])};
            unordered_map<string,unordered_map<string,int>>::iterator it=tables.find(vs[0]);
            for( int j=1; j<display[0].size(); j++){// display[0]==items_vec
                unordered_map<string,int>::iterator jt=it->second.find(display[0][j]);// ==items_vec[j]
                vs.push_back(jt!=it->second.end()?to_string(jt->second):"0");
            }
            display.push_back(vs);
        }
        
        return display;
    }
    
protected:
    int stringToInt(string s){
        int num=0;
        for( int i=0; i<s.size();i++)   num=num*10+s[i]-'0';
        return num;
    }
};