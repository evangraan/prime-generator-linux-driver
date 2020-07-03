#include "generator.h"
#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Apache license version 2.0");
MODULE_AUTHOR("Ernst van Graan");

static int generator_init(void)
{
    printk(KERN_NOTICE "[prime-generator] initializing");
    return register_generator();
}
static void generator_exit(void)
{
    printk(KERN_NOTICE "[prime-generator] exiting");
    unregister_generator();
}

module_init(generator_init);
module_exit(generator_exit);
