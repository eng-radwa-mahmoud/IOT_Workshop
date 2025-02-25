
#include <linux/module.h>
#include <linux/init.h>

#include "fileoperations.h"

MODULE_LICENSE("GPL")
MODULE_AUTHOR("Radwa Mahmoud")
MODULE_DESCRIPTION("Gpio driver to control led")


struct structContainer
{
    dev_t deviceNumber;
    struct cdev cdevObject;
    struct file_operations fileOperations;
    struct class  *class;
}data{
    .fileOperations = {
        .owner = THIS_MODULE,
        .open = ledFile_open,
        .close = ledFile_close,
        .write = ledFile_write,
        .read = ledFile_read
    }
};

static int __init ledDriverInit()
{
    printk("led driver init\n");
    if(alloc_chrdev_region(&data.deviceNumber,0,1,"Led-Driver") < 0)
    {
        printk("DEvice Number Couldn't be allocated");
        return -1;
    }
    cdev_init(&data.cdevObject, &data.fileOperations);

    if(cdev_add(&data.cdevObject,&data.deviceNumber,1) == -1)
    {
     printk("DEvice registraion to kernel failed"); 
     return -1;  
     goto devAddError;
    }

    if(data.class = class_create(THIS_MODULE,"LED") == NULL)
    {
        printk("DEvice class creation failed"); 
        goto classError;
    }

    if(device_create(data.class,NULL,&data.deviceNumber,NULL,"Led-Driver")== NULL)
    {
        printk("DEvice file creation failed"); 
        goto deviceFileError;
    }

    if(gpio_request(21,"rpi_gpio_21")){
        printk("cannot allocate for GPIO 21\n");
        goto GPIO_REQUEST_ERROR;
    }
    if(gpio_direction_output(21,0)){
        printk("cannot set the pin to be output  \n");
        goto GPIO_DIR_ERROR;
    }
    

GPIO_DIR_ERROR:
    gpio_free(21);
GPIO_REQUEST_ERROR:
    device_destroy(data.class, data.deviceNumber);
deviceFileError:
    class_destroy(data.class);
classError:
    cdev_del(&data.cdevObject);
devAddError:
   unregister_chrdev_region(data.deviceNumber,1); 
   return -1;
}
static void __exit ledDriverExit()
{
	gpio_set_value(21,0);
	gpio_free(21);
	device_destroy(&data.class, &data.deviceNumber);
	class_destroy(data.class);
	cdev_del(&data.cdevObject);
	unregister_chrdev_region(data.deviceNumber,1);
}

module_init(ledDriverInit);
module_exit(ledDriverExit);
