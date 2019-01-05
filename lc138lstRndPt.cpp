
/*
Leetcode 138. Copy List with Random Pointer

Companies  
Amazon, Microsoft, Bloomberg, Facebook, Google, Alibaba, LinkedIn, Mathwork, Adobe, Uber 
Related Topics 
Hash Table, Linked List 
Similar Questions 
Clone Graph

Next challenges: Encode and Decode TinyURL, Replace Words, Design HashSet



*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
// Runtime: 64 ms, faster than 7.06% of C++ online submissions for Copy List with Random Pointer.
// slower, probably b/c need to check whether in hash table each time
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // O(n) time, one pass 
		if(!head)	return head;
        
		unordered_map<RandomListNode*,RandomListNode*> um;
		unordered_map<RandomListNode*,RandomListNode*>::iterator umi;		
        RandomListNode *og=head, *th=new RandomListNode(og->label), *lt=th, *rd, *rt=th;// th,lt,rd: current,last,random node 
		um.emplace( og, th);
		if(og->random){
			rd=new RandomListNode( og->random->label);
			um.emplace( og->random, rd);
			th->random=rd;
		}
		
		for( og=og->next; og; og=og->next){
			umi=um.find(og);
			if(umi!=um.end()){
				th=umi->second;
			}else{
				th=new RandomListNode(og->label);
				um.emplace(og,th);
			}
			lt->next=th;
            
			if(og->random){
				umi=um.find(og->random);
				if(umi!=um.end()){
					rd=umi->second;
				}else{
					rd=new RandomListNode(og->random->label);
					um.emplace( og->random, rd);
				}
				th->random=rd;
			}
			
			lt=th;
		}
		
		return rt;
    }
};

// Runtime: 32 ms	Your runtime beats 48.60 % of cpp submissions.
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // give me new understanding about unordered_map 
        if(!head)   return head;
        unordered_map<RandomListNode *,RandomListNode *> um;
        unordered_map<RandomListNode *,RandomListNode *>::iterator umi;
        RandomListNode * rt=new RandomListNode(head->label), * lh=head, * lt=rt;
		um.emplace( lh, rt);
        
        for( lh=head->next; lh; lh=lh->next){
            RandomListNode * ln=new RandomListNode(lh->label);
            lt->next=ln;
			lt=ln;
            um.emplace( lh, ln);
        }
        
        for( lh=head, lt=rt; lh; lh=lh->next, lt=lt->next){
            umi=um.find(lh->random);
            if(umi!=um.end())   lt->random=umi->second;
        }
        
        return rt;
    }
};
