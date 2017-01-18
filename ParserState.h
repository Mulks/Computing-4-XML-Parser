/* 
 * File:   ParserState.h
 * Author: Cody Mulkern <Cody_Mulkern@Student.uml.edu>
 *
 * Created on October 3, 2014, 9:31 PM
 */

#ifndef PARSERSTATE_H
#define	PARSERSTATE_H

#include <stdio.h>
#include <iostream>
/**
 * Provided in class by professor Heines
 * the various parser states
 */
enum ParserState { UNKNOWN, STARTING_DOCUMENT, DIRECTIVE,
    ELEMENT_OPENING_TAG, ELEMENT_CONTENT, ELEMENT_NAME_AND_CONTENT,
    ELEMENT_CLOSING_TAG, SELF_CLOSING_TAG,
    STARTING_COMMENT, IN_COMMENT, ENDING_COMMENT, ONE_LINE_COMMENT,
    ERROR } ;


/**
 * This function is used during debugging to display the parser state.
 * @param ps the parser state
 */
void ShowState( ParserState ps );

#endif	/* PARSERSTATE_H */