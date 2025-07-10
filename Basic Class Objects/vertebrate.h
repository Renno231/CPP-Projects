/* 
 * File:   vertebrate.h
 * Author: Renno231
 */

#ifndef CLASSES_VERTEBRATE_H
#define CLASSES_VERTEBRATE_H

#include <string>
#include <iostream>

#define MIN_AGE 0
#define MIN_WEIGHT 1

class Vertebrate {

    public:
    /*
     * constructors
     * one with no params, one with params (overloading)
     */
    Vertebrate();
    Vertebrate(int, int);

    //destructor (not used in this example)
    ~Vertebrate();

    // Getters
    
    int getAge();
    int getWeight();

    // Setters

    void setAge(int);
    void setWeight(int);

protected:
    //private variables 
    int age, weight;

};

#endif //CLASSES_VERTEBRATE_H
 
