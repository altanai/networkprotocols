//extract a record from the "additional" section in a message.
#pragma once

#include "record.h"

namespace DNS {

class Additional : public Record
{
public:
    /**
     *  Constructor
     *  @param  message    the full message
     *  @param  index       the question-number
     */
    Additional(const Message &message, size_t index = 0) : 
        Record(message, ns_s_ar, index) {}
        
    /**
     *  Destructor
     */
    virtual ~Additional() = default;
};
}