#ifndef ARG_H
#define ARG_H

typedef int id_t;

int  init_options();
id_t add_option(char opt);
int  is_set(id_t id);
int  parse_options(int argc, char** argv);

#endif
