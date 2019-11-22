MAKE := make -w
PWD := $(shell pwd)

PATH := /usr/bin/
PATH := /opt/toolchains/stbgcc-4.8-1.1/arm-linux-gnueabihf/bin/
CROSS_COMPILE :=

SYSROOT := /opt/toolchains/stbgcc-4.8-1.1/arm-linux-gnueabihf/sys-root/

LIBNL_DIR = $(PWD)/libnl-1.1.4
OPENSSL_DIR = $(PWD)/openssl-1.0.1s
WPA_SUPPLICANT_DIR = $(PWD)/wpa_supplicant-2.9/wpa_supplicant

all:wpa_supplicant

wpa_supplicant:openssl libnl
        cp -rf $(WPA_SUPPLICANT_DIR)/defconfig $(WPA_SUPPLICANT_DIR)/.config
        $(MAKE) -C $(WPA_SUPPLICANT_DIR) CC=arm-linux-gnueabihf-gcc
        cp -rf $(WPA_SUPPLICANT_DIR)/wpa_cli $(WPA_SUPPLICANT_DIR)/wpa_supplicant $(PWD)

openssl:
        if [ ! -f $(OPENSSL_DIR)/config.log ];then cd $(OPENSSL_DIR) && ./config no-asm --prefix=$(SYSROOT)/usr os/compiler:arm-linux-gnueabihf-gcc;fi
        $(MAKE) -C $(OPENSSL_DIR)
        arm-linux-gnueabihf-gcc -shared -o libcrypto.so $(OPENSSL_DIR)/libcrypto.a
        arm-linux-gnueabihf-gcc -shared -o libssl.so $(OPENSSL_DIR)/libssl.a
        $(MAKE) -C $(OPENSSL_DIR) install DESTDIR=$(SYSROOT)
        cp -rf libcrypto.so libssl.so $(SYSROOT)/usr/lib

libnl:
        if [ ! -f $(LIBNL_DIR)/config.log ];then cd $(LIBNL_DIR) && ./configure --prefix=/usr --host=arm-linux-gnueabihf;fi
        $(MAKE) -C $(LIBNL_DIR)
        $(MAKE) -C $(LIBNL_DIR) install DESTDIR=$(SYSROOT)

clean:
        rm -rf *.so *.so.* wpa_cli wpa_supplicant