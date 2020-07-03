#ifndef GENERATOR_H_
#define GENERATOR_H_
#include <linux/compiler.h>

__must_check int register_generator(void);
void unregister_generator(void); 

#endif //GENERATOR_H_
