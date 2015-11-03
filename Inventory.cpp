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
	std::cout << "\n//////////////*************////////////////\n";
	std::cout << "\nInitilising store products ....\n";

	addProduct("A1", 1.25, 3, 3);
	addProduct("3-Q", 4.25);
	addProduct("45K11", 1, 6, 5);
	addProduct("X1", 0.75);

	std::cout << "\nInitilisation finished with " << storeProducts.size() << " products\n";
	std::cout << "\n//////////////***********////////////////\n";
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
		}
	}
	return product;
}

void Inventory::addProduct(std::string code, double unitPrice, int volumeFactor, int volumePrice)
{
	Product *product = new Product(code);
	product->setUnitPrice(unitPrice);
	product->setVolumePrice(volumeFactor, volumePrice);
	std::cout << *product << std::endl;
	
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
		}
	}
}


