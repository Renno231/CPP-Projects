/* 
 * File:   functions.cpp
 * Author: Renno231
 */

#include "functions.h"

void displayVertebrate(Vertebrate *myVertebrate){

    std::cout << "Vertebrate age: " << myVertebrate->getAge() << std::endl;
    std::cout << "Vertebrate weight: " << myVertebrate->getWeight() << std::endl;
    
    std::cout << std::endl;

}

void displayDog(Dog *myDog){

    std::cout << myDog->getName() << std::endl;
    std::cout << myDog->getBreed() << std::endl;
    std::cout << myDog->getAge() << " years old" << std::endl;
    std::cout << myDog->getWeight() << "lbs" << std::endl;
    myDog->Bark();
    std::cout << std::endl;

} 
