/* 
 * File:   Attribute.h
 * Author: Cody Mulkern <Cody_Mulkern@Student.uml.edu>
 *
 * Created on October 24, 2014, 5:16 PM
 */

#include "Attribute.h"

/**
 * Default constructor
 */
Attribute::Attribute(){
    
}

/**
 * Copy constructor
 * @param orig
 */
Attribute::Attribute(const Attribute& orig){
    
}


/**
 * Input name and value into class constructor
 * @param aName
 * @param aValue
 */
Attribute::Attribute( std::string aName, std::string aValue ){
    name = aName;
    value = aValue;
}

/**
 * Destructor
 */
Attribute::~Attribute(){
    
}


/**
 * Returns string name
 * @return 
 */
std::string Attribute::getName( ){
    return name;
}

/**
 * Returns string value
 * @return 
 */
std::string Attribute::getValue( ){
    return value;
}