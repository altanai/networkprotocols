# DHCP 

Dynamic Host Configuration Protocol(DHCP) is an application layer protocol. Based on a client-server model and based on discovery, offer, request, and ACK. 


(+) centralized management of IP addresses
(+) ease of adding new clients to a network
(+) reuse of IP addresses reducing the total number of IP addresses that are required
(+) simple reconfiguration of the IP address space on the DHCP server without needing to reconfigure each client


Port number for server is 67 and for the client is 68
DORA process has 4 DHCP messages in order to make a connection

1. DHCP discover message is broadcasted to all devices present in a network to find the DHCP server. This message is 342 or 576 bytes long.

In this the source IP address is 0.0.0.0(because PC has no IP address till now) and destination IP address is 255.255.255.255 (IP address used for broadcasting)

2. DHCP offer message is broadcasted by server ( 342 bytes)

3. DHCP request message is broadcasted by client on receiver a DHCP offer message from server.

The client will produce a  gratuitous ARP in order to find if there is any other host present in the network with same IP address. If there is no reply by other host, then there is no host with same TCP configuration in the network and the message is broadcasted to server showing the acceptance of IP address .


4. DHCP acknowledgement message – In response to the request message received, the server will make an entry with specified client ID and bind the IP address offered with lease time.

5. DHCP release
6. DHCP inform 
7. DHCP negative acknowledgement message
8. DHCP decline 