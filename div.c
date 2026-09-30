#include "apc.h"

void division(node *headL1, node *headOPR2, node *tailOPR2, node **headR, node **tailR)
{
    node *headOPR1 = NULL, *tailOPR1 = NULL, *headSR = NULL, *tailSR = NULL;
    node *L1temp = headL1;

    insert_last(&headOPR1, &tailOPR1, L1temp->data);

    while(compare_list(headOPR1, headOPR2) == OPERAND2)
    {
        L1temp = L1temp->next;
        insert_last(&headOPR1, &tailOPR1, L1temp->data);
    }
   
    while(L1temp != NULL)
    {
        int sub_count = 0;
        int res = compare_list(headOPR1, headOPR2);
        while(res == OPERAND1 || res == SAME)
        {   
            subtraction(tailOPR1, tailOPR2, &headSR, &tailSR);  
            delete_list(&headOPR1, &tailOPR1);
            
            headOPR1 = headSR;
            tailOPR1 = tailSR;
            headSR = NULL;
            tailSR = NULL;
            sub_count++;
            
            res = compare_list(headOPR1, headOPR2);
            
        }
        
        insert_last(headR, tailR, sub_count);

        L1temp = L1temp->next;

        if(L1temp != NULL)
            insert_last(&headOPR1, &tailOPR1, L1temp->data);
        
        remove_pre_zeros(headR);

        remove_pre_zeros(&headOPR1);
        
    }
}