// dhcp1.cpp

// https://stackoverflow.com/questions/17866222/dhcp-c-program

#include "StdAfx.h"
#include "WINDOWS.H"
#include "Dhcpcsdk.h"
//#include "Dhcpcsvc.dll"
#include <iostream>

using namespace std;

#pragma comment(lib, "dhcpcsvc.lib")

#define NUMBER_OF_OPTIONS 7

//#define NUMBER_OF_OPTIONS 4
enum OptionArrayPositions
{
   MASK,
   DNS,
   HOSTNAME,
   VENDOR,
   LEASE_TIME,
   MESSAGE_TYPE,
   SERVERIP
};

BOOL RetrieveDHCPInfo(LPWSTR pszAdapterName);
void PrintAsAscii(DHCPCAPI_PARAMS param);
void PrintAsIP(DHCPCAPI_PARAMS param);
void PrintAsInt(DHCPCAPI_PARAMS param);
void PrintMask(DHCPCAPI_PARAMS param);
void PrintDNS(DHCPCAPI_PARAMS param);
void PrintHostName(DHCPCAPI_PARAMS param);
void PrintVendor(DHCPCAPI_PARAMS param);
void PrintLeaseTime(DHCPCAPI_PARAMS param);
void PrintMessageType(DHCPCAPI_PARAMS param);
void PrintServerIP(DHCPCAPI_PARAMS param);
void Printer(char[500]);

BOOL RetrieveDHCPInfo(LPWSTR pszAdapterName)
{
   DWORD dwError, dwSize;
   CHAR TmpBuffer[1000]; // host name won't be larger than this

   DHCPCAPI_PARAMS DhcpApiMaskParams = {0,
                                        OPTION_SUBNET_MASK,
                                        FALSE,
                                        NULL,
                                        0};
   DHCPCAPI_PARAMS DhcpApiDNSParams = {0,
                                       OPTION_DOMAIN_NAME_SERVERS,
                                       FALSE,
                                       NULL,
                                       0};
   DHCPCAPI_PARAMS DhcpApiHostNameParams = {
       0,                // Flags
       OPTION_HOST_NAME, // OptionId
       FALSE,            // vendor specific?
       NULL,             // data filled in on return
       0                 // nBytes
   };
   DHCPCAPI_PARAMS DhcpApiVendorParams = {0,
                                          OPTION_VENDOR_SPEC_INFO,
                                          FALSE,
                                          NULL,
                                          0};
   DHCPCAPI_PARAMS DhcpApiLeaseTimeParams = {0,
                                             OPTION_LEASE_TIME,
                                             FALSE,
                                             NULL,
                                             0};
   DHCPCAPI_PARAMS DhcpApiMsgTypeParams = {0,
                                           OPTION_MESSAGE_TYPE,
                                           FALSE,
                                           NULL,
                                           0};

   DHCPCAPI_PARAMS DhcpApiServerNameParams = {0,
                                              OPTION_SERVER_IDENTIFIER,
                                              FALSE,
                                              NULL,
                                              0};

   DHCPCAPI_PARAMS paramArray[NUMBER_OF_OPTIONS] = {DhcpApiMaskParams,
                                                    DhcpApiDNSParams,
                                                    DhcpApiHostNameParams,
                                                    DhcpApiVendorParams,
                                                    DhcpApiLeaseTimeParams,
                                                    DhcpApiMsgTypeParams,
                                                    DhcpApiServerNameParams};

   DHCPCAPI_PARAMS_ARRAY DhcpApiParamsArray = {NUMBER_OF_OPTIONS, // only one option to request
                                               paramArray};
   DHCPCAPI_PARAMS_ARRAY SendParams = {0, NULL};

   dwSize = sizeof(TmpBuffer);
   dwError = DhcpRequestParams(DHCPCAPI_REQUEST_SYNCHRONOUS, // Flags
                               NULL,                         // Reserved
                               pszAdapterName,               // Adapter Name
                               NULL,                         // not using class id
                               SendParams,                   // nothing to send
                               DhcpApiParamsArray,           // requesting params
                               (PBYTE)TmpBuffer,             // buffer
                               &dwSize,                      // buffer size
                               NULL                          // Request ID
   );

   cout << "Your Error Code from DhcpRequestParams is " << dwError << endl;
   if (ERROR_MORE_DATA == dwError)
   {
      //
      // dwSize is not large enough.
      cout << "dwSize is not large enough" << endl;
      //
   }

   int success = FALSE;
   if (NO_ERROR == dwError)
   {
      for (int i = 0; i < NUMBER_OF_OPTIONS; i++)
      {
         if (paramArray[i].nBytesData != 0)
         {
            success = true;
            switch (paramArray[i].OptionId)
            {
            case OPTION_SUBNET_MASK:
               PrintMask(paramArray[i]);
               break;
            case OPTION_DOMAIN_NAME_SERVERS:
               PrintDNS(paramArray[i]);
               break;
            case OPTION_HOST_NAME:
               PrintHostName(paramArray[i]);
               break;
            case OPTION_VENDOR_SPEC_INFO:
               PrintVendor(paramArray[i]);
               break;
            case OPTION_LEASE_TIME:
               PrintLeaseTime(paramArray[i]);
               break;
            case OPTION_MESSAGE_TYPE:
               PrintMessageType(paramArray[i]);
               break;
            case OPTION_SERVER_IDENTIFIER:
               PrintServerIP(paramArray[i]);
               break;
            }
         }
      }
      cout << endl;
   }

   if (success == TRUE)
      return TRUE;
   else
      return FALSE;
}

