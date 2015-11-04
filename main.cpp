#include "Inventory.hpp"
#include "PointOfSaleTerminal.hpp"
using namespace std;

int main(int argc, char *argv[])
{
	if ( argc < 2 )
	{
		std::cout << "\nPlease enter product codes separated by space as command line\n" ;
	}
	else
	{
		Inventory *inventory = new Inventory();
		PriceManager *priceManager = new PriceManager();
		//std::cout << priceManager->toString();
		PointOfSaleTerminal *terminal = new PointOfSaleTerminal(*inventory, *priceManager);
		for(int i = 1; i < argc ; i++)
		{
			terminal->scan(argv[i]);
		}
		terminal->calculateTotal();
		delete terminal;
		delete priceManager;
		delete inventory;
	}
	return 0;
}
