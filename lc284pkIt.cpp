
/*
Leetcode 284. Peeking Iterator

Companies 
Google, Apple, Yahoo 
Related Topics 
Design 
Similar Questions 
Binary Search Tree Iterator, Flatten 2D Vector, Zigzag Iterator

Error Message:
Line 23: no match for 'operator=' (operand types are 'std::vector<int>::iterator {aka __gnu_cxx::__normal_iterator<int*, std::vector<int> >}' and 'std::vector<int>::const_iterator {aka __gnu_cxx::__normal_iterator<const int*, std::vector<int> >}')

Next challenges: Implement Queue using Stacks, Shortest Word Distance II, LFU Cache

Runtime: 3 ms
Your runtime beats 97.22 % of cpp submissions.

*/


// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
    // PeekingIterator is the child of Iterator 
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    it=nums.begin();
        ed=nums.end();
	}
    // 0-hasNext(); 1-peek(); 2-next() 

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return *it;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        int nx=*it;
        it++;
        return nx;
	}

	bool hasNext() const {
	    return it!=ed;
	}
    
    vector<int>::const_iterator it, ed;
};

