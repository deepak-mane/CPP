//Listing 20.10 Array of pointers to member functions
#include <iostream>
using namespace std;

class Dog
{
 public:
     void Speak()const { cout << "Woof!\n"; }
     void Move() const { cout << "Walking to heel...\n"; }
     void Eat() const { cout << "Gobbling food...\n"; }
     void Growl() const { cout << "Grrrrr\n"; }
     void Whimper() const { cout << "Whining noises...\n"; }
     void RollOver() const { cout << "Rolling over...\n"; }
     void PlayDead() const
         { cout << "Is this the end of Little Caesar?\n"; }
};

typedef void (Dog::*PDF)()const ;

int main(int argc, char *argv[]){
	
     const int MaxFuncs = 7;
     PDF DogFunctions[MaxFuncs] =
         {   Dog::Speak,
             Dog::Move,
             Dog::Eat,
             Dog::Growl,
             Dog::Whimper,
             Dog::RollOver,
             Dog::PlayDead
         };

     Dog* pDog =0;
     int Method;
     bool fQuit = false;

     while (!fQuit)
     {
         cout << "(0)Quit (1)Speak (2)Move (3)Eat (4)Growl";
         cout << " (5)Whimper (6)Roll Over (7)Play Dead: ";
         cin >> Method;
         if (Method == 0)
         {
             fQuit = true;
             break;
         }
         else
         {
             pDog = new Dog;
             (pDog->*DogFunctions[Method-1])();
             delete pDog;
         }
     }
     return 0;
}