/* 
 * File:   vertebrate.cpp
 * Author: Renno231
 */

#include "vertebrate.h"

Vertebrate::Vertebrate() {
    setAge(MIN_AGE);
    setWeight(MIN_WEIGHT);
}

Vertebrate::Vertebrate(int age, int weight) {
    setAge(age);
    setWeight(weight);
}

Vertebrate::~Vertebrate() {
}

int Vertebrate::getAge() {
    return age;
}

int Vertebrate::getWeight() {
    return weight;
}

void Vertebrate::setAge(int a) {
    if (a > MIN_AGE) {
        age = a;
    } else {
        age = MIN_AGE;
    }
}

void Vertebrate::setWeight(int w) {
    if (w > MIN_WEIGHT) {
        weight = w;
    } else {
        weight = MIN_WEIGHT;
    }
}
 
