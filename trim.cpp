/* 
 * File:   trim.cpp
 * Author: Cody Mulkern <Cody_Mulkern@Student.uml.edu>
 *
 * Created on September 26, 2014, 11:02 AM
 */

#include "trim.h"

/**
 * Trim function provided in class by prof Heines.
 * Function eliminates white space in the line.
 * Question about the return. Function returns a string but the function also uses a reference
 * to the string so it seems redundant to return the same string if you are already modifying it.
 * @param str
 * @return str
 */

std::string trim( std::string& str ) {
    // cout << "Trimming |" << str << "|" << endl ;
    //erases white space infront of any characters.
    while ( str[0] == ' ' || str[0] == '\t' ) {
        str.erase( str.begin() ) ;  // must use an iterator
    }
    //erases any white space at the end.
    while ( str[str.length()-1] == ' ' || str[str.length()-1] == '\t' ) {
        str.erase( str.end()-1 ) ;  // must use an iterator
    }
    return str ;
}