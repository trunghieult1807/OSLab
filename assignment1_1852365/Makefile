obj-m += test.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean
test:
	sudo dmesg -C
	sudo insmod test.ko
	sudo rmmod test.ko
	dmesg
