#include "arg.h"
#include <assert.h>

#define ARRAY_LEN(a) (sizeof a / sizeof a[0])

id_t _l, _a, _p;

int parse(int argc, char** argv)
{
	init_options();
	_l = add_option('l');
	_a = add_option('a');
	_p = add_option('p');
	return parse_options(argc, argv);
}

int main()
{
	char* argv[] = {
		"program_name",
		"-lap",
		"-pa",
		"--",
		"-l",
		"arg1",
	};
	int argc = ARRAY_LEN(argv);

	assert(parse(argc, argv) == 4);
	assert(is_set(_l));
	assert(is_set(_p));
	assert(is_set(_a));

	return 0;
}
