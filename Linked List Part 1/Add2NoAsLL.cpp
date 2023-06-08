ListNode *tmphead = new ListNode(-1);
        ListNode *temp = tmphead;

        ListNode *ptr1 = l1, *ptr2 = l2;

        int carry = 0;
        while(ptr1 && ptr2){
            int sum = ptr1->val + ptr2->val + carry;
            carry = sum/10;
            ListNode *curr = new ListNode(sum % 10);
            temp->next = curr;
            temp = curr;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        while(ptr1){
            int sum = ptr1->val + carry;
            carry = sum/10;
            ListNode *curr = new ListNode(sum % 10);
            temp->next = curr;
            temp = curr;
            ptr1 = ptr1->next;
        }

        while(ptr2){
            int sum = ptr2->val + carry;
            carry = sum/10;
            ListNode *curr = new ListNode(sum % 10);
            temp->next = curr;
            temp = curr;
            ptr2 = ptr2->next;
        }

        if(carry){
            temp->next = new ListNode(carry);
        }
        return tmphead->next;