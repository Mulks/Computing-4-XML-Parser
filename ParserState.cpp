/* 
 * File:   ParserState.cpp
 * Author: Cody Mulkern <Cody_Mulkern@Student.uml.edu>
 *
 * Created on October 3, 2014, 9:31 PM
 */
#include "ParserState.h"
/**
 * This function is used during debugging to display the parser state.
 * Displays the current parserState
 * @param ps the parser state
 */
void ShowState( ParserState ps ) {
    std::cout << "ParserState = " ;
    switch ( ps ) {
        case UNKNOWN : std::cout << "UNKNOWN" ; break ;
        case STARTING_DOCUMENT : std::cout << "STARTING_DOCUMENT" ; break ;
        case DIRECTIVE : std::cout << "DIRECTIVE" ; break ;
        case ELEMENT_OPENING_TAG : std::cout << "ELEMENT_OPENING_TAG" ; break ;
        case ELEMENT_CONTENT : std::cout << "ELEMENT_CONTENT" ; break ;
        case ELEMENT_NAME_AND_CONTENT : std::cout << "ELEMENT_NAME_AND_CONTENT" ; break ;
        case ELEMENT_CLOSING_TAG : std::cout << "ELEMENT_CLOSING_TAG" ; break ;
        case SELF_CLOSING_TAG : std::cout << "SELF_CLOSING_TAG" ; break ;
        case STARTING_COMMENT : std::cout << "STARTING_COMMENT" ; break ;
        case IN_COMMENT : std::cout << "IN_COMMENT" ; break ;
        case ENDING_COMMENT : std::cout << "ENDING_COMMENT" ; break ;
        case ONE_LINE_COMMENT : std::cout << "ONE_LINE_COMMENT" ; break ;
        case ERROR : std::cout << "ERROR" ; break ;
        default : std::cout << "UNKNOWN" ; break ;
        }
    //Ends the line after printing out the parserState
    std::cout << std::endl ;
}