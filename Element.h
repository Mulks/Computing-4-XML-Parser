/* 
 * File:   Element.h
 * Author: Cody Mulkern <Cody_Mulkern@Student.uml.edu>
 *
 * Created on September 26, 2014, 10:57 AM
 */

#ifndef ELEMENT_H
#define	ELEMENT_H

#include <iostream>
#include <string>
#include <vector>
#include "Attribute.h"

using namespace std;

class Element{
    
    
private:
    int lineNumber;
    int xmlTreeLevel;
    std::string xmlTag = "";
    std::string elementContent = "";
    std::vector<Element*> child;
    std::vector<Attribute*> attributes;
    
    
public:
    
    
    
    /**
     * Default constructor
    */
    Element();
    
    /**
     * Copy constructor
     * @param orig
     */
    Element(const Element& orig);
    
    /**
     * Constructor used to initialize the xmlTag and lineNumber.
     * @param tag
     * @param lNum
     */
    Element( std::string tag, int lNum);
    
    /**
     * Constructor used to initialize the xmlTag, lineNumber, and xmlContent.
     * @param tag
     * @param lNum
     * @param content
     */
    Element( std::string tag, int lNum, std::string content );
    
    /**
     * Constructor used to initialize the xmlTag, lineNumber, xmlContent, and xmlTreeLevel.
     * @param tag
     * @param lNum
     * @param content
     * @param xmlLevel
     */
    Element( std::string tag, int lNum, std::string content , int xmlLevel);
    
    /**
     * Constructor used to initialize the xmlTag, lineNumber, xmlContent, xmlTreeLevel, and attributes.
     * @param tag
     * @param lNum
     * @param content
     * @param xmlLevel
     * @param nAttributes
     */
    Element( std::string tag, int lNum, std::string content , int xmlLevel, std::vector<Attribute*> nAttributes );
    
    /**
     * Destructor
     */
    virtual ~Element();
    
    /**
     * Returns the xml tag stored in the object.
     * @return string
     */
    std::string getXmlTag();
    
    /**
     * Takes a string and sets it as the xmlTag in the object.
     * @param xTag
     */
    void setXmlTag( std::string xTag );
    
    /**
     * Returns the line number of the object.
     * @return int
     */
    int getLineNumber();
    
    /**
     * Takes a integer and sets it as the line number in the object.
     * @param lNum
     */
    void setLineNumber( int lNum );
    
    /**
     * Returns the content inside the xml tag.
     * @return 
     */
    
    /**
     * Takes in a string and sets it as the xmlContent in the object.
     * @return string
     */
    std::string getElementContent();
    
    /**
     * Takes in a string and sets it as the xmlContent in the object.
     * @param content
     */
    void setElementContent( std::string content );
    
    /**
     * Returns the xmlTreeLevel.
     * @return int
     */
    int getXmlTreeLevel();
    
    /**
     * Takes in a int and sets it has the xmlTreeLevel.
     * @param xmlLevel
     */
    void setXmlTreeLevel( int xmlLevel );
    
    /**
     * Returns the child vector.
     * @return vector<Element*>
     */
    std::vector<Element*> getChildElement();
    
    /**
     * Push back a child Element*
     * @param element
     */
    void pushBackChild( Element* element );
    
    /**
     * Recursively pushes back a child element to the xmlTreeLevel given.
     * @param element
     * @param xmlTreeLevel
     */
    void pushBackChild( Element* element, int xmlTreeLevel );
    
    /**
     * Push back a child Attribute*
     * @param attribute
     */
    void pushAttributes( Attribute* attribute );
    
    /**
     * Recursively traverses the tree and prints out elements and their children.
     */
    void printElements( std::ostream& fileOut );
    
    /**
     * Prints the elements Attributes.
     */
    void printAttributes( ostream& fileOut );
};

#endif	/* ELEMENT_H */