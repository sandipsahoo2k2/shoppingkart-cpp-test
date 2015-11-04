#include "Inventory.hpp"
#include "PointOfSaleTerminal.hpp"
using namespace std;

/* For interviewer's comfort this programme has been written to take products code in command line */
/* If you want to run this in intercative mode recompile uncommenting the below line #define INTERACTIVE_MODE 1 */

//#define INTERACTIVE_MODE 1

void interctiveScan(PointOfSaleTerminal &pos)
{
	std::string inputCode ; 
	std::cout << "\n\nPlease enter the product code to scan \nJust type DONE to finish scan and make billing: ";
	std::cin >>  inputCode;
	while(inputCode != "DONE")
	{
		pos.scan(inputCode);
		/* Calculating prices in realtime */
		pos.calculateTotal(); //if it is too irritating please comment this line and recompile :)
		std::cout << "\nScan next: ";
		std::cin >>  inputCode;
	}
	pos.calculateTotal(); 
}

  
int main(int argc, char *argv[])
{
	Inventory *inventory = new Inventory();
	PriceManager *priceManager = new PriceManager();

	/* print the contents of PriceManager */
	//std::cout << priceManager->toString();	//**** This is a commented code, helps in sanity testing

	/* get and print the pricing info for a prodduct code e.g A1 */
	//priceManager->getPriceMap("A1"); 		//**** This is a commented code, helps in sanity testing

	/* Initialise the POS with inventory and price manager */
	PointOfSaleTerminal *terminal = new PointOfSaleTerminal(*inventory, *priceManager);

#ifndef INTERACTIVE_MODE
	if ( argc < 2 )
	{
		std::cout << "\n\nPlease enter product codes separated by space as command line\n" ;
	}
	else
	{
		for(int i = 1; i < argc ; i++)
		{
			terminal->scan(argv[i]);
		}
		terminal->calculateTotal();
	}
#else
	interctiveScan(*terminal);
#endif

	delete terminal;
	delete priceManager;
	delete inventory;
	return 0;
}


