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
		PointOfSaleTerminal *terminal = new PointOfSaleTerminal(*inventory);
		for(int i = 1; i < argc ; i++)
		{
			terminal->scan(argv[i]);
		}
		terminal->calculateTotal();
		delete terminal;
		delete inventory;
	}
	return 0;
}
