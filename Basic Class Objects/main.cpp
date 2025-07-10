/* 
 * File:   main.cpp
 * Author: Renno231
 */

#include "main.h"

int main(int argc, char** argv) {
    //creates a vertebrate object with no parameters
    Vertebrate myVertebrate1;
    //creates a vertebrate object with width and height 5x4
    Vertebrate myVertebrate2(5, 20);

    //creates a Dog object with no parameters
    Dog myDog1;
    //creates a Dog object with name, breed, age, and weight
    Dog myDog2("Buddy", "German Shepherd", 6, 45);

    //examples of passing objects by reference
    displayVertebrate(&myVertebrate1);
    displayVertebrate(&myVertebrate2);

    displayDog(&myDog1);
    displayDog(&myDog2);

    return 0;
}
 
