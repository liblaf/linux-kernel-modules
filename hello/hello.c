#include <linux/init.h>    // __init, __exit
#include <linux/module.h>  // MODULE_LICENSE, module_init, module_exit
#include <linux/printk.h>  // pr_alert

MODULE_LICENSE("Dual BSD/GPL");

static int __init hello_init(void);
module_init(hello_init);
static void __exit hello_exit(void);
module_exit(hello_exit);

static int __init hello_init(void) {
  pr_alert("Hello, World\n");
  return 0;
}

static void __exit hello_exit(void) { pr_alert("Goodbye, cruel world\n"); }
