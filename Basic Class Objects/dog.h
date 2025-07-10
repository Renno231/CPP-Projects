/* 
 * File:   dog.h
 * Author: Renno231
 */

#ifndef CLASSES_DOG_H
#define CLASSES_DOG_H

#include "vertebrate.h"
#include <string>
#include <iostream>

class Dog : public Vertebrate {
public:
    Dog();
    Dog(std::string, std::string, int, int); //name, breed, age, weight
    ~Dog();

    // Getters
    
    std::string getName();
    std::string getBreed();
    void Bark();

    // Setters
    void setName(std::string);
    void setBreed(std::string);

private:
    //private variables that define a Dog (from a Vertebrate)
    std::string name;
    std::string breed;

};

#endif //CLASSES_DOG_H 
