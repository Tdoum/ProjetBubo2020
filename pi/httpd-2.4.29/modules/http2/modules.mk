DISTCLEAN_TARGETS = modules.mk
static = 
shared = 
MOD_CFLAGS = -I/usr/local/include
MOD_CPPFLAGS = -DH2_OPENSSL
MOD_LDFLAGS = -L/usr/local/lib -lssl -lcrypto -lrt -lcrypt -lpthread -ldl
