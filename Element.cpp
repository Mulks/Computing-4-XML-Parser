/* 
 * File:   Element.cpp
 * Author: Cody Mulkern <Cody_Mulkern@Student.uml.edu>
 * 
 * Created on September 26, 2014, 10:57 AM
 * Updated on October 3, 2014
 */

#include "Element.h"



/**
 * Default constructor
 */
Element::Element() {
}

/**
 * Copy constructor
 * @param orig
 */
Element::Element(const Element& orig) {
}

/**
 * Constructor used to initialize the xmlTag and lineNumber.
 * @param tag
 * @param lNum
 */
Element::Element( std::string tag, int lNum){
    setXmlTag( tag );
    setLineNumber( lNum );
    
}

/**
 * Constructor used to initialize the xmlTag, lineNumber, and xmlContent.
 * @param tag
 * @param lNum
 * @param content
 */
Element::Element( std::string tag, int lNum, std::string content ){
    setXmlTag( tag );
    setLineNumber( lNum );
    setElementContent( content );
}

/**
 * Constructor used to initialize the xmlTag, lineNumber, xmlContent, and xmlTreeLevel.
 * @param tag
 * @param lNum
 * @param content
 * @param xmlLevel
 */
Element::Element( std::string tag, int lNum, std::string content , int xmlLevel){
    setXmlTag( tag );
    setLineNumber( lNum );
    setElementContent( content );
    xmlTreeLevel = xmlLevel;
}

/**
 * Constructor used to initialize the xmlTag, lineNumber, xmlContent, xmlTreeLevel, and attributes.
 * @param tag
 * @param lNum
 * @param content
 * @param xmlLevel
 * @param nAttributes
 */
Element::Element( std::string tag, int lNum, std::string content , int xmlLevel, std::vector<Attribute*> nAttributes ){
    setXmlTag( tag );
    setLineNumber( lNum );
    setElementContent( content );
    xmlTreeLevel = xmlLevel;
    attributes = nAttributes;
}

/**
 * Destructor
 */
Element::~Element() {
}

/**
 * Returns the xml tag stored in the object.
 * @return string
 */
std::string Element::getXmlTag(){
    return xmlTag;
}

/**
 * Takes a string and sets it as the xmlTag in the object.
 * @param xTag
 */
void Element::setXmlTag( std::string xTag ){
    xmlTag = xTag;
}

/**
 * Returns the line number of the object.
 * @return int
 */
int Element::getLineNumber(){
    return lineNumber;
}

/**
 * Takes a integer and sets it as the line number in the object.
 * @param lNum
 */
void Element::setLineNumber( int lNum ){
    lineNumber = lNum;
}

/**
 * Returns the content inside the xml tag.
 * @return string
 */
std::string Element::getElementContent(){
    return elementContent;
}

/**
 * Takes in a string and sets it as the xmlContent in the object.
 * @param content
 */
void Element::setElementContent( std::string content ){
    elementContent = content;
}

/**
 * Returns the xmlTreeLevel.
 * @return int
 */
int Element::getXmlTreeLevel(){
    return xmlTreeLevel;
}


/**
 * Takes in a int and sets it has the xmlTreeLevel.
 * @param xmlLevel
 */
void Element::setXmlTreeLevel( int xmlLevel ){
    xmlTreeLevel = xmlLevel;
}

/**
 * Push back a child Element*
 * @param element
 */
void Element::pushBackChild( Element* element ){
    child.push_back( element );
}

/**
 * Recursively pushes back a child element to the xmlTreeLevel given.
 * @param element
 * @param xmlTreeLevel
 */
void Element::pushBackChild( Element* element, int xmlTreeLevel ){
    if( xmlTreeLevel == 1 ){
        child.push_back(element);
    }
    else{
        child.back()->pushBackChild( element, xmlTreeLevel - 1 );
    }
}

/**
 * Push back a child Attribute*
 * @param attribute
 */
void Element::pushAttributes( Attribute* attribute ){
    attributes.push_back( attribute );
}

/**
 * Returns the child vector.
 * @return vector<Element*>
 */
std::vector<Element*> Element::getChildElement(){
    
    return child;
}

/**
 * Recursively traverses the tree and prints out elements and their children.
 */
void Element::printElements( ostream& fileOut ){
    
    //Makes the stars to show which level the element is on.
    /* Unused
    for( int i = 0; i < xmlTreeLevel; i++ ){
        //std::cout << "* ";
    }*/
    
    //Spaces for json
    for( int i = 0; i < xmlTreeLevel + 2; i++ ){
        fileOut << " ";
    }
    
    
    //Checks to see if there is no content and if not then "no content".
    if( elementContent == "" ){
        //std::cout << "Element \"" << xmlTag
        //<<  "\" was found at line " << lineNumber
        //<< " with no content , " << attributes.size() << " attributes, and " << child.size() << " children " << std::endl;
        
        //Prints out the xml tag in json format.
        fileOut << "\"" << xmlTag << "\" : {" << endl;
        
        
        //If attributes print them.
        if( !attributes.empty()){
            printAttributes( fileOut );
            fileOut << "," << endl;
        }
    }
    //If there is content print it out
    else{
        //std::cout << "Element \"" << xmlTag
        //<<  "\" was found at line " << lineNumber
        //<< " with \"" << elementContent <<  "\", " << attributes.size() << " attributes, and " << child.size() << " children " << std::endl;
        
        //Prints out the xml tag and content in json format.
        fileOut << "\"" << xmlTag << "\" : \"" << elementContent << "\" ," << endl;
        
        
        //If attributes print them.
        if( !attributes.empty()){
            printAttributes( fileOut );
            fileOut << "," << endl;
        }
    }
    
    //Check to see if child vector is empty and if not then print it out
    if( !child.empty()){
        
        for( int i = 0; i < child.size(); i++ ){
            
            child[i]->printElements( fileOut );
        }
    }
    else{
        //Spaces for json
        //fileOut << endl;
        for( int i = 0; i < xmlTreeLevel + 2; i++ ){
            //fileOut << "TreeLevel = " << xmlTreeLevel;
            fileOut << " ";
            
        }
        
        //Adds end curly bracket and comma for next line
        fileOut << "} ," << endl;
        
        
        
    }
    
}

/**
 * Prints the elements Attributes.
 */
void Element::printAttributes( ostream& fileOut ){
    //Check to see if attribute vector is empty and if not then print it out
    if( !attributes.empty()){
        
        //Makes the stars to show which level the attributes are on is on.
        //Adds 1 to show attribute under element it is part of
        for( int i = 0; i < xmlTreeLevel + 3; i++ ){
            //std::cout << "= ";
            fileOut << " ";
        }
        
        fileOut << "\"" << attributes.back()->getName() << "\" : " << attributes.back()->getValue();
        //std::cout << "Attribute: " << attributes.back()->getName() << " = " << attributes.back()->getValue() << std::endl;
    
    }
}