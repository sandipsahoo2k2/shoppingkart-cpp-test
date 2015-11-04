#include "Inventory.hpp"
#include "Product.hpp"

Inventory::Inventory()
{
	initialise();
}

Inventory::~Inventory()
{
	for(std::map<IProduct*, int>::iterator itr = storeProducts.begin(); itr != storeProducts.end(); itr++)
	{
		IProduct *p = itr->first;
		delete p; 
	}
}

void Inventory::initialise()
{
	std::cout << "\nInventory Initilising store products ....\n";

	addProduct("A1");
	addProduct("3-Q");
	addProduct("45K11");
	addProduct("X1");

	std::cout << "\n\nInitilisation finished with " << storeProducts.size() << " products";
}

IProduct* Inventory::getProduct(std::string code)
{
	IProduct * product = NULL;
	/* Check the product in store */
	for(std::map<IProduct*, int>::iterator itr = storeProducts.begin(); itr != storeProducts.end(); itr++)
	{
		IProduct* temp = itr->first;
		if(temp->getCode() == code)
		{
			product = temp;
			break;
		}
	}
	return product;
}

void Inventory::addProduct(std::string code)
{
	Product *product = new Product(code);
	std::cout << *product << " added.";
	
	std::map<IProduct*, int>::iterator itr = storeProducts.find(product);
                if(itr == storeProducts.end()) //not found
                {
                        storeProducts[product] = 1;
                }
                else //update the count
                {
                        storeProducts[product]++;
                }
}

void Inventory::removeProduct(std::string code)
{
	IProduct * product = NULL;
	/* Check the product in store */
	for(std::map<IProduct*, int>::iterator itr = storeProducts.begin(); itr != storeProducts.end(); itr++)
	{
		IProduct* temp = itr->first;
		if(temp->getCode() == code)
		{
			product = temp;
			storeProducts.erase(product);	
			break;
		}
	}
}


