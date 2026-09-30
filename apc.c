#include "apc.h"

int cla_validation(int argc, char *argv[])
{
    if(argc != 4)
        return FAILURE;

    int i = 0;
    if(argv[1][0] == '+' || argv[1][0] == '-')
        i++;
    while(argv[1][i])
    {
        if(!isdigit(argv[1][i]))
            return FAILURE;
        i++;
    }
    i = 0;
    if(argv[3][0] == '+' || argv[3][0] == '-')
        i++;
    while(argv[3][i])
    {
        if(!isdigit(argv[3][i]))
            return FAILURE;
        i++;
    }
    char ch = argv[2][0];
   
    if(ch == '+' || ch == '-' || ch == 'x' || ch == '/' || ch == '%' || ch == '^')
        return SUCCESS;
    
    return FAILURE;
}

int insert_last(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node));
        if(new == NULL)
            return FAILURE;
        new->data = data;
        new->next = NULL;
                new->prev = NULL;
    if(*head == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS;   
    }
    new->prev = *tail;
    (*tail)->next = new;
    *tail = new;
    return SUCCESS;
}


void create_list(char *opr, node **head, node **tail)
{
    int i = 0;
    if(opr[i] == '+' || opr[i] == '-')
        i++;
    while(opr[i])
    {
        if(insert_last(head, tail, opr[i] - 48) == FAILURE)
        {
            printf("Error while creating list");
            return;
        }
        i++;
    }
}

int insert_first(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node));
    if(new == NULL)
        return FAILURE;
    new->data = data;
    new->prev = NULL;
    if(*tail == NULL)
    {
        *tail = new;
        *head = new;
        new->next = NULL;
        return SUCCESS;
    }
    (*head)->prev = new;
    new->next = *head;
    *head = new;
    return SUCCESS;
}

void print_list(node *head)
{
	
	if (head == NULL)
	{
		return;
	}
	else
	{
	    while (head)		
	    {
		    printf("%d", head -> data);

		    head = head -> next;
	    }
        printf("\n");
    }
}

int list_len(node *head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

int compare_list(node *head1, node *head2)
{
    int len1 = list_len(head1);
    int len2 = list_len(head2);

    if(len1 > len2)
        return OPERAND1;
    if(len1 < len2)
        return OPERAND2;
    
    while(head1 != NULL)
    {
        if(head1->data > head2->data)
            return OPERAND1;
        if(head1->data < head2->data)
            return OPERAND2;
        head1 = head1->next;
        head2 = head2->next;
    }
    return SAME;
}


void remove_pre_zeros(node **head)
{
    node *temp = *head;
    while(temp->data == 0)
    {
        if(temp->next == NULL)
            break;
        *head = temp->next;
        free(temp);
        temp = *head;
        temp->prev = NULL;   
    }
  
}

int delete_list(node **head, node **tail)
{
    if(*head == NULL)
        return FAILURE;
    node *temp = *head;
    
    while(temp != NULL)
    {
        *head = temp->next;
        free(temp);
        temp = *head;
    }
    
    *tail = NULL;
}

void sign_check(int* n1, int* p1, int* n2, int* p2, char *op1, char* op2)
{
    if(op1[0] == '-')
    {
        *n1 = 1;
    }
    else
    {
        *p1 = 1;
    }

    if(op2[0] == '-')
    {
        *n2 = 1;
    }
    else
    {
        *p2 = 1;
    }
}

void actual_operation(int n1, int p1, int n2, int p2, char *op, int * sign, node *head1, node *head2)
{
    int n = compare_list(head1, head2);
    if(*op == '+')
    {
        if(p1 == 1 && p2 == 1)
        {
            *op = '+';
            *sign = 1;
        }
        else if(n1 == 1 && p2 == 1)
        {
            *op = '-';
            if(n == OPERAND1)   
                *sign = -1;
        }
        else if(p1 == 1 && n2 == 1)
        {
            *op = '-';
            if(n == OPERAND2)
                *sign = -1;
        }
        else
        {
            *op = '+';
            *sign = -1;
        }
    }
    else if(*op == '-')
    {
        if(p1 == 1 && p2 == 1)
        {
            *op = '-';
            if(n == OPERAND2)
                *sign = -1;
        }
        else if(n1 == 1 && p2 == 1)
        {
            *op = '+';
            if(n == OPERAND1)
                *sign = -1;
        }
        else if(p1 == 1 && n2 == 1)
        {
            *op = '+';
        }
        else
        {
            *op = '-';
            if(n == OPERAND1)
                *sign = -1;
        }
    }
    else if(*op == 'x')
    {
        if(p1 != p2 || n1 != n2)
            *sign = -1;
    }
    else
    {
        if(p1 != p2 || n1 != n2)
            *sign = -1;
    }
}