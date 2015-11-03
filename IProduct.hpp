#include <iostream>
#include <string>
using namespace std;

#ifndef _IPRODUCT_H_
#define _IPRODUCT_H_
/* Interface which will be used by every Product */
class IProduct
{
public :
	/* return correct price of the product for n items */
	virtual double getPrice(int volume) = 0 ;

	virtual const std::string& getCode() const = 0 ;
	
	/* print helper */
	virtual std::string toString() const = 0;

	/* operator == over loaded for stl::find function  
        friend bool operator == (IProduct *product, const std::string code)
        {
                bool  matched = false;
                if(code == product->getCode())
                {
                        matched = true;
                }
                return matched;
        }*/

	virtual ~IProduct(){};
};

#endif

