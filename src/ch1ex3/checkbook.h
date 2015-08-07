// checkbook.h - A class for a checkbook

class Checkbook
{
public:
	void setBalance( float amount ){ balance = amount; }
	bool writeCheck( float amount );  // Returns false if amount is greater than balance; 
	                                  // otherwise returns true
	void deposit( float amount ){ balance += amount; lastDeposit = amount; }
	float getBalance( ){ return balance; }
	float getLastCheck( ){ return lastCheck; }
	float getLastDeposit( ){ return lastDeposit; }
private:
	float balance;
	float lastCheck;
	float lastDeposit;
};
