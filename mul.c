#include "apc.h"

void multiplication(node *tail1, node *tail2, node **headR1, node **tailR1)
{
    node *temp1 = tail1, *temp2 = tail2;
    int count = 0, carry = 0;
    node *headR2 = NULL, *tailR2 = NULL, *headAR = NULL, *tailAR = NULL;
    
    while(temp2 != NULL)
    {
        for(int i = 0; i < count; i++)
        {
            insert_last(&headR2, &tailR2, 0);
        }
        while(temp1 != NULL)
        {
            int res = (temp1->data * temp2->data) + carry;
            if(res > 9)
            {
                carry = res / 10;
                res = res % 10;
            }
            else
                carry = 0;
            if(count == 0)
                insert_first(headR1, tailR1, res);
            else
                insert_first(&headR2, &tailR2, res);

            temp1 = temp1->prev;
        }
        if(carry > 0)
        {
            if(count == 0)
                insert_first(headR1, tailR1, carry);
            else
                insert_first(&headR2, &tailR2, carry);
            carry = 0;
        }
        addition(*tailR1, tailR2, &headAR, &tailAR);

        delete_list(headR1, tailR1);
        delete_list(&headR2, &tailR2);

        *headR1 = headAR;
        *tailR1 = tailAR;

        headAR = NULL;
        tailAR = NULL;

        temp2 = temp2->prev;
        temp1 = tail1;
        count++;
    }
    if(carry > 0)
        insert_first(headR1, tailR1, carry);
   
    remove_pre_zeros(headR1);
}
