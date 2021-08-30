//
//  Transform.cpp
//  FourVector
//
//  Created by Hevander Da Costa on 1/1/18.
//  Copyright © 2018 Hevander Da Costa. All rights reserved.
//

#include "Transform.hpp"
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

// .cpp file contains the function bodies

// class::function_name(), means this function or constructor belongs to named class
Transform::Transform() {

}
// pass in vector by referenece to reduce memory usage
/* passinng in by reference; accesses the memory address of the passed variable using '&'
   instead of creating a a copy of the variable which would be the usual case */
// "void" indicates that the function does not return any value
void Transform::printVector(vector<double> &Vec){
    for(unsigned int i = 0; i < Vec.size(); i++){
        cout << Vec[i] << " ";
    }
}

double Transform::mass(double E, double Px, double Py, double Pz){
    double mass = 0;
    try{
        mass = sqrt((E*E) - (Px*Px) - (Py*Py) - (Pz*Pz));
        
        if(E < Px || E < Py || E < Pz ) { throw 0; }
    
    }catch(...) {
        cerr << "ERROR: Energy cannot be less that any momentum component \n";
        exit(1);
    }
    return mass;
}

double Transform::Pt(double Px, double Py) {
    double Pt = sqrt((Px*Px)+(Py*Py));
    return Pt;
}

double Transform::Phi(double Px, double Py) {
    double angle = 0;
    try {
        angle = atan(Px/Py);
        if(Py == 0){
        angle = M_PI/2;
        }
    
        if(Px == 0 && Py == 0) { throw 1; }
        
    }catch(...) {
        cerr << "ERROR: Phi undefined" << endl;
    }
    return angle;
}

double Transform::Rapidity(double E, double Pz) {
    double y = 0;
    try{
        y = 0.5 *log((E+Pz)/(E-Pz));
        
        if(y < 0) { throw 2; }
    }catch(...) {
        cerr << "ERROR: Rapidity cannot be negative" << endl;
        exit(1);
    }
    return y;
}

double Transform::Pseudorapidity(double Px, double Py, double Pz) {
    double n = 0;
    try {
        n = 0.5*log((sqrt((Px*Px)+(Py*Py)+(Pz*Pz)) + Pz)
                 /(sqrt((Px*Px)+(Py*Py)+(Pz*Pz)) - Pz));
    
        if(n < 0) { throw 3; }
    }catch(...){
            cerr << "ERROR: Pseudorapidity cannot be negative \n" << endl;
            exit(1);
    }
    return n;
}
 
