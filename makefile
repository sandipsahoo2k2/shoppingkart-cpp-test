PointOfSale.out : Product.o PointOfSaleTerminal.o Inventory.o PriceManager.o main.o
	g++ -o PointOfSale.out Product.o PointOfSaleTerminal.o Inventory.o PriceManager.o main.o

main.o : main.cpp PointOfSaleTerminal.hpp Product.hpp
	g++ -c main.cpp

Product.o : Product.cpp Product.hpp IProduct.hpp
	g++ -c Product.cpp

PointOfSaleTerminal.o : PointOfSaleTerminal.cpp PointOfSaleTerminal.hpp
	g++ -c PointOfSaleTerminal.cpp

Inventory.o : Inventory.cpp Inventory.hpp
	g++ -c Inventory.cpp

PriceManager.o : PriceManager.cpp PriceManager.hpp
	g++ -c PriceManager.cpp
clean: 
	rm *.o *.out 

