//  extract an answer from a response

#pragma once

#include "record.h"

namespace DNS {

class Answer : public Record
{
public:
    /**
     *  Constructor
     *  @param  response    the full response
     *  @param  index       the question-number
     */
    Answer(const Response &response, size_t index = 0) : 
        Record(response, ns_s_an, index) {}
        
    virtual ~Answer() = default;
};
}