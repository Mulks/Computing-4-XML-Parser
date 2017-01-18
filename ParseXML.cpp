/* 
 * File:   ParseXML.cpp
 * Author: Cody Mulkern <Cody_Mulkern@Student.uml.edu>
 *
 * Created on October 3, 2014, 8:45 PM 
 */


#include "ParseXML.h"


/**
 * ParseXML function definition
 * This function will return either EXIT_SUCCESS or EXIT_FAILURE
 * @return 
 */
int parseXML( ){
    
    //Vector of references to elements holding the xml tags and their line numbers
    vector<Element*> xmlTags;
    
    //Vector of references to elements used to make the xml tree
    vector<Element*> treeTags;
    
    //Root element in xmlTree
    Element rootElement;
    
    //xmlTree level
    int xmlTreeLevel = 0;
   
    //string holding the text read in from each line if the xml file.
    string line;
    
    //int holding the line number that the program is currently on in the xml file.
    int lineCount = 0;
    
    //Ifstream object opening the xml file.
    ifstream fileIn("tdwp2.xml");
    
    //Ofstream object opening a file to write to.
    ofstream fileOut("XmlToJSon.json");
    
    //Initialize the parserState and set to STARTING_DOCUMENT
    ParserState ps = STARTING_DOCUMENT;
    
    //Used to test showing the parserState.
    //ShowState( ps );
    
    /**
     * This while loop will go until it reaches the end of the xml file.
     * The getline function takes the ifstream object and the line string and will return the line of the xml file.
     */
    while( getline ( fileIn, line ) ) {
        
        //Statement to catch the parserState being an ERROR and exiting program.
        //Prints out line number before terminating to help find problem
        if( ps == ERROR ){
            
            //print out the line in the xml file that an error occurred.
            cout << "Error on line: " << lineCount << endl;
            
            //Return an exit failure because error occurred and xml is not well formed.
            return EXIT_FAILURE;
        }
        
        //Pre-increment line count because it starts at 0.
        ++lineCount;
        
        //Trim the white space from the line of xml.
        trim(line);
        
        //Used for testing to see line number of each parsing state.
        //cout << lineCount << ": ";
        
        /**
         * @param ps is the current parserState
         * @param line is the current line of the xml file
         * @return parserState
         */
        ps = searchParserState( ps, line );
        
       
        /**
         * This will parse each line looking at the parser status and decided what to do 
         * @param line is a string
         * @param xmlTags is the vector of element pointers
         * @param ps is the parserState
         * @return 
         */
        parseLine(line, xmlTags, treeTags, lineCount, ps , xmlTreeLevel);
        
        
    }
    
    /**
     * Prints out all the elements and attributes of the treeTags Vector.
     * Adds first curly bracket to start json file.
     */
    fileOut << "{" << endl;
    
    treeTags.back()->printElements( fileOut );
    
    //Delete and clear xmlTags
    deleteVector( xmlTags );
    
    //Delete and clear treeTags
    deleteVector( treeTags );
    
    //Closes the ifstream object reading the xml file.
    fileIn.close();
    
    //Closes the ofstream object writing to the json file.
    fileOut.close();
    
    return EXIT_SUCCESS;
}