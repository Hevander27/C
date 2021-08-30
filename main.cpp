//
//  main.cpp
//  FourVector
//
//  Created by Hevander Da Costa on 1/1/18.
//  Copyright © 2018 Hevander Da Costa. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include "Transform.hpp"
#include <sstream>
#include <iomanip>
#include <cstdio>


//Descript

using namespace std;

int main(int argc, const char * argv[]) {
   
    // create object name for ifstream (class that reads in a file)
    ifstream infile;
    // create object name for ofstream (class outputs onto a file)
    ofstream outfile;
    
    
    /*  Copy number array into Input.txt file to test
        ---------------
        655 345 221 176
        393 212 343 165
        889 145  19 465
        491  67  23  89
        234  87  103 12
         77  56  32  12
         43  33  33  33
         17   8   5   0
         34   0   0   0
         19  11   0   0
         23   0  13   0
         27   0   0  19
     */
    
    // create an input file; must manually add string of numbers with first number greater than others
    infile.open("Input.txt");
    // creates output file that will have four vector transformations printed on
    outfile.open("Output.txt");
    
    // check if file is open with .is_open(); this prints out to the consoles
    if(outfile.is_open() & infile.is_open()) {
        cout << "Files are open\n" << endl;
    }else{
        cerr << "Files are not open ";
        exit (1);
    }
    
    // create double vector; needs to be assigned data type in angle brackets ie <data_type>
    // vector are arrays that expand when values are added
    vector<double> myVector;
    
    
    // create an object to use functions in Transform class
    Transform T;
        
    outfile <<left<<setw(6)<< "Mass"<<"\t"<<left<< setw(6)<< "P_t" <<"\t"
            <<left<<setw(6)<< "Phi" <<"\t"<<left<< setw(6)<<"Rapid"<< "\t"
            <<"Pseudo_Rapid"<< "\n--------------------------------------------\n" <<endl;
    
    // four vector data variables
    double E,Px,Py,Pz;
    while(infile >>E>>Px>>Py>>Pz){ // Boolean condition requires that four vector values in given order
        
        // push_back inserts a values into the vector
        myVector.push_back(E);
        myVector.push_back(Px);
        myVector.push_back(Py);
        myVector.push_back(Pz);
        
        // check the intial four vector values
        cout << "Inital input: " ;
        T.printVector(myVector);
        cout<< "\n";
        
        // to use a function of a particular class, a class object must be dotted with the class function
        // class_object.class_function()
    
        double ma = T.mass(E,Px,Py,Pz);
        double pt = T.Pt(Px,Py);
        double ph = T.Phi( Px,Py);
        double ra = T.Rapidity(E,Pz);
        double ps = T.Pseudorapidity(Px,Py,Pz);
            
        // set precision sets desired decimal precision
        // printing onto the outfile
        outfile << setprecision(4);
        outfile << left << setw(6)<< ma << "\t"<< left<<setw(6)<<pt << "\t"
                << left << setw(6)<< ph << "\t"<< left<<setw(6)<<ra << "\t"
                << ps << endl;
        
        
        // printing onto console to check functionality
        cout << setprecision(6);
        cout << "Mass: " << ma << "\n" << "P_t: "<< pt << "\n"<< "Phi: "<< ph<< "\n"
             <<"Rapidity: "<< ra << "\n" << "Pseudo_rapidity: " << ps << "\n" << endl;
        // vector is cleared after every set of (E,Px,Py,Pz) is processed in the while loop
        myVector.clear();

    }
    infile.close();
}


