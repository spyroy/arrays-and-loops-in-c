#include <stdio.h>
#include "myBank.h"


int main(int argc, char **argv)
{
	char choice;
	int bankAccount;
	double ammount;
	double add;
	double pull;
	do{
		printf("please enter: 'O' to Open new bank account, 'B' to check balance on opened account, 'D' to deposite money to opened account, 'W' to withdraw from opened account, 'C' to close an opened account, 'I' to add interest to all opened accounts, 'P' to print all opened accounts and their balance, 'E' to escape \n");
		scanf("%c", &choice);

		switch(choice)
		{
			case 'O':
				printf("transection type?: O\n");	
				printf("please enter ammount to initial bank account \n");
				scanf(" %lf", &ammount);
				bankAccount = open(ammount);
				if(bankAccount == -1)
					printf("err:all accounts are taken"); break;
				printf("initial deposite?: %lf\n", ammount);
				printf("your account number is: %d\n" , bankAccount);
				break;
			case 'B':
				printf("transection type?: B\n");
				printf("please enter account number (901-950) to check balance \n");
				scanf("%d", &bankAccount);
				if(balance(bankAccount)== -1)
					printf("err: this account is closed\n"); break;
				printf("account_number?: %d your balance is: %0.2lf\n", bankAccount, balance(bankAccount));
				break;
			case 'D':
				printf("transection type?: D\n");
				printf("please enter account number (901-950) and the ammount you want to deposit \n");
				scanf(" %d %lf",&bankAccount, &add);
				if(deposit(bankAccount,add) == -1)
					printf("err: the account is closed\n"); break;
				printf("account_number?: %d \n you added %lf \n and your new balance is: %0.2lf \n", bankAccount, add, deposit(bankAccount,add));
				break;				
			case 'W':
				printf("transection type?: W\n");
				printf("please enter account number (901-950) and the ammount you want to withdraw \n");
				scanf(" %d %lf",&bankAccount, &pull);
				if (withdraw(bankAccount, pull) == -1)
					printf("err: the account is closed/ you don't have enough money to withdraw\n"); break;
				printf("account_number?: %d \n you withdrew %0.2lf \n and your new balance is: %0.2lf \n", bankAccount, pull, withdraw(bankAccount, pull));
				break;
			case 'C':
				printf("transection type?: C\n");
				printf("please enter account number (901-950) to close this account \n");
				scanf(" %d", &bankAccount);
				close(bankAccount);
				break;
			case 'I':
				printf("transection type?: I\n");
				printf("please enter interest (0.x for x%) to add to all open accounts \n");
				break;
				//fix
			case 'P':
				printf("transection type?: P\n");
				printf("printing all bank accounts and their balance...\n");
				print();
				break;
			case 'E':
				printf("transection type?: E\n");
				printf("closing all bank accounts...\n");
				printf("thank you and goodbye\n");
				escape();
				break;
		}
	} while(choice != 'E');
	
	
	return 0;
}
