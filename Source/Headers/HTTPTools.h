/*
  ==============================================================================

    HTTPTools.h
    Created: 10 Aug 2016 2:30:44pm
    Author:  czy_jerry

  ==============================================================================
*/

#ifndef HTTPTOOLS_H_INCLUDED
#define HTTPTOOLS_H_INCLUDED

#include "JuceHeader.h"

class HTTPTools: public URL
{
public:
	HTTPTools();
	~HTTPTools();

	bool SetLoginParams(StringArray);

private:
	
};


#endif  // HTTPTOOLS_H_INCLUDED
