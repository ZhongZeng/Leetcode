/*
1472. Design Browser History

Medium
Related Topics	Design

Test Cases:
["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]

Runtime: 376 ms	Your runtime beats 66.67 % of cpp submissions.
Memory Usage: 54.8 MB
*/

class BrowserHistory {
public:
    BrowserHistory(string homepage) {
      his.push_back(homepage);
      loc=0;
    }
    
    void visit(string url) {
      while( loc+1<his.size() ) his.pop_back();
      loc++;
      his.push_back(url);
    }
    
    string back(int steps) {
      loc=0<loc-steps?loc-steps:0;
      return his[loc];
    }
    
    string forward(int steps) {
      loc=loc+steps<his.size()?loc+steps:his.size()-1;
      return his[loc];
    }
  
protected:
    vector<string> his;
    int loc;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */