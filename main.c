#include <stdio.h>
#include "myBank.h"


int main(int argc, char **argv)
{
	char choice;
	int bankAccount;
	double ammount;
	double add;
	double pull;
	double inter;
	int check;
	do{
		printf("please enter (capital): \n 'O' to Open new bank account\n 'B' to check balance on opened account\n 'D' to deposite money to opened account\n 'W' to withdraw from opened account\n 'C' to close an opened account\n 'I' to add interest to all opened accounts\n 'P' to print all opened accounts and their balance\n 'E' to escape \n");
		scanf(" %c", &choice);

		switch(choice)
		{
			case 'O':
				printf("transection type?: O\n");	
				printf("please enter ammount to initial bank account \n");
				check = scanf(" %lf", &ammount);
				if(check !=1){
					printf("err: not a real number");
					break;
				}
				bankAccount = open(ammount);
				if(bankAccount == -1){
					printf("err:all accounts are taken \n"); 
					break;
				}
				printf("initial deposite?: %0.2lf\n", ammount);
				printf("your account number is: %d\n" , bankAccount);
				break;
			case 'B':
				printf("transection type?: B\n");
				printf("please enter account number (901-950) to check balance \n");
				check = scanf("%d", &bankAccount);
				if(check!=1){
					printf("err: not a natural number");
					break;
				}
				if(balance(bankAccount)== -1){
					printf("err: this account is closed\n"); 
					break;
				}
				printf("account_number?: %d your balance is: %0.2lf\n", bankAccount, balance(bankAccount));
				break;
			case 'D':
				printf("transection type?: D\n");
				printf("please enter account number (901-950) and the ammount you want to deposit, seperated with space \n");
				check = scanf(" %d %lf",&bankAccount, &add);
				if(check !=2){
					printf("err: wrong input");
					break;
				}
				double added = deposit(bankAccount,add);
				if(added == -1){
					printf("err: the account is closed\n");
					break;
				}
				printf("account_number?: %d \n you added %0.2lf \n and your new balance is: %0.2lf \n", bankAccount, add, added);
				break;				
			case 'W':
				printf("transection type?: W\n");
				printf("please enter account number (901-950) and the ammount you want to withdraw, seperated with space \n");
				check = scanf(" %d %lf",&bankAccount, &pull);
				if(check !=2){
					printf("err: wrong input");
					break;
				}
				double withdrew = withdraw(bankAccount, pull);
				if (withdrew == -1){
					printf("err: the account is closed/ you don't have enough money to withdraw\n");
					break;
				}
				printf("account_number?: %d \n you withdrew %0.2lf \n and your new balance is: %0.2lf \n", bankAccount, pull, withdrew);
				break;
			case 'C':
				printf("transection type?: C\n");
				printf("please enter account number (901-950) to close this account \n");
				check = scanf(" %d", &bankAccount);
				if(check !=1){
					printf("err: not a natural number");
					break;
				}
				close(bankAccount);
				break;
			case 'I':
				printf("transection type?: I\n");
				printf("please enter interest to add to all open accounts \n");
				check = scanf("%lf", &inter);
				if(check !=1){
					printf("err: not a real number");
					break;
				}
				interest(inter);
				printf("interest added to all open accounts");
				break;
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
