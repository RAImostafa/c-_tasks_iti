#include<iostream>
#include <string>
#include <vector>



class BankAccount
{

int ID_number ;
std::string name;
std::string type;
double balance;

public:

BankAccount (std::string name, std::string type , int ID_number , double balance ):name(name) ,type(type) , ID_number( ID_number), balance(balance)
{}

void Deposit (double funds) {
  this->balance += funds;
   std::cout << "Deposit successful! New balance: $" << this->balance << std::endl;
}
void Withdraw (double funds) {
  if (this->balance >= funds)
  { 
    this->balance -= funds;
    
   std::cout << "Withdrawal successful! New balance: $" << this->balance << std::endl;

  }
  else {
    std::cout<<"failed!";
  }
}

double GetAccountBalance  (void) const {return balance; }
std::string GetAccountHolder(void) const {return name;}
std::string GetAccountType (void) const {return type;}
int GetAccountNumber (void) const {return ID_number;}
void DisplayAccountInfo (void) const 
{
  std::cout<<"ID_number: ["<<ID_number<< "], name: ["<<name<<"], balance: ["<<balance<<"], account type: ["<<type<<"]" << std::endl;
}
};


class Bank
{
  std::vector<BankAccount> bankAccounts;
  static int counter;
  public:
  
 
void AddAccount(std::string acc_name, std::string acc_type, int acc_ID_number, double acc_balance) {
    for (int i = 0; i < counter; i++) {
        if (bankAccounts[i].GetAccountNumber() == acc_ID_number) {
            std::cout << "Invalid ID, try again." << std::endl;
            return;
        }
    }
    bankAccounts.push_back(BankAccount(acc_name, acc_type, acc_ID_number, acc_balance));
    counter++;
}

  double GetTotalBalance( int acc_ID_number)
  {
    double totalBalance =0.0;
    for (int i = 0; i < counter; i++)
    {
        if(bankAccounts[i].GetAccountNumber()==  acc_ID_number)
        {
          totalBalance += bankAccounts[i].GetAccountBalance();
        }
    }
    return totalBalance;
  
  }

  void DisplayAllAccounts(void) const
  {
    
    for (int i = 0; i < counter; i++)
    {
      std::cout<<"ID_number: ["<<bankAccounts[i].GetAccountNumber()<< "], name: ["<<bankAccounts[i].GetAccountHolder()<<"], balance: ["<<bankAccounts[i].GetAccountBalance()<<"], account type: ["<<bankAccounts[i].GetAccountType()<<"]" << std::endl;
    }
  
  }


  void DepositToAccount(int acc_ID_number, double amount) {
    for (auto &account : bankAccounts) {
        if (account.GetAccountNumber() == acc_ID_number) {
            account.Deposit(amount);
            std::cout << "Deposited $" << amount << " to account ID " << acc_ID_number << std::endl;
            return;
        }
    }
    std::cout << "Account ID " << acc_ID_number << " not found." << std::endl;
}

void WithdrawFromAccount(int acc_ID_number, double amount) {
    for (auto &account : bankAccounts) {
        if (account.GetAccountNumber() == acc_ID_number) {
            account.Withdraw(amount);
            std::cout << "Withdrawn $" << amount << " from account ID " << acc_ID_number << std::endl;
            return;
        }
    }
    std::cout << "Account ID " << acc_ID_number << " not found." << std::endl;
}

};


int Bank::counter =0;




int main(){

int option;

 Bank bank;
    bank.AddAccount("John Doe", "Savings", 1001 , 1500.0);
    bank.AddAccount("Alice Smith", "Checking", 1002, 2000.0);




std::cout<<"choose by entering the number of the service "<<std::endl;

std::cout<< "1.Creat an account \n"
            "2.Deposite funds\n"
            "3.withdraw funds \n" 
            "4.Total Balance \n"
            "5.Display all acounts \n"  
            "6.Exit \n" 
            << std::endl;
std::cin >> option; 

if (option == 1)
{
  
  std::cout <<"enter your name : " <<std::endl;
  std::string name;
  std::cin >> name;
  std::cout <<"enter your ID number " <<std::endl;
  int ID;
  std::cin >> ID;
  std::cout <<"enter the type" <<std::endl;
  std::string type;
  std::cin >> type;
  std::cout <<"enter your acc balance " <<std::endl;
  double balance;
  std::cin >> balance;
  bank.AddAccount(name, type, ID, balance);
 std::cout<<"account created successfully"<<std::endl;
}
else if( option ==2){
int id;
   double amount;
            std::cout << "Enter your bank account ID: ";
            std::cin >> id;
            std::cout << "Enter the amount to deposit: ";
            std::cin >> amount;
bank.DepositToAccount(id, amount); 

}
else if(option == 3){
  int id;
            double amount;
            std::cout << "Enter your bank account ID: ";
            std::cin >> id;
            std::cout << "Enter the amount to withdraw: ";
            std::cin >> amount;
            bank.WithdrawFromAccount(id, amount); 
 }
else if(option == 4){
   int id;
            std::cout << "Enter your bank account ID: ";
            std::cin >> id;
            std::cout << "Total balance for account " << id << ": $" << bank.GetTotalBalance(id) << std::endl;
 }
else if(option == 5){
  std::cout << "All accounts:" << std::endl;
  bank.DisplayAllAccounts();
}
else if(option != 6){
   std::cout << "Exiting program." << std::endl;
   
 }
else {
  std::cout << "Invalid option, please try again." << std::endl;
}


  return 0;
}