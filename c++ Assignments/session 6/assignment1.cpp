#include<iostream>
#include <string>
#include <vector>
using namespace std;




class BankAccount
{
protected:
string accountNumber;
double balance;
public:
BankAccount (): accountNumber("null"),balance(0.0){};
BankAccount(string name , double Amountmoney):accountNumber(name),balance(Amountmoney){};
virtual ~BankAccount() {}

double deposit (double additionalDebosites)
{
balance += additionalDebosites;
return balance;
}

double withdraw (double withdrawAmount)
{
if (withdrawAmount <= balance)
{balance -= withdrawAmount;
return balance;}
else{
  cout<<"sorry you don't have enough money"<<endl;
  return 0.0;
}
}

void displayInfo(void) const
{
 
 cout<<"accountNumber:"<<accountNumber<<" balance:"<<balance<<endl;

}

};

class SavingsAccount :public BankAccount
{
   double interestRate;
   public:
   SavingsAccount(string name , double Amountmoney , double rate):BankAccount(name , Amountmoney),interestRate(rate){};
   double CalculateInterest(void)
   {
    balance +=(balance * interestRate);
    return balance;
   }

   void displayInfo(void) const
   { 
       BankAccount::displayInfo();
       cout<<"interest rate:"<<interestRate<<endl;
   }

};

class CheckingAccount :public BankAccount
{
  double transactionFee = 0.0;
  public:
  void deductTransactionFee(double tarnsFees )
  {
     balance -= tarnsFees;
     return;
  }

  void displayInfo(void) const
  {
    BankAccount::displayInfo();
    cout<<"transaction Fees:"<<transactionFee<<endl;
  }

};


int main (void)
{

  SavingsAccount account_one ("1459", 15000 , 0.1);
  account_one.deposit(4000);
  account_one.displayInfo();
  account_one.withdraw(500);
  account_one.displayInfo();
  account_one.CalculateInterest();
  account_one.displayInfo();
  return 0;
}