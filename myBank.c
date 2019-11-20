#include <stdio.h>
#include "myBank.h"



int open(double ammount) 
{ 
	int i; 
	int account_number;
	for (i = 0; i < 50;i++) {
		if (arr[i][1] == 0) {
			arr[i][0] = ammount;
			arr[i][1] = 1;
			account_number = i + 901;
			break;
		}
		else{
			account_number = -1;
		}
	}
	return account_number;
}
double balance(int bankAccount) 
{ 
	double current_balance;
	if (arr[bankAccount-901][1] == 1) {
		current_balance = arr[bankAccount-901][0];
	}
	else{
		current_balance = -1;
	}
	return current_balance;
}
double deposit(int bankAccount, double ammount) 
{ 
	double current_balance;
	if (arr[bankAccount-901][1] == 1) {
		arr[bankAccount -901][0] += ammount;
		current_balance = arr[bankAccount -901][0];
	}
	else{
		current_balance = -1;
	}
	return current_balance;
}
double withdraw(int bankAccount , double withdraw) 
{
	double new_balance;
	if (arr[bankAccount-901][1] == 1 && withdraw <= arr[bankAccount-901][0]) {
		arr[bankAccount -901][0] = arr[bankAccount -901][0] - withdraw;
		new_balance = arr[bankAccount - 901][0];
	}
	else{
		new_balance = -1;
	}
	return new_balance;
}
void close(int bankAccount) 
{
	if (arr[bankAccount-901][1] == 1) {
		arr[bankAccount - 901][1] = 0;
		arr[bankAccount - 901][0] = 0;
		printf("account_number?: %d is now closed!\n", bankAccount);
	} 
	else {
		printf("err: the account is already closed\n");
	}
}
void interest(double inter) {
	int i;
	for (i = 0; i < 50; i++) {
		if (arr[i][1] == 1) {
			arr[i][0] = arr[i][0] + (arr[i][0] * inter);
		}
	}
}
void print() 
{ 
	int i;
	for(i = 0; i < 50; i++){
		if(arr[i][1] == 1){
			printf("account number: %d amount: %0.2lf\n", i+901 , arr[i][0]);
		}
	}
}
void escape() 
{
	int i;
	for(i = 0; i < 50; i++){
		if (arr[i][1] == 1) {
			arr[i][1] = 0;
			arr[i][0] = 0;
		}
	}
	printf("all accounts are now closed\n");
}

