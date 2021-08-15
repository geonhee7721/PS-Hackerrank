/*
 * insert-a-node-at-a-specific-position-in-a-linked-list - LinkedList - Easy
 * hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/problem
 */

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    
    if (position == 0) {
        newNode->next = llist;
        return newNode;
    } else {
        SinglyLinkedListNode* pp = llist;
        for (int i = 0; i < position - 1; ++i) pp = pp->next;
        
        newNode->next = pp->next;
        pp->next = newNode;
    
        return llist;
    }
}
