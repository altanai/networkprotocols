
 // extract the action IP address from Record object that holds an AAAA record

#pragma once

/**
 *  Dependencies
 */
#include "extractor.h"

/**
 *  Begin of namespace
 */
namespace DNS {

/**
 *  Class definition
 */
class AAAA : public Extractor
{
private:
    /**
     *  The IP address
     *  @var Ip
     */
    Ip _ip;


public:
    /**
     *  The constructor
     *  @param  response
     *  @param  record
     *  @throws std::runtime_error
     */
    AAAA(const Response &response, const Record &record) : Extractor(record, TYPE_AAAA, 16), _ip((struct in6_addr *)_record.data()) {}

    /**
     *  The constructor
     *  @param  record
     *  @throws std::runtime_error
     */
    AAAA(const Record &record) : Extractor(record, TYPE_AAAA, 16), _ip((struct in6_addr *)_record.data()) {}
    

    virtual ~AAAA() = default;
    

    const Ip &ip() const
    {
        return _ip;
    }
};

}
