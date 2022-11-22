// To handle  
 // IPv4 address : u_int32_t (unsigned 32 bits [4 bytes] integer) 
 // Ethernet addresses : u_int8_t[6] array (unsigned 8 bits [1 byte] integer) 

//  string representations of addresses char[] = {'1', '2', '7', '.', '0', '.', '0', '.', '1', '\0' }.
//  numerical addresses stored in byte arrays  u_int8_t[] = {127, 0, 0, 1}


// 1. get these address in libnet in network byte order 
// 2. if your architecture stores integers in little-endian order (e.g., x86 and x86_64), you will get your addresses in memory with most significant bytes first (lower addresses) and least significant bytes last (higher addresses).

