/* 
 * File:   ParseLine.cpp
 * Author: Cody Mulkern <Cody_Mulkern@Student.uml.edu>
 *
 * Created on October 3, 2014, 9:18 PM
 */
#include "ParseLine.h"

/**
 * Takes in line, xmlTags "Vector of Elements*", lineNumber, and the parserState.
 * Uses a switch statement based off the parserState to decide what to do.
 * Pushing and popping of the vector happens inside switch statement which is why i passed vector as a reference.
 * 
 * Most commented out lines are used for testing only and are turned off intentionally.
 * 
 * @param line
 * @param xmlTags
 * @param treeTags
 * @param lineNumber
 * @param ps
 * @param tagLevel
 */
void parseLine( std::string line, std::vector<Element*> &xmlTags , std::vector<Element*> &treeTags, int lineNumber , ParserState &ps, int &tagLevel ){
   
    //String to hold the xmlTag
    std::string xmlTag;
    
    //String to hold the content for the xmlTag
    std::string xmlContent;
    
    //Vector to hold attributes.
    std::vector<Attribute*> attributes;
    
    /**
     * Switch statement takes parserState as a parameter
     * Decides what to do based off the parserState passed in
     */
    switch ( ps ) {
        //If case is unknown set the parserState to Error
        //This will terminate the program
        case UNKNOWN :{
            ps = ERROR;
        }
            break;
        //Starting document doesn't do anything
        case STARTING_DOCUMENT :
            break;
        //Directive prints out the whole line
        case DIRECTIVE:{
            
            xmlContent = line;
            
            //Erases the "<?" at beginning and "?>" at the end
            xmlContent.erase( xmlContent.begin());
            xmlContent.erase( xmlContent.begin());
            xmlContent.erase( xmlContent.end()-1);
            xmlContent.erase( xmlContent.end()-1);
            
            //Prints out the lineNumber and what on the line
            //std::cout << lineNumber << ":  " << line << std::endl;
            
            //Prints out the Directive inside the line
            //std::cout << "*** " << "Directive = " << xmlContent << std::endl;
        }
            break;
        /**
         * ELEMENT_OPENING_TAG
         * Extracts the opening tag
         * Pushes xmlTag, lineNumber, xmlContent, and the tagLevel into the treeTags vector.
         * Increments the tagLevel by 1.
         */
        case ELEMENT_OPENING_TAG :{
            //Extract the opening tag by looking for closing bracket
            for( int i = 0; line[i] != '>'; i++){
                xmlTag+= line[i];
            }
            //Erases the '<' at the beginning of the tag
            xmlTag.erase( xmlTag.begin());
            
            //Push back a child in xmlTree
            treeTags.back()->pushBackChild( new Element( xmlTag, lineNumber, xmlContent, tagLevel ), tagLevel );
            
            //Prints out the lineNumber and xmlTag
            //std::cout << lineNumber << ":  " << line << std::endl;
            //std::cout << "*** " << "  Element Opened = " << xmlTag << std::endl;
            
            //Inserts the xmlTag into the vector at the end
            xmlTags.insert( xmlTags.end(), new Element( xmlTag, lineNumber ));
            
            //std::cout <<"Tree Level: " << tagLevel << " Line number: " << lineNumber << std::endl;
            
            //Iterates through the vector and prints out all elements
            /*std::cout << "Vector (Stack) now contains: ";
            for ( int i = 0; i < xmlTags.size(); i++ ){
                std::cout << xmlTags[i]->getXmlTag() << " ";
            }*/
            //Add new line
            //std::cout << "\n";
            
            //Increment treeLevel
            tagLevel++;
            
        }
            break;
        /**
         * ELEMENT_CONTENT
         * Extracts xmlTag and xmlContent
         * Prints out line,lineNumber
         * Pushes xmlTag, lineNumber, xmlContent, and the tagLevel into the treeTags vector.
         * Does not change the tagLevel
         */
        case ELEMENT_CONTENT :{
            
            //New string same as line that can be manipulated.
            std::string newLine = line;
            
            
            //Extract the xmlTag.
            for( int i = 0; line[i] != '>'; i++){
                xmlTag+= line[i];
            }
            
            //Erases opening tag.
            while( newLine[0] != '>' ){
                newLine.erase( newLine.begin() );
            }
            //Erases closing tag.
            while( newLine[newLine.length()-1] != '<' ){
                newLine.erase( newLine.end()-1 );
            }
            //Erases the '<' from end of content.
            newLine.erase( newLine.end()-1 );
            
            //Extract the xmlContent
            for( int i = 0; i < newLine.length(); i++){
                xmlContent+= newLine[i];
            }
            
            //Erases the '<' at the beginning of both xmlTag and xmlContent
            xmlTag.erase( xmlTag.begin());
            xmlContent.erase( xmlContent.begin());
            
            //Push back a child of xmlTree
            treeTags.back()->pushBackChild( new Element( xmlTag, lineNumber, xmlContent, tagLevel), tagLevel );
            
            
            //std::cout <<"Tree Level: " << tagLevel << " Line number: " << lineNumber << std::endl;
           
            //Prints lineNumber and the line
            //Prints element name and content
            //std::cout << lineNumber << ":  " << line << std::endl;
            //std::cout << "*** " << "  Complete element found:" << std::endl;
            //std::cout << "*** " << "  Element Name = " << xmlTag << std::endl;
            //std::cout << "*** " << "  Element Content = " << xmlContent << std::endl;
            
            //Print vector unchanged
            //std::cout << "Vector (Stack) unchanged." << std::endl;
        }
            break;
        /**
         * ELEMENT_NAME_AND_CONTENT
         * Extract xmlTag
         * Extract xmlContent
         * Pushes xmlTag, lineNumber, xmlContent,tagLevel, and the attributes into the treeTags vector.
         * Increments the tagLevel by 1
         */
        case ELEMENT_NAME_AND_CONTENT :{
        
            //Counter used for the while loops    
            int i = 0;
            
            
            //newLine string to manipulate.
            std::string newLine = line;
            std::string attName;
            std::string attContent;
            
            //Extract the xmlTag
            while( line[i] != ' ' ){
                xmlTag+= line[i];
                i++;
            }
            
            //Extract the attribute
            while( newLine[0] != ' ' ){
                newLine.erase( newLine.begin() );
            }
            
            //Get Attribute name
            //set i back to 0 to use as counter again.
            i = 0;
            
            while( newLine[i] != '=' ){
                attName+= newLine[i];
                i++;
            }
            //Get attribute content
            while( newLine[i] != newLine[newLine.length()-1] ){
                attContent+= newLine[i];
                i++;
            }
            
            //Erase the '<' at the beginning of the xmlTag
            xmlTag.erase( xmlTag.begin());
            attName.erase( attName.begin());
            attContent.erase( attContent.begin());
            
            attributes.push_back( new Attribute( attName, attContent));
            
            if( tagLevel != 0 ){
                //Push back child of xmlTree
                treeTags.back()->pushBackChild( new Element( xmlTag, lineNumber, xmlContent, tagLevel, attributes), tagLevel );
            }
            else{
                treeTags.push_back( new Element( xmlTag, lineNumber, xmlContent, tagLevel, attributes));
            }
            
            //std::cout <<"Tree Level: " << tagLevel << " Line number: " << lineNumber << std::endl;
            
            //Increment treeLevel
            tagLevel++;
            
            //Print out the lineNumber and line
            //Print out the xmlTag found
            //std::cout << lineNumber << ":  " << line << std::endl;
            //std::cout << "*** " << "  Element Opened = " << xmlTag << std::endl;
            //std::cout << "*** " << "  Attribute = " << newLine << std::endl;
            //std::cout << "attname: " << attName << " attContent: " << attContent << std::endl;
            
            //Insert the xmlTag, xmlContent, and lineNumber into back of vector
            xmlTags.insert( xmlTags.end(), new Element( xmlTag, lineNumber, xmlContent ));
            
            //Print out current vector that has grown
            //Test to see vector size.
            /*
            std::cout << "Vector (Stack) now contains: ";
            for ( int i = 0; i < xmlTags.size(); i++ ){
                std::cout << xmlTags[i]->getXmlTag() << " ";
            }
            */
            //Add new line
            //std::cout << "\n";
            
            
        }
            break;
        /**
         * ELEMENT_CLOSING_TAG
         * Extract the closing xmlTag
         * Erase the "</"
         * Compare to back of vector if its the same pop back of vector.
         * If it does not match the there is an ERROR and set the parserState to ERROR and terminate program.
         * Decrement tagLevel by 1.
         */
        case ELEMENT_CLOSING_TAG :{
            
            
            
            //Extract the closing xmlTag
            for( int i = 0; line[i] != '>'; i++){
                xmlTag+= line[i];
            }
            
            //Erase the "</" from beginning of xmlTag
            xmlTag.erase( xmlTag.begin());
            xmlTag.erase( xmlTag.begin());
            
            //std::cout <<"Tree Level: " << tagLevel << " Line number: " << lineNumber << std::endl;
            
            //If the closing tag and the back of the vector are the same pop_back of vector
            if( xmlTag == xmlTags[xmlTags.size()-1]->getXmlTag() ){
                xmlTags.pop_back();
                
                //Print out current lineNumber and line
                //Print out which xmlTag is closed
                //std::cout << lineNumber << ":  " << line << std::endl;
                //std::cout << "*** " << "  Element Closed = " << xmlTag << std::endl;
                
                //Print updated Vector
                //std::cout << "Vector (Stack) now contains: ";
                /*for ( int i = 0; i < xmlTags.size(); i++ ){
                    
                    std::cout << xmlTags[i]->getXmlTag() << " ";
                }*/
                //If vector is empty print "empty" next to status
                /*if( xmlTags.empty() ){
                    std::cout << "Empty";
                }*/
            }
            //Set parserState to ERROR and terminate but try and be helpful with reason for the error
            else{
                //Set parserState to ERROR
                ps = ERROR;
                
                //Print error message
                std::cout << "Error: Non-matching closing tag" << std::endl;
                
                //Terminate function
                return;
            }
            //Add new line
            //std::cout << "\n";
            
            //Closing tag so decrement TreeLevel-1
            tagLevel--;
            
        }
            break;
        /**
         * SELF_CLOSING_TAG
         * Extract the xmlTag
         * Extract the xmlContent
         * Erase '<' at beginning of xmlTag
         * Pushes xmlTag, lineNumber, xmlContent,tagLevel, and the attributes into the treeTags vector.
         */
        case SELF_CLOSING_TAG :{
            
            //Counter used in while loops
            int i = 0;
            
            //Self closing tag increment pushback then decrement
            //tagLevel++;
            
            //newLine to get attributes
            std::string newLine;
            
            //string to hold attribute name
            std::string attName;
            
            //string to hold attribute content
            std::string attContent;
            
            //Extract the xmlTag
            while( line[i] != ' ' ){
                xmlTag+= line[i];
                i++;
            }
            
            //Extract the xmlContent
            while( line[i] != '/' ){
                newLine+= line[i];
                i++;
            }
            
            //Get Attribute name
            //set i back to 0 to use as counter again.
            i = 0;
            
            while( newLine[i] != '=' ){
                attName+= newLine[i];
                i++;
            }
            //Get attribute content
            while( newLine[i] ){
                attContent+= newLine[i];
                i++;
            }
            
            //Erase the '<' at beginning of xmlTag
            xmlTag.erase( xmlTag.begin());
            attName.erase( attName.begin());
            attContent.erase( attContent.begin());
            
            attributes.push_back( new Attribute( attName, attContent));
            
            //Push back child of xmTree
            treeTags.back()->pushBackChild( new Element( xmlTag, lineNumber, xmlContent, tagLevel, attributes), tagLevel );
            
            
            //std::cout <<"Tree Level: " << tagLevel << " Line number: " << lineNumber << std::endl;
            
            //Print lineNumber and line
            //Print Self closing found
            //Print the xmltag and the xmlContent
            //std::cout << lineNumber << ":  " << line << std::endl;
            //std::cout << "*** " << "Self-closing element found:" << std::endl;
            //std::cout << "*** " << "  Element Name = " << xmlTag << std::endl;
            //std::cout << "*** " << "  Element Content = " << xmlContent << std::endl;
            //std::cout << "*** " << "  Attribute = " << newLine << std::endl;
            //std::cout << "attname: " << attName << " attContent: " << attContent << std::endl;
            
            //Print vector unchanged
            //std::cout << "Vector (Stack) unchanged."  << std::endl;
            
        }
            break;
        /**
         * STARTING_COMMENT
         * Prints out the lineNumber and line
         * Prints starting comment
         */
        case STARTING_COMMENT :{
            
            //Prints out the lineNumber and line
            //Prints starting comment
            //std::cout << lineNumber << ":  " << line << std::endl;
            //std::cout << "*** " << "Starting Comment" << std::endl;
        }
            break;
        /**
         * IN_COMMENT
         * Prints out lineNumber and line
         * Prints comment Line
         */
        case IN_COMMENT :{
            
            //Prints out lineNumber and line
            //Prints comment Line
            //std::cout << lineNumber << ":  " << line << std::endl;
            //std::cout << "*** " << "Comment Line" << std::endl;
        }
            break;
        /**
         * ENDING_COMMENT
         * Prints lineNumber and line
         * Prints ending comment
         */
        case ENDING_COMMENT :{
            
            //Prints lineNumber and line
            //Prints ending comment
            //std::cout << lineNumber << ":  " << line << std::endl;
            //std::cout << "*** " << "Ending comment" << std::endl;
        }
            break;
        /**
         * ONE_LINE_COMMENT
         * Prints lineNumber and line
         * Prints one line comment 
         */
        case ONE_LINE_COMMENT :{
            
            //Prints lineNumber and line
            //Prints one line comment
            //std::cout << lineNumber << ":  " << line << std::endl;
            //std::cout << "*** " << "One Line Comment" << std::endl;
        }
            break;
        //Not used wont ever be reached
        case ERROR :
            break;
        default :
            break;
        }
    
    //Adds some space to make output more readable
    //std::cout << "\n";
    
}