# Libnet

libnet provides a portable framework for low-level network packet writing and handling.
This lib provides portable packet creation interfaces at the IP layer and link layer.

Traceroute and ping use libnet and libpcap

	sudo apt-get install libnet1

	gcc -ggdb -Wall `libnet-config --defines libnet-config --libs` example.c -o example

## packages in ubuntu 

libnet1: library for the construction and handling of network packets
libnet1-dbg: debugging symbols for libnet
libnet1-dev: development files for libnet
libnet1-doc: developers documentation files for libnet

## Libnet functions

	libnet_t * libnet_init (int injection_type, char *device, char *err_buf)

IPv4 address to string, string to IPv4 address and string to Ethernet address are:

	char* libnet_addr2name4 (u_int32_t in, u_int8_t use_name) 
	u_int32_t libnet_name2addr4 (libnet_t *l, char *host_name, u_int8_t use_name) 
	u_int8_t* libnet_hex_aton (int8_t * s, int * len)

Get Ip and MAc address form libnet 

	u_int32_t libnet_get_ipaddr4 (libnet_t *l)
	libnet_ether_addr * libnet_get_hwaddr (libnet_t *l)

## Tests 

Addr 

	 gcc addr.c  -lnet

Get own Ip addr 

	> gcc get_own_addr.c -lnet
	> sudo ./a.out 

	IP address: 192.168.111.146
	MAC address: 00:0C:29:3B:D5:7E
	osboxes@osboxes:~/networkprotocols

Ping.c :  Internet Control Message Protocol (ICMP), 
Build and sent an ICMP echo request to an address read from stdin.


	libnet_ptag_t libnet_build_icmpv4_echo (u_int8_t type,
	    u_int8_t code, u_int16_t sum, u_int16_t id,
	    u_int16_t seq, u_int8_t * payload, u_int32_t payload_s,
	    libnet_t * l, libnet_ptag_t ptag)

	libnet_ptag_t libnet_autobuild_ipv4 (u_int16_t len,
	    u_int8_t prot, u_int32_t dst, libnet_t *l)
	


arp.c :  Address Resolution Protocol (ARP) request for the IP address read from stdin

	libnet_ptag_t libnet_autobuild_arp (u_int16_t op,
	    u_int8_t * sha, u_int8_t * spa, u_int8_t * tha,
	    u_int8_t * tpa, libnet_t * l)

	libnet_ptag_t libnet_autobuild_ethernet (u_int8_t * dst,
	    u_int16_t type, libnet_t * l)



## Ref : 

- https://github.com/libnet/libnet
- https://codedocs.xyz/libnet/libnet/
- https://repolinux.wordpress.com/2011/09/18/libnet-1-1-tutorial
- https://launchpad.net/ubuntu/+source/libnet
