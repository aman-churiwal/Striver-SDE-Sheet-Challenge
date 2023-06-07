LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    //if(!head || !head->next) return NULL;
    LinkedListNode<int> *n_next = NULL;
    LinkedListNode<int> *curr = NULL;
    LinkedListNode<int> *prev = head;

    while(prev != NULL){
        n_next = curr;
        curr = prev;
        prev = prev->next;

        curr->next = n_next;
    }
   
    return curr;
}