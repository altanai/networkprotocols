typedef struct
{
    unsigned short id;         // identification number
    unsigned char rd : 1;      // recursion desired
    unsigned char tc : 1;      // truncated message
    unsigned char aa : 1;      // authoritive answer
    unsigned char opcode : 4;  // purpose of message
    unsigned char qr : 1;      // query/response flag
    unsigned char rcode : 4;   // response code
    unsigned char cd : 1;      // checking disabled
    unsigned char ad : 1;      // authenticated data
    unsigned char z : 1;       // its z! reserved
    unsigned char ra : 1;      // recursion available
    unsigned short q_count;    // number of question entries
    unsigned short ans_count;  // number of answer entries
    unsigned short auth_count; // number of authority entries
    unsigned short add_count;  // number of resource entries
} DNS_HEADER;

// Structure for the query ( we wont keep the name in this structure since size is variable)

typedef struct
{
    unsigned short qtype;
    unsigned short qclass;
} QUESTION;
// Resource Record

    typedef struct
{
    unsigned short type;
    unsigned short _class;
    unsigned int ttl;
    unsigned short data_len;
} R_DATA;
// Once again name and rdata have been kept out.These two structures will help

    typedef struct
{
    unsigned char *name;
    R_DATA *resource;
    unsigned char *rdata;
} RES_RECORD;

typedef struct
{
    unsigned char *name;
    QUESTION *ques;
} QUERY;

int main()
{

    SOCKET s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); // UDP packet for DNS queries
    RES_RECORD answers[20], auth[20], addit[20];         // the replies from the DNS server
    sockaddr_in dest;

    dest.sin_family = AF_INET;
    dest.sin_port = htons(53);
    dest.sin_addr.s_addr = inet_addr(dns_servers[0]); // use the first dns server

    unsigned char buf[65536], *qname, *reader;
    DNS_HEADER *dns = NULL;
    QUESTION *qinfo = NULL;

    // Set the DNS structure to standard queries
    dns = (DNS_HEADER *)&buf;

    // set up the header
    dns->id = (unsigned short)htons(GetCurrentProcessId());
    dns->qr = 0;     // This is a query
    dns->opcode = 0; // This is a standard query
    dns->aa = 0;     // Not Authoritative
    dns->tc = 0;     // This message is not truncated
    dns->rd = 1;     // Recursion Desired
    dns->ra = 0;     // Recursion not available! hey we dont have it (lol)
    dns->z = 0;
    dns->ad = 0;
    dns->cd = 0;
    dns->rcode = 0;
    dns->q_count = htons(1); // we have only 1 question
    dns->ans_count = 0;
    dns->auth_count = 0;
    dns->add_count = 0;

    // point to the query portion
    qname = (unsigned char *)&buf[sizeof(DNS_HEADER)];
    ChangetoDnsNameFormat(qname, host);

    qinfo = (QUESTION *)&buf[sizeof(DNS_HEADER) + (strlen((const char *)qname) + 1)];

    // fill it
    qinfo->qtype = htons(1);  // we are requesting the ipv4 address
    qinfo->qclass = htons(1); // its internet (lol)

sendto(s,(char*)buf,sizeof(DNS_HEADER) + (strlen((const char*)qname)+1) +
sizeof(QUESTION),0,(sockaddr*)&dest,sizeof(dest))==SOCKET_ERROR)
int i=sizeof(dest);
recvfrom(s, (char *)buf, 65536, 0, (sockaddr *)&dest, &amp; i);
dns = (DNS_HEADER *)buf;

// move ahead of the dns header and the query field
reader = &buf[sizeof(DNS_HEADER) + (strlen((const char *)qname) + 1) +
              sizeof(QUESTION)];

printf("nThe response contains : ");
printf("n %d Questions.", ntohs(dns->q_count));
printf("n %d Answers.", ntohs(dns->ans_count));
printf("n %d Authoritative Servers.", ntohs(dns->auth_count));
printf("n %d Additional records.nn", ntohs(dns->add_count));

// reading answers
int stop = 0;
for (i = 0; i < ntohs(dns->ans_count); i++)
{
    answers[i].name = ReadName(reader, buf, stop);
    reader += stop;
    answers[i].resource = (R_DATA *)(reader);
    reader += sizeof(R_DATA);
    if (ntohs(answers[i].resource->type) == 1)
    {
        answers[i].rdata = new unsigned char[ntohs(answers[i].resource->data_len)];
        for (int j = 0; j < ntohs(answers[i].resource->data_len); j++)
            answers[i].rdata[j] = reader[j];
        answers[i].rdata[ntohs(answers[i].resource->data_len)] ='';
        reader += ntohs(answers[i].resource->data_len);
    }
    else
    {
        answers[i].rdata = ReadName(reader, buf, stop);
        reader += stop;
    }
}
// and so on….The IP address in the rdata section will be as numbers which must be converted  to a string and then to the dotted format using inet_ntoa like this

    sockaddr_in a;
    long *p;
    p = (long *)addit[i].rdata;
    a.sin_addr.s_addr = (*p);
    printf("has IPv4 address : %s", inet_ntoa(a.sin_addr));
}