// Enumeration of the supported algorithms for signatures

#pragma once


namespace DNS {
enum class Algorithm : uint8_t
{
    RSAMD5          = 1,
    DH              = 2,
    DSA             = 3,
    ECC             = 4,
    RSASHA1         = 5,
    DSA_NSEC3       = 6,
    RSASHA1_NSEC3   = 7,
    RSASHA256       = 8,
    RSASHA512       = 10,
    ECC_GOST        = 12,
    ECDSAP256SHA256 = 13,
    ECDSAP384SHA384 = 14,
    ED25519         = 15, 
    ED448           = 16, 
    INDIRECT        = 252,
    PRIVATEDNS      = 253,
    PRIVATEOID      = 254
};
    
}