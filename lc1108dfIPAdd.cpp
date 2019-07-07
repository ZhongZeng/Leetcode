/*
1108. Defanging an IP Address

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