
#include "soapH.h"
#include "calc.nsmap"


int main(int argc, char** argv)
{
	struct soap *soap = soap_new();

	soap_init(soap);

	double result;
   if (soap_call_ns2__add(soap, NULL, NULL, 1.0, 2.0, &result) == SOAP_OK){
      printf("The result is\n%g\n", result);
   }
   else
      soap_print_fault(soap, stderr);
   soap_end(soap);
   soap_free(soap);
   return 0;
}

