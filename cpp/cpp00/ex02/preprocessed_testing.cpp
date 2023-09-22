# 1 "testing.cpp"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 383 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "testing.cpp" 2
# 1 "./Account.hpp" 1
# 19 "./Account.hpp"
class Account {


public:

 typedef Account t;

 static int getNbAccounts( void );
 static int getTotalAmount( void );
 static int getNbDeposits( void );
 static int getNbWithdrawals( void );
 static void displayAccountsInfos( void );

 Account( int initial_deposit );
 ~Account( void );

 void makeDeposit( int deposit );
 bool makeWithdrawal( int withdrawal );
 int checkAmount( void ) const;
 void displayStatus( void ) const;


private:

 static int _nbAccounts;
 static int _totalAmount;
 static int _totalNbDeposits;
 static int _totalNbWithdrawals;

 static void _displayTimestamp( void );

 int _accountIndex;
 int _amount;
 int _nbDeposits;
 int _nbWithdrawals;

 Account( void );

};
# 2 "testing.cpp" 2

int main(void)
{
 return 0;
}
