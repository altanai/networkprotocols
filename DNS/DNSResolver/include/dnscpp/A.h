// extract the action IP address from Record object that holds an A record

#pragma once

/**
 *  Dependencies
 */
#include "extractor.h"
#include "ip.h"

namespace DNS {

class A : public Extractor
{
private:
    Ip _ip;

public:
    /**
     *  The constructor
     *  @param  response
     *  @param  record
     *  @throws std::runtime_error
     */
    A(const Response &response, const Record &record) : Extractor(record, TYPE_A, 4), _ip((struct in_addr *)_record.data()) {}

    /**
     *  The constructor
     *  @param  record
     *  @throws std::runtime_error
     */
    A(const Record &record) : Extractor(record, TYPE_A, 4), _ip((struct in_addr *)_record.data()) {}
    
    virtual ~A() = default;
    
    const Ip &ip() const
    {
        return _ip;
    }
};
    
}