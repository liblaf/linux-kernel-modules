#include <linux/init.h>     // __init, __exit
#include <linux/module.h>   // MODULE_LICENSE, module_init, module_exit
#include <linux/proc_fs.h>  // proc_ops, proc_create, remove_proc_entry
#include <linux/seq_file.h>  // seq_printf, single_open, seq_read, seq_lseek, single_release

MODULE_LICENSE("GPL");

static int hello_proc_show(struct seq_file *m, void *v);
static int hello_proc_open(struct inode *inode, struct file *file);
static int __init hello_proc_init(void);
module_init(hello_proc_init);
static void __exit hello_proc_exit(void);
module_exit(hello_proc_exit);

static const struct proc_ops hello_proc_fops = {
    .proc_open = hello_proc_open,
    .proc_read = seq_read,
    .proc_lseek = seq_lseek,
    .proc_release = single_release,
};

static int hello_proc_show(struct seq_file *m, void *v) {
  seq_printf(m, "Hello proc!\n");
  return 0;
}

static int hello_proc_open(struct inode *inode, struct file *file) {
  return single_open(file, hello_proc_show, NULL);
}

static int __init hello_proc_init(void) {
  proc_create(/*name=*/"hello_proc", /*mode=*/0, /*parent=*/NULL,
              /*proc_ops=*/&hello_proc_fops);
  return 0;
}

static void __exit hello_proc_exit(void) {
  remove_proc_entry("hello_proc", NULL);
}
