#include <iostream>
#include <unistd.h>
#include <stdlib.h>

#include "opts.h"

using namespace std;

Settings options(int argc, char **argv)
{
	int SET_SIZE = DEFAULT_SET_SIZE;
	int NUM_SETS = DEFAULT_NUM_SETS;
	int NUM_PLAYERS = DEFAULT_NUM_PLAYERS;

	int opt;
	while ((opt = getopt(argc, argv, "s:n:p:h")) != -1) {
		switch (opt) {
			case 's':
				SET_SIZE = atoi(optarg);
				break;
			case 'n':
				NUM_SETS = atoi(optarg);
				break;
			case 'p':
				NUM_PLAYERS = atoi(optarg);
				break;
			case 'h':
				usage(argv);
				exit(EXIT_SUCCESS);
			default:  // '?'
				usage(argv);
				exit(EXIT_FAILURE);
		}
	}

	Settings settings = {SET_SIZE, NUM_SETS, NUM_PLAYERS};
	return settings;
}

void usage(char **argv)
{
	cerr
		<< "Usage: " << argv[0] << " [OPTIONS]"          << endl
		                                                 << endl
		<< "  A flexible engine for imaginary quartet!"  << endl
		                                                 << endl
		<< "Options:"                                    << endl
		<< "  -s [int]    Size of one set.   [default: " << DEFAULT_SET_SIZE    << "]" << endl
		<< "  -n [int]    Number of sets.    [default: " << DEFAULT_NUM_SETS    << "]" << endl
		<< "  -p [int]    Number of players. [default: " << DEFAULT_NUM_PLAYERS << "]" << endl
		<< "  -h          Show this help and exit."      << endl;
}
