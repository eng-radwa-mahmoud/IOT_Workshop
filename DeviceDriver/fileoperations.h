#include <linux/module.h>
#include <linux/init.h>
#include <linux/moduleparam.h>
#include <linux/fs.h> 
#include <linux/cdev.h>
#include <linux/gpio.h>



ssize_t ledFile_write(struct file *file, const char __user *user_buff, size_t count, loff_t *offs);
ssize_t ledFile_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offs);
static int ledFile_open(struct inode *device_file, struct file *instance);
static int ledFile_close(struct inode *device_file, struct file *instance);


