CPP_DIR = ../..
TEST_DIR = ../../../cppunit-1.12.1/include

CPPUnit.out : PriceManager.o PriceManagerTest.o
	g++ -o CPPUnit.out PriceManager.o PriceManagerTest.o /usr/local/lib/libcppunit.a

PriceManager.o : $(CPP_DIR)/PriceManager.cpp $(CPP_DIR)/PriceManager.hpp
	g++ -c $(CPP_DIR)/PriceManager.cpp

PriceManagerTest.o : PriceManagerTest.cpp $(CPP_DIR)/PriceManager.hpp
	g++ -c PriceManagerTest.cpp -I$(TEST_DIR)

clean: 
	rm *.o *.out 

