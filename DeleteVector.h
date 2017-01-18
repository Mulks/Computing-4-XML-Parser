/* 
 * File:   DeleteVector.h
 * Author: Cody Mulkern <Cody_Mulkern@Student.uml.edu>
 *
 * Created on October 24, 2014, 5:16 PM
 */

#ifndef DELETEVECTOR_H
#define	DELETEVECTOR_H

#include <iostream>
#include <vector>
#include "Element.h"
#include "Attribute.h"

/*
 * Found on by Mike Seymour: http://stackoverflow.com/questions/18574813/having-trouble-deleting-vector-of-pointers
 * 
 * This function will traverse through the vectors and delete all elements since we used new to allocate memeory for them.
 * Then it will clear the vectors completely.
 */


/**
 * Deletes Vector of pointers to Elements.
 * @param vector<Element*>
 *
 */
void deleteVector( std::vector<Element*> vect );

/**
 * Deletes Vector of pointers to Attributes.
 * @param vector<Element*>
 *
 */
void deleteVector( std::vector<Attribute*> vect );

#endif	/* DELETEVECTOR_H */

