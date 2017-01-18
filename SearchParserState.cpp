/* 
 * File:   SearchParserState.h
 * Author: Cody Mulkern <Cody_Mulkern@Student.uml.edu>
 *
 * Created on October 3, 2014, 9:33 PM
 */
#include "SearchParserState.h"

/**
 * Takes the current parserSTate and the currentLine and determines the new parserState
 * @param curPS
 * @param curLine
 * @return parserState
 */
ParserState searchParserState( ParserState curPS, std::string curLine ){
    
    //Create a parserState variable
    ParserState ps;
    
    //Counter variables used in the if and elseIF statements
    int i = 0;
    
    //Searches for the '?' to check for directive
    if( curLine[i] == '<' &&
        curLine[i+1] == '?' &&
        curLine[curLine.length()-2] == '?' &&
        curLine[curLine.length()-1] == '>' ){
        
        //Assignes DIRECTIVE to the parserState
        ps = DIRECTIVE;
        
        //Used to show state for testing
        //ShowState( ps );
    }
    //Checking for the starting comment with "<!--" and no --> at the end of the line
    else if ( curLine[i] == '<' &&
              curLine[i+1] == '!' &&
              curLine[i+2] == '-' &&
              curLine[i+3] == '-' &&
              curLine[curLine.length()-1] != '>'){
        
        //Assignes STARTING_COMMENT to the parserState
        ps = STARTING_COMMENT;
        
        //Used to show state for testing
        //ShowState( ps );
    }
    //Checking for a one line comment with both "<!--" and "-->"
    else if ( curLine[i] == '<' &&
              curLine[i+1] == '!' &&
              curLine[i+2] == '-' &&
              curLine[i+3] == '-' &&
              curLine[curLine.length()-1] == '>' &&
              curLine[curLine.length()-2] == '-' &&
              curLine[curLine.length()-3] == '-' ){
        
        //Assignes ONE_LINE_COMMENT to the parserState
        ps = ONE_LINE_COMMENT;
        
        //Used to show state for testing
        //ShowState( ps );
    }
    //Checking for the end of a comment with "-->"
    else if ( curLine[curLine.length()-1] == '>' &&
              curLine[curLine.length()-2] == '-' &&
              curLine[curLine.length()-3] == '-'){
        
        //Assignes ENDING_COMMENT to the parserState
        ps = ENDING_COMMENT;
        
        //ShowState( ps );
    }
    //Checking for a comment line with no beginning or end
    else if ( (curPS == STARTING_COMMENT || curPS == IN_COMMENT ) && curPS != ENDING_COMMENT ){
        
        //Assignes IN_COMMENT to the parserState
        ps = IN_COMMENT;
        
        //ShowState( ps );
    }
    //Checking for an element with a opening tag with content inside
    else if ( curLine[i] == '<' &&
              curLine[i+1] != '/' &&
              curLine[curLine.length()-1] == '>' &&
              curLine[curLine.length()-2] != '/' &&
              curLine[curLine.find('=')] == '='){
        
        //Assignes ELEMENT_NAME_AND_CONTENT to the parserState
        ps = ELEMENT_NAME_AND_CONTENT;
        
        //Used to show state for testing
        //ShowState( ps );
    }
    //Checking for if content exists between opening tag and closing tag
    else if ( curLine[i] == '<' &&
              curLine[i+1] != '/' &&
              curLine[curLine.length()-1] == '>' &&
              curLine[curLine.length()-2] != '/' &&
              curLine.find_first_of('>') != curLine.length()-1){
        
        //Assignes ELEMENT_CONTENT to the parserState
        ps = ELEMENT_CONTENT;
        
        //Used to show state for testing
        //ShowState( ps );
    }
    //Checking for a element opening tag with that closes itself
    else if ( curLine[i] == '<' &&
             curLine[curLine.length()-2] == '/' &&
             curLine[curLine.length()-1] == '>'){
        
        //Assignes SELF_CLOSING_TAG to the parserState
        ps = SELF_CLOSING_TAG;
        
        //Used to show state for testing
        //ShowState( ps );
    }
    //Checking for an opening tag that is alone
    else if ( curLine[i] == '<' &&
              curLine[i+1] != '/' &&
              curLine[curLine.length()-1] == '>'){
        
        //Assignes ELEMENT_OPENING_TAG to the parserState
        ps = ELEMENT_OPENING_TAG;
        
        //Used to show state for testing
        //ShowState( ps );
    }
    //Checking for a closing tag that is alone
    else if ( curLine[i] == '<' &&
              curLine[i+1] == '/'){
        
        //Assignes ELEMENT_CLOSING_TAG to the parserState
        ps = ELEMENT_CLOSING_TAG;
        
        //Used to show state for testing
        //ShowState( ps );
    }
    //Catches anything not defined above
    //Will also lead to program terminating
    else{
        
        //Assignes UNKNOWN to the parserState
        ps = UNKNOWN;
        
        //Used to show state for testing
        //ShowState( ps );
    }
    
    //Return the current parserState
    return ps;
}