
/*
Leetcode 138. Copy List with Random Pointer

Companies  
Amazon, Microsoft, Bloomberg, Facebook, Google, Alibaba, LinkedIn, Mathwork, Adobe, Uber 
Related Topics 
Hash Table, Linked List 
Similar Questions 
Clone Graph

Next challenges: Encode and Decode TinyURL, Replace Words, Design HashSet

Runtime: 32 ms
Your runtime beats 48.60 % of cpp submissions.

*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
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
