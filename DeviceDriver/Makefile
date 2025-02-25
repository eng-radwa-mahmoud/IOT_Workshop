obj-m += leddriver.o
leddriver-y := gpioderiver.o fileoperations.o

all:
	$(MAKE) -C $(KERNEL_SRC) M=$(shell pwd) 

modules_install:
	$(MAKE) -C $(KERNEL_SRC) M=$(shell pwd) modules_install

clean:
     	rm -f *.o *~ .depend .*.cmd *.ko *.mod.c
     	rm -f Module.makers Module.symvers modules.order
     	rm -rf .tmp_versions Modules.symvers
	
