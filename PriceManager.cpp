#include "PriceManager.hpp"
#include <sstream>

PriceManager::PriceManager()
{
	initialise();
}

void PriceManager::initialise()
{
        std::cout << "\n\nPriceManager Initilising store prices ....\n";

        addPrice("A1", 1, 1.25);
        addPrice("A1", 3, 3);
       	addPrice("3-Q", 1, 4.25);
       	addPrice("45K11", 1, 1);
	addPrice("45K11" , 6, 5);
        addPrice("X1", 1, 0.75);

        std::cout << "\n\nInitilisation finished with " << prices.size() << " prices\n";
}

void PriceManager::addPrice(std::string code, int volume, double price)
{
	std::pair<std::string, int> codeKey = std::make_pair(code, volume);
	std::cout << "\nPrice for " << volume << " units of " << code << " is $" << price << " added.";
        prices[codeKey] = price;
}

void PriceManager::removePrice(std::string code, int volume)
{
	std::pair<std::string, int> codeKey = std::make_pair(code, volume);
	prices.erase(codeKey);	
}

std::string PriceManager::toString()
{
	std::ostringstream ss;
	ss << "\nPrinitng pricing info for all products" << std::endl;
	for(std::map<std::pair<std::string, int>, double>::iterator itr = prices.begin(); itr != prices.end(); ++itr)
	{
		/* Map is sorted with highest volume/price first */
		std::pair<std::string, int> tempCodeKey = itr->first;
		double itrPrice = itr->second;
		ss << "\nPrice for " << tempCodeKey.second << " " << tempCodeKey.first << " is $" << itrPrice << std::endl;
	}
	return std::string(ss.str());
}

double PriceManager::getPrice(std::string code, int volume)
{
	double totalPrice = 0;
	bool matchCodeStart = false;
	int countMatchOffers = 0;
	std::cout << "\nCalculating price for " << volume << " " << code << "..."; 
	/* get the first highest volume, price mapping and calculate the total price */
	for(std::map<std::pair<std::string, int>, double>::iterator itr = prices.begin(); itr != prices.end(); ++itr)
	{
		/* Map is sorted with highest volume/price first */
		std::pair<std::string, int> tempCodeKey = itr->first;
		double itrPrice = itr->second;
		std::string itrCode = tempCodeKey.first ;	
		int itrVolume = tempCodeKey.second ;
		if (code == itrCode) //code found
		{
			matchCodeStart = true;
			countMatchOffers ++ ;
			int factor = volume / itrVolume ;
        		int remainder = volume % itrVolume;
        		totalPrice += factor * itrPrice ;
			if(remainder == 0)
			{
				std::cout << "\n\t\t$" << totalPrice ; 
				break;
			}
			else
			{
				volume = remainder;
			}
		}
		else if(matchCodeStart == true)
		{
			std::cout << "\nMatched keys " << countMatchOffers ; 
			break;
		}
	}
	if(matchCodeStart == false)
	{
		std::cout << "\nPrice for " << code << " is missing in the pricing manager !" ; 
	}
	return totalPrice;
}
