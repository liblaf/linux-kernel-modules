ifneq ($(KERNELRELEASE),)
# kbuild part of makefile
obj-m := hello_proc.o

else
# normal makefile
PWD  := $(shell pwd)
KDIR ?= /lib/modules/$(shell uname --kernel-release)/build

.PHONY: default
default:
	$(MAKE) -C $(KDIR) M=$(PWD)

.PHONY: modules
modules:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

.PHONY: clean
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

.PHONY: help
help:
	$(MAKE) -C $(KDIR) M=$(PWD) help

endif
