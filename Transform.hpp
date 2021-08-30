//
//  Transform.hpp
//  FourVector
//
//  Created by Hevander Da Costa on 1/1/18.
//  Copyright © 2018 Hevander Da Costa. All rights reserved.
//

#ifndef Transform_hpp
#define Transform_hpp
#include <vector>
//#include <stdio.h>
using namespace std;

// .hpp file holds function prototypes
/* Function prototypes are a declaration of a function that specifies the function's name and
  type signature (arity, data types of parameters, and return type), but omits the function body. */
/* Purpose of using .hpp file is so that function bodies aren't modified when distrubting code;
   .cpp file will be compiled into binary and the .hpp file will be distributed. */
class Transform {
    
    // Only functions within "Transform" class can use "private" variables
    /* Likewise anything else denoted private can only be used by functions and/or objects
       within the respective class*/
    private:
        double E,Px,Py,Pz;
   
    // public allows for functions and/or object can use private variables
    public:
        // constructors are functions that automatically run code present within
     Transform();
        // functions are in prototype format
        void printVector(vector<double> &Vec);
        double mass(double E, double Px,double Py, double Pz);
        double Pt(double Px, double Py);
        double Phi(double Px, double Py);
        double Rapidity(double E,double Pz);
        double Pseudorapidity(double Px, double Py, double Pz);

};


#endif /* Transform_hpp */
