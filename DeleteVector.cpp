/* 
 * File:   DeleteVector.cpp
 * Author: Cody Mulkern <Cody_Mulkern@Student.uml.edu>
 *
 * Created on October 24, 2014, 5:16 PM
 */

#include "DeleteVector.h"

/*
 * Found on by Mike Seymour: http://stackoverflow.com/questions/18574813/having-trouble-deleting-vector-of-pointers
 * this for loop has an iterator to go through the vector and delete each element since we used new operator to create them
 *
 */



/**
 * Deletes Vector of pointers to Elements.
 * @param vector<Element*>
 *
 */
void deleteVector( std::vector<Element*> vect ){
    for (auto it = vect.begin(); it != vect.end(); ++it){
        delete *it;
    }
    //Clears the vector to make sure its completely empty.
    vect.clear();
    
}

/**
 * Deletes Vector of pointers to attributes.
 * @param vector<Attribute*>
 *
 */
void deleteVector( std::vector<Attribute*> vect ){
    for (auto it = vect.begin(); it != vect.end(); ++it){
        delete *it;
    }
    //Clears the vector to make sure its completely empty.
    vect.clear();
    
}
