#include "arg.h"
#include <string.h>
#include <assert.h>

struct option {
	int short_;
	char* val_;
};

struct {
	struct option buf[20];
	size_t len;
} options;

int init_options()
{
	memset(&options, 0, sizeof(options));
	return 0;
}

id_t add_option(char opt)
{
	assert(options.len < sizeof options.buf);

	options.buf[options.len].short_ = opt;

	return options.len++;
}

int is_set(id_t id)
{
	return (options.buf[id].val_)
		? 1 : 0;
}

int parse_options(int argc, char** argv)
{
	if (argc < 2) {
		return argc;
	}
	for (int i = 1; i < argc; i++) {
		char *arg = argv[i];
		if (*(arg++) != '-') {
			return i;
		}
		if (arg[0] == '-' && arg[1] == '\0') {
			return i+1;
		}
		while (*arg) {
			for (int j = 0; j < options.len; j++) {
				if (options.buf[j].short_ == *arg) {
					options.buf[j].val_ = arg;
				}
			}
			arg++;
		}
	}
	return argc;
}
