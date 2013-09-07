
#include "soapH.h" // include the generated declarations 
#include "calc.nsmap" // include the XML namespace mappings 

int ns2__add(struct soap *soap, double a, double b, double* result) 
{ 
	*result = a+ b;
     return SOAP_OK; 
}
int ns2__sub(struct soap *soap, double a, double b, double* result) 
{ 
	*result = a+ b;
     return SOAP_OK; 
}
int ns2__pow(struct soap *soap, double a, double b, double* result) 
{ 
	*result = a+ b;
     return SOAP_OK; 
}
int ns2__mul(struct soap *soap, double a, double b, double* result) 
{ 
	*result = a+ b;
     return SOAP_OK; 
}
int ns2__div(struct soap *soap, double a, double b, double* result) 
{ 
	*result = a+ b;
     return SOAP_OK; 
}
