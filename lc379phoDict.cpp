
/*
Leetcode 379. Design Phone Directory

Companies   
Dropbox
Related Topics 
Linked List, Design 

Test Cases:
["PhoneDirectory","get","get","check","get","check","release","check"]
[[3],[],[],[2],[],[2],[2],[2]]
["PhoneDirectory","check","get","check","get"]
[[1],[0],[],[0],[]]
["PhoneDirectory","release","get"]
[[1],[0],[]]
["PhoneDirectory","check","get","check","get","release","check","get","get"]
[[1],[0],[],[0],[],[0],[0],[],[]]

Next challenges: Design HashSet, Design HashMap, Insert into a Cyclic Sorted List

Runtime: 28 ms
Your runtime beats 99.51 % of cpp submissions.

*/

class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {// O(n)
        for( int i=0; i<maxNumbers; i++)    avl.insert(avl.end(),i);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(avl.size()<1)    return -1;// learned from Runtim Error 
        int rt=*avl.begin();
		avl.pop_front();
		
		uu.emplace( rt, used.insert(used.begin(),rt));
        
		return rt;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        unordered_map<int,list<int>::iterator>::iterator uui=uu.find(number);
		return uui==uu.end();
    }
    
    /** Recycle or release a number. */
    void release(int number) {
		unordered_map<int,list<int>::iterator>::iterator uui=uu.find(number);
        if(uui==uu.end())   return ;
        
        used.erase( uui->second );
		uu.erase( uui );
        
        avl.push_back(number);
        
        return ;
    }
	
protected: 	
	list<int> used, avl;
	unordered_map<int,list<int>::iterator> uu;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
