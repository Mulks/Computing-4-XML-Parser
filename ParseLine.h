/* 
 * File:   ParseLine.h
 * Author: Cody Mulkern <Cody_Mulkern@Student.uml.edu>
 *
 * Created on October 3, 2014, 9:18 PM
 */

#ifndef PARSELINE_H
#define	PARSELINE_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "Element.h"
#include "ParserState.h"
#include "DeleteVector.h"

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
void parseLine( std::string line, std::vector<Element*> &xmlTags, std::vector<Element*> &treeTags, int lineNumber, ParserState &ps, int &tagLevel );

#endif	/* PARSELINE_H */