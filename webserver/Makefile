
ifndef WEBSERVER_DIR
WEBSERVER_DIR = .
endif

#follow should defined by user own
#WSDL=./example.wsdl
#SERVER=./example.c
#CLIENT=./example.c
#LIBS+=

GSOAP_DIR=$(WEBSERVER_DIR)/gsoap
PLUGIN=$(WEBSERVER_DIR)/plugin

WSDL2H=wsdl2h
GSOAP=soapcpp2
SOAPH=$(GSOAP_DIR)/stdsoap2.h
SOAPC=$(GSOAP_DIR)/stdsoap2.c
SOAPCPP=$(GSOAP_DIR)/stdsoap2.cpp
SOAPDOMC=$(GSOAP_DIR)/dom.c
SOAPDOMCPP=$(GSOAP_DIR)/dom.cpp
CC=gcc
CPP=g++
LIBS+=-lpthread -lz -lssl -lcrypto
COFLAGS=-O2
CWFLAGS=-Wall -Wno-deprecated-declarations
CIFLAGS=-I. -I$(WEBSERVER_DIR) -I$(PLUGIN)
#CMFLAGS=-DWITH_COOKIES -DWITH_GZIP -DWITH_OPENSSL 
CMFLAGS=-DWITH_COOKIES -DWITH_OPENSSL -DWITH_NOIDREF -DSOAP_BUFLEN=262144
CFLAGS=$(CWFLAGS) $(COFLAGS) $(CIFLAGS) $(CMFLAGS)

SRC= $(WEBSERVER_DIR)/webserver.c
	
all:		webserver client
client:         
		$(CC) $(CWFLAGS) $(COFLAGS) $(CIFLAGS) -o $@ $(CLIENT) soapClient.c soapC.c $(SOAPC)
webserver:	webserver.h $(SRC) logging.o httpget.o httpform.o httpda.o md5evp.o threads.o options.o $(SOAPH) $(SOAPC)
		$(GSOAP) -c -L webserver.h
		$(CC) $(CFLAGS) -o webserver $(SRC) logging.o httpget.o httpform.o httpda.o md5evp.o threads.o options.o soapC.c soapClient.c soapServer.c $(SOAPC) $(LIBS) $(SERVER)
webserver.h:    $(WSDL)
		$(WSDL2H) -c -o $@ $< 
options.o:	$(WEBSERVER_DIR)/opt.h $(WEBSERVER_DIR)/options.h $(WEBSERVER_DIR)/options.c
		$(GSOAP) -cnpopt $(WEBSERVER_DIR)/opt.h
		$(CC) $(CFLAGS) -c $(WEBSERVER_DIR)/options.c
logging.o:	$(PLUGIN)/logging.h $(PLUGIN)/logging.c
		$(CC) $(CFLAGS) -c $(PLUGIN)/logging.c
httpget.o:      $(PLUGIN)/httpget.h $(PLUGIN)/httpget.c
		$(CC) $(CFLAGS) -c $(PLUGIN)/httpget.c
httpform.o:	$(PLUGIN)/httpform.h $(PLUGIN)/httpform.c
		$(CC) $(CFLAGS) -c $(PLUGIN)/httpform.c
httpda.o:	$(PLUGIN)/httpda.h $(PLUGIN)/httpda.c
		$(CC) $(CFLAGS) -c $(PLUGIN)/httpda.c
md5evp.o:	$(PLUGIN)/md5evp.h $(PLUGIN)/md5evp.c
		$(CC) $(CFLAGS) -c $(PLUGIN)/md5evp.c
threads.o:	$(PLUGIN)/threads.h $(PLUGIN)/threads.c
		$(CC) $(CFLAGS) -c $(PLUGIN)/threads.c
.PHONY: clean clear
clear:
		rm -f *.o soapH.h soapStub.h soapC.c soapClient.c soapServer.c soapClientLib.c soapServerLib.c
clean:
		rm -f *.o soapH.h soapStub.h soapC.c soapClient.c soapServer.c soapClientLib.c soapServerLib.c
		rm -f optH.h optC.c optStub.h optStub.c
		rm -f *.xsd *.xml *.nsmap *.log
		rm -f webserver.h webserver client
