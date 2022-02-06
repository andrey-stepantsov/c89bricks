#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "CBricksLibConfig.h"

#include "cprimes.h"

void printVersion(){
  printf("cprime %d.%d\n", CBricksLib_VERSION_MAJOR, CBricksLib_VERSION_MINOR);
}

char quick_help[] =
    "The cprime utility checks if a number (non-negative integer) is a prime.\n"
    "\n    cprime [OPTION...] <number>...\n"
    "\nExits with zero status if the number is a prime number.\n"
    "use -h or --help for information about options\n";

void printQuickHelp(){
  printf("%s", quick_help);
}

char help[] =
    "The cprime utility checks if a number (non-negative integer) is a prime.\n"
    "The following forms are supported:\n"
    "\n (1)   cprime [OPTION...] <number>...\n"
    "\n (2)   cprime [OPTION...]\n"
    "\n(1) The first form tests one or more non-negative integers supplied\n"
    "as arguments, if they are primes. The utility prints space separated\n"
    "results of the testing: '0' for a non-prime and '1' for a prime. \n"
    "Then, the utility exists with zero status if all the arguments are\n"
    "primes. If at least one argument is not a prime, the exit status is not\n"
    "zero.\n"
    "\n(2) The 2nd form, instead of testing arguments, tries to read the"
    "numbers for the standrad input.\n";

void printHelp() { printf("%s", help); }

int main(int argc, char **argv) {
  int c;
  int digit_optind = 0;
  int silent = 0;

  opterr = 0;

  while (1) {
    int this_option_optind = optind ? optind : 1;
    int option_index = 0;
    static struct option long_options[] = {
        {"generate", required_argument, 0, 'g'},
        {"help", no_argument, 0, 'h'},
        {"version", no_argument, 0, 'v'},
        {"quiet", no_argument, 0, 'q'},
        //{"file", required_argument, 0, 0},
        {0, 0, 0, 0}};

    c = getopt_long(argc, argv, "g:vhq", long_options, &option_index);
    if (c == -1)
      break;

    switch (c) {

    case 0:
      printf("option %s", long_options[option_index].name);
      if (optarg)
        printf(" with arg %s", optarg);
      printf("\n");
      break;

    case 'h':
      printHelp();
      exit(EXIT_SUCCESS);
      break;

    case 'v':
      printVersion();
      exit(EXIT_SUCCESS);
      break;

    case 'q':
      silent = 1;
      break;

    case 'g': {
      printf("option g with value '%s'\n", optarg);
    } break;

    case '?':
      printf("?\n");
      break;

    default:
      printf("?? getopt returned character code 0%o ??\n", c);
    }
  }

  if (optind < argc) {
    //printf("non-option ARGV-elements: ");
    int non_primes = 0;
    while (optind < argc) {
      char* end_p = NULL;
      long long int num = strtoll(argv[optind], &end_p, 10);
      if(0 == *end_p) {
        int test = is_prime(num);
        if (!test)
          ++non_primes;
        if (!silent)
          printf("%d ", test);
      } else {
        printf("error processing: %s, (%d)\n", argv[optind], (int)*end_p);
        exit(EXIT_FAILURE);
      }
      ++optind;
    }
    exit(non_primes ? EXIT_FAILURE : EXIT_SUCCESS);
    //printf("\n");
  }

  if (!isatty(fileno(stdin))) {
    printf("processing stdin\n");
  } else {
    printQuickHelp();
    exit(EXIT_FAILURE);
  }

  return 0;
}
