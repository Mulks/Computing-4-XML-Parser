/* 
 * File:   SearchParserState.h
 * Author: Cody Mulkern <Cody_Mulkern@Student.uml.edu>
 *
 * Created on October 3, 2014, 9:33 PM
 */

#ifndef SEARCHPARSERSTATE_H
#define	SEARCHPARSERSTATE_H

#include <stdio.h>
#include <iostream>
#include <string>
#include "ParserState.h"

/**
 * Takes the current parserSTate and the currentLine and determines the new parserState
 * @param curPS
 * @param curLine
 * @return parserState
 */
ParserState searchParserState( ParserState curPS, std::string curLine );

#endif	/* SEARCHPARSERSTATE_H */