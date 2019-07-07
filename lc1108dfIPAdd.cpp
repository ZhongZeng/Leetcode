/*
1108. Defanging an IP Address

Ranking of Weekly Contest 144  
Rank	Name	Score	Finish Time 	Q1 (1)	Q2 (4)	Q3 (6)	Q4 (6)
1325 / 4358	zhongzeng 	11	1:22:47	 0:03:53	 1:07:47  2	 0:41:54  1	

Tag: String (suggested)

Runtime: 4 ms
Memory Usage: 8.3 MB
*/

class Solution {
public:
    string defangIPaddr(string address) {
        string rt;
        for( int i=0; i<address.size(); i++){
            if(address[i]=='.') rt.append("[.]");
            else    rt.push_back(address[i]);
        }
        return rt;
    }
};