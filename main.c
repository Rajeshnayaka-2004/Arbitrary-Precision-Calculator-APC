#include "apc.h"

int main(int argc, char *argv[])
{
    node *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;

	int op1_nf = 0, op1_pf = 0, op2_nf = 0, op2_pf = 0, sign = 1;

    if(cla_validation(argc, argv) == FAILURE)
	{
		
		printf("Validation Unsuccessful,\nPlease enter the following parameters:\n./a.out (operand 1) (operator) (operand 2)\n");
		printf("Note: operands must contain only digits ,sign and available operators are '+', '-', 'x', '/', '%%', '^'\n");
		
		return FAILURE;
	}

	sign_check(&op1_nf, &op1_pf, &op2_nf, &op2_pf, argv[1], argv[3]);

    create_list(argv[1], &head1, &tail1);

	create_list(argv[3], &head2, &tail2);

    char oper = argv[2][0];
	
	actual_operation(op1_nf, op1_pf, op2_nf, op2_pf, &oper, &sign, head1, head2);

    switch(oper)
    {
	case '+':
	    addition(tail1, tail2, &headR, &tailR);

		if(sign == -1)
			printf("-");

		print_list(headR);
	    break;

	case '-':
		int n = compare_list(head1, head2);

		if(n == OPERAND1)
			subtraction(tail1, tail2, &headR, &tailR);

		if(n == OPERAND2)
			subtraction(tail2, tail1, &headR, &tailR);

		if(n == SAME)
		{
			printf("0\n");
			break;
		}	

		if(sign == -1)
			printf("-");

		print_list(headR);
	    break;

	case 'x':
	case 'X':
		multiplication(tail1, tail2, &headR, &tailR);

		if(sign == -1)
			printf("-");

		print_list(headR);
	    break;

	case '/':
		division(head1, head2, tail2, &headR, &tailR);

		if(sign == -1)
			printf("-");

		print_list(headR);
	    break;
	
	case '%':
		division(head1, head2, tail2, &headR, &tailR);

		if(sign == -1)
			printf("-");
		
		print_list(headR);
	    break;

	default:
	    printf("Invalid operator\n");
		
    }
}