void PrintAsAscii(DHCPCAPI_PARAMS param)
{
   unsigned char temp[260];
   CopyMemory(temp,
              param.Data,
              param.nBytesData);

   temp[param.nBytesData] = '\0';
   cout << temp;
}

void PrintAsIP(DHCPCAPI_PARAMS param)
{
   unsigned char temp[260];
   CopyMemory(temp,
              param.Data,
              param.nBytesData);

   temp[param.nBytesData] = '\0';
   for (unsigned int i = 0; i < param.nBytesData; i++)
   {
      if (i % 4 == 0)
      {
         cout << endl;
      }
      cout << (int)temp[i] << ".";
   }
}

void PrintAsInt(DHCPCAPI_PARAMS param)
{
   unsigned char temp[260];
   CopyMemory(temp,
              param.Data,
              param.nBytesData);

   temp[param.nBytesData] = '\0';
   cout << (unsigned int)*temp;
}

void PrintMask(DHCPCAPI_PARAMS param)
{
   /* Print the subnet mask
    * This is stored as Option 1
    *
    *
    */
   cout << endl
        << "MASK" << endl;
   cout << "--------------------------------------------";
   PrintAsIP(param);
}

void PrintDNS(DHCPCAPI_PARAMS param)
{
   /* Print the DNS Servers
    * This is stored as Option 6
    *
    *
    */
   cout << endl
        << "\nDNS SERVERS" << endl;
   cout << "--------------------------------------------";
   PrintAsIP(param);
}

void PrintHostName(DHCPCAPI_PARAMS param)
{
   /* Print the Host name or IP address if
    * that's what's stored in this option
    * This is stored as Option 12
    *
    */
   cout << endl
        << "\nHOST NAME" << endl;
   cout << "--------------------------------------------";
   cout << endl
        << "ANSI String" << endl;
   PrintAsAscii(param);
   cout << endl
        << "IP FORMAT";
   PrintAsIP(param);
}

void PrintVendor(DHCPCAPI_PARAMS param)
{
   /* Print the Vendor parameter
    * This is stored as Option 43
    *
    *
    */
   cout << endl
        << "\nVENDOR PARAMETER" << endl;
   cout << "--------------------------------------------";
   cout << endl
        << "ANSI String" << endl;
   PrintAsAscii(param);
}

void PrintLeaseTime(DHCPCAPI_PARAMS param)
{
   /* Print the Lease Time
    * This is stored as Option 51
    *
    *
    */
   cout << endl
        << "\nLEASE TIME" << endl;
   cout << "--------------------------------------------" << endl;
   PrintAsInt(param);
   cout << endl;
}

void PrintMessageType(DHCPCAPI_PARAMS param)
{
   /* Print the message type
    * This is stored as Option 53
    *
    *
    */
   cout << endl
        << "\nMESSAGE TYPE" << endl;
   cout << "--------------------------------------------" << endl;
   ;
   PrintAsInt(param);
}

void PrintServerIP(DHCPCAPI_PARAMS param)
{
   /* Print the DHCP servers IP address
    * This is stored as Option 54
    *
    *
    */
   cout << endl
        << "\nDHCP SERVER" << endl;
   cout << "--------------------------------------------";
   PrintAsIP(param);
}
void Printer(char input[500])
{
   cout << input << endl;
}

int main()
{

   struct DHCPAPI_PARAMS
   {
      ULONG Flags;
      ULONG OptionId;
      BOOL IsVendor;
      LPBYTE Data;
      DWORD nBytesData;
   };
   /*
   DHCPCAPI_PARAMS param;
   param.Flags = 0;
   param.OptionId = 43;
   param.IsVendor = true;
   //param.Data
   PrintAsIP(param);
   */
   DHCPCAPI_PARAMS param = {0,
                            0,
                            FALSE,
                            NULL,
                            0};

   int x = 1;
   char name[26];
   char hold[26];
   while (x != 0)
   {
      // cout<<"Hello World"<< endl;
      // cin>>name;
      cin >> x;
      param.OptionId = x;
      PrintMessageType(param);
      PrintServerIP(param);
      PrintLeaseTime(param);
      PrintVendor(param);
      PrintDNS(param);
      Printer("\n\nEnter New Value:");
   }

   return 0;
}