
#include "fileoperations.h"

ssize_t ledFile_write(struct file *File, const char __user *user_buff, size_t count, loff_t *offs)
{
    int not_copied;
    char value;
    not_copied = copy_from_user(&value, user_buff, sizeof(value));

    switch(value)
    {
        case '1':
            gpio_set_value(21,1);
            break;
        case '0':
            gpio_set_value(21,0);
            break;
        default:
            printk("Error: invalid input data\n");
            break;
    }

    count = count-not_copied;
    return count;
}

ssize_t ledFile_read(struct file *File, char __user *user_buffer, size_t count, loff_t *offs)
{
    printk("Inavlid Operation(read)\n");
    return -ENOSYS;
}

int ledFile_open(struct inode *device_file, struct file *instance)
{
    printk("%s dev_nr - open was called!\n", __FUNCTION__);
    return 0;
}

int ledFile_close(struct inode *device_file, struct file *instance)
{
    printk("dev_nr - close was called!\n");
    return 0;
}
