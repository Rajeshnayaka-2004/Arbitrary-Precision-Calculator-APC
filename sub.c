#include "apc.h"

void subtraction(node *tail1, node *tail2, node **headR, node **tailR)
{
    int borrow = 0;
    
    node *temp1 = tail1;
    node *temp2 = tail2;
    int data1, data2;
    while(temp1 != NULL)
    {
        
        if(borrow == 1)
        {
            temp1->data--;
            borrow = 0;
        }
        
        if(temp2 == NULL)
            data2 = 0;
        else    
            data2 = temp2->data;

        if(temp1->data < data2)
        {
            temp1->data = temp1->data + 10;
            borrow = 1;
        }   

        
        data1 = temp1->data;
        
        insert_first(headR, tailR, data1 - data2);

        temp1 = temp1->prev;
        
        if(temp2 != NULL)
            temp2 = temp2->prev;
            
        
    }
    remove_pre_zeros(headR);
    
}
