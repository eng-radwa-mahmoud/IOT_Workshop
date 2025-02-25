#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h> 
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/gpio.h>



ssize_t ledFile_write(struct file *File, const char __user *user_buff, size_t count, loff_t *offs);
ssize_t ledFile_read(struct file *File, char __user *user_buffer, size_t count, loff_t *offs);
int ledFile_open(struct inode *device_file, struct file *instance);
int ledFile_close(struct inode *device_file, struct file *instance);


