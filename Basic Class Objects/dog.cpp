/* 
 * File:   dog.cpp
 * Author: Renno231
 */

#include "dog.h"

Dog::Dog() {
    setName("Dog");
    setBreed("Mutt");
    setAge(MIN_AGE);
    setWeight(MIN_WEIGHT);
}

Dog::Dog(std::string name, std::string breed, int age, int weight) {
    setName(name);
    setBreed(breed);
    setAge(age);
    setWeight(weight);
}

Dog::~Dog() {
}

std::string Dog::getName() {
    return name;
}

std::string Dog::getBreed() {
    return breed;
}

void Dog::Bark() {
    std::cout << name << ": Bark!" << std::endl;
}

void Dog::setName(std::string n) {
    name = n;
}

void Dog::setBreed(std::string b) {
    breed = b;
}
 
