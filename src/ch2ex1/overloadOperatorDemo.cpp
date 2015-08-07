#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

struct CarType
{
	string maker;
	int year;
	float price;
	bool operator >( int num ){ if ( price > num ) return true; return false; }
};

int main( )
{
	CarType myCar;
	myCar.maker = "Mercedes";
	myCar.year = 2005;
	myCar.price = 58000;
	
	if ( myCar > 2000 )  // equals to 
		                   // if ( myCar.operator>( 2000 ) )
	{
		cout << "My car is more than 2000!" << endl;
	}
	return 0;
}
