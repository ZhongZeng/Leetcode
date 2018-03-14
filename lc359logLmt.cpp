
/*
Leetcode 359. Logger Rate Limiter

Companies 
Google 
Related Topics 
Hash Table, Design 
Similar Questions 
Design Hit Counter

Next challenges: Design Hit Counter

Test Cases:
["Logger","shouldPrintMessage","shouldPrintMessage","shouldPrintMessage","shouldPrintMessage","shouldPrintMessage","shouldPrintMessage"]
[[],[1,"foo"],[2,"bar"],[3,"foo"],[8,"bar"],[10,"foo"],[11,"foo"]]
["Logger","shouldPrintMessage","shouldPrintMessage","shouldPrintMessage","shouldPrintMessage","shouldPrintMessage","shouldPrintMessage","shouldPrintMessage","shouldPrintMessage","shouldPrintMessage","shouldPrintMessage"]
[[],[0,"A"],[0,"B"],[0,"C"],[0,"A"],[0,"B"],[0,"C"],[11,"A"],[11,"B"],[11,"C"],[11,"A"]]

Runtime: 79 ms
Your runtime beats 42.24 % of cpp submissions.

*/

class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        unordered_map<string, int>::iterator umi=um.find(message);
        if(umi!=um.end()){
            if(9<timestamp-umi->second){
                umi->second=timestamp;
                return true;
            }else{
                return false;
            }
        }else{
            um.emplace(message, timestamp);
            return true;
        }
    }
    
    unordered_map<string, int> um;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */
 