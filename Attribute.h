/* 
 * File:   Attribute.h
 * Author: Cody Mulkern <Cody_Mulkern@Student.uml.edu>
 *
 * Created on October 24, 2014, 5:15 PM
 */

#ifndef ATTRIBUTE_H
#define	ATTRIBUTE_H

#include <iostream>

/**
 * Attribute Class holds two string with "name" and "value".
 */
class Attribute{
    
    
private:
    
    /**
     * String holds the name.
     */
    std::string name = "";
    
    /**
     * String holds the value.
     */
    std::string value = "";
    
public:
    
    /**
     * Default constructor
     */
    Attribute();
    
    /**
     * Copy constructor
     * @param orig
     */
    Attribute(const Attribute& orig);
    
    /**
     * Input name and value into class constructor
     * @param aName
     * @param aValue
     */
    Attribute( std::string aName, std::string aValue );
    
    /**
     * Returns string name
     * @return 
     */
    std::string getName( );
    
    /**
     * Returns string value
     * @return 
     */
    std::string getValue( );
    
    /**
     * Destructor
     */
    virtual ~Attribute();
    
};

#endif	/* ATTRIBUTE_H */