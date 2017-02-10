// Listing 21.5 - Printing values in DEBUG mode
#include <iostream>
using namespace std;
#define DEBUG

#ifndef DEBUG
#define PRINT(x)
#else
#define PRINT(x) \
     cout << #x << ":\t" << x << endl;
#endif

int main(int argc, char *argv[]){
	
     int x = 5;
     long y = 73898l;
     PRINT(x);
     for (int i = 0; i < x; i++)
     {
         PRINT(i);
     }

     PRINT (y);
     PRINT("Hi.");
     int *px = &x;
     PRINT(px);
     PRINT (*px);
     return 0;
 }