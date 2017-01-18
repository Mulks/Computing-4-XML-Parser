/* 
 * File:   trim.h
 * Author: Cody Mulkern <Cody_Mulkern@Student.uml.edu>
 *
 * Created on September 26, 2014, 11:02 AM
 */

#ifndef TRIM_H
#define	TRIM_H

#include <iostream>
#include <string>

/**
 * Trim function provided in class by prof Heines.
 * Function eliminates white space in the line.
 * Question about the return. Function returns a string but the function also uses a reference
 * to the string so it seems redundant to return the same string if you are already modifying it.
 * @param str
 * @return str
 */
std::string trim( std::string& str );

#endif	/* TRIM_H */