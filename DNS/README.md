# DNS 
Domain Name Service (DNS) is an Internet service that maps IP addresses and fully qualified domain names (FQDN) to one another

1. Authoritative DNS Server

An authoritative name server is a server that stores DNS records (A, CNAME, MX, TXT, etc.) for domain names. These servers will only respond to queries for locally stored DNS zone files. 

2. Recursive Nameserver
A recursive name server is a DNS server that receives queries for informational purposes (do not store DNS records). When a query is received, it will search the cache memory for an address linked to the IP address. If the recursive name server has the information, then it will return a response to query sender. If it does not have the record, then the query will be sent to other recursive name servers. This continues until it reaches an authoritative DNS server that can supply the IP address.


## DNS Zones
A DNS zone is an administrative space within the Domain Name System. A zone forms one part of the DNS namespace delegated to administrators or specific entities. Each zone contains the resource records for all of its domain names.

DNS zone file is a text file with all the records for every domain within that zone. It contains TTL for Time to Live in server’s cache memory. It displays the Start of Authority (SOA) record which shows the primary authoritative name server for the DNS Zone.

## Records 

- A record (or Address Record) points a domain name to an IP address.
- CNAME (Canonical Name) Record forwards a domain name to a different domain name. This record does not contain an IP address. 
- MX (Mail Exchanger)
- TXT (Text) Record
- NS (Name Server) Record
- SOA (Start of Authority) Record
- SRV (Service) Record
- PTR (Pointer) Record


## Inbuilt Tools 

### bind
Ubuntu used BIND (Berkley Internet Naming Daemon)9 for DNS ops and dnsutils to troubleshoot.

/etc/bind/named.conf.options: global DNS options
/etc/bind/named.conf.local: for your zones
/etc/bind/named.conf.default-zones: default zones such as localhost, its reverse, and the root hints

### dig ( DNS lookup utility) :

	dig -x 127.0.0.1
	; <<>> DiG 9.11.3-1ubuntu1.17-Ubuntu <<>> -x 127.0.0.1
	;; global options: +cmd
	;; Got answer:
	;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 12904
	;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 1
	;; OPT PSEUDOSECTION:
	; EDNS: version: 0, flags:; udp: 65494
	;; QUESTION SECTION:
	;1.0.0.127.in-addr.arpa.		IN	PTR
	;; ANSWER SECTION:
	1.0.0.127.in-addr.arpa.	0	IN	PTR	localhost.
	;; Query time: 2 msec
	;; SERVER: 127.0.0.53#53(127.0.0.53)
	;; WHEN: Mon Nov 21 17:59:59 EST 2022
	;; MSG SIZE  rcvd: 74


### ping 



## References 

RFC 1035: DOMAIN NAMES - IMPLEMENTATION AND SPECIFICATION
RFC 3110: RSA/SHA-1 SIGs and RSA KEYs in the Domain Name System (DNS)
RFC 4033: DNS Security Introduction and Requirements
RFC 4034: Resource Records for the DNS Security Extensions
RFC 4035: Protocol Modifications for the DNS Security Extensions
RFC 4470: Minimally Covering NSEC Records and DNSSEC On-line Signing
RFC 4509: Use of SHA-256 in DNSSEC Delegation Signer (DS) Resource Records (RRs)
RFC 5702: Use of SHA-2 Algorithms with RSA in DNSKEY and RRSIG Resource Records for DNSSEC
RFC 5155: DNS Security (DNSSEC) Hashed Authenticated Denial of Existence
RFC 6014: Cryptographic Algorithm Identifier Allocation for DNSSEC
RFC 6840: Clarifications and Implementation Notes for DNS Security (DNSSEC)
RFC 8624: Algorithm Implementation Requirements and Usage Guidance for DNSSEC