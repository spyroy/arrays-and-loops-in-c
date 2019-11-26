#define bank_accounts 50

double arr[bank_accounts][2];

int open(double ammount); // if the user typed "O". 
double balance(int bankAccount); //if the user typed "B".
double deposit(int bankAccount, double ammount); //if the user typed "D".
double withdraw(int bankAccount, double withdraw); //if the user typed "W". 
void close(int bankAccount); //if the user typed "C". 
void interest(double inter); //if the user typed "I". 
void print(); //if the user typed "P". 
void escape(); //if the user typed "E".
