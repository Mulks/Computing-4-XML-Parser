/* 
 * File:   ParseXML.h
 * Author: Cody Mulkern <Cody_Mulkern@Student.uml.edu>
 *
 * Created on October 3, 2014, 8:45 PM 
 */

#ifndef PARSEXML_H
#define	PARSEXML_H

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "trim.h"
#include "Element.h"
#include "Attribute.h"
#include "ParserState.h"
#include "SearchParserState.h"
#include "ParseLine.h"
#include "DeleteVector.h"

using namespace std;

/**
 * ParseXML function definition
 * This function will return either EXIT_SUCCESS or EXIT_FAILURE
 * @return 
 */
int parseXML( );

#endif	/* PARSEXML_H */