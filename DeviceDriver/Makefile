obj-m += leddriver.o
leddriver-y := gpioderiver.o fileoperations.o

all:
	$(MAKE) -C $(KERNEL_SRC) M=$(shell pwd) 

modules_install:
	$(MAKE) -C $(KERNEL_SRC) M=$(shell pwd) modules_install

	