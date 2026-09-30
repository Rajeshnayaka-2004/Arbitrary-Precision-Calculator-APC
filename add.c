#include "apc.h"

void addition(node *tail1, node *tail2, node **headR, node **tailR)
{
    int count = 0;

    while(tail1 || tail2)
    {
        int res = 0;
        if(tail1 == NULL)
          res = tail2->data;
        else if(tail2 == NULL)
          res = tail1->data ;
        else
         res = tail1->data + tail2->data;

        if(count == 1)
        {
           res = res + 1;
           count = 0; 
        }

        if(res > 9)
        {
            res = res % 10;
            count = 1;
        }

        insert_first(headR , tailR , res);

        if(tail1 != NULL)
          tail1 = tail1->prev;
        
        if(tail2 != NULL)
          tail2 = tail2->prev;

    }

    if(count == 1)
     insert_first(headR , tailR , 1);
}
