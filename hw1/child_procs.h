#ifndef CHILD_PROCS_H
#define CHILD_PROCS_H

#include "create_procs.h"

void grandchild();
void child();
void parent();

void open_to_write();
void open_to_read();
void close_file();
int read_word(char* buff);

#endif
