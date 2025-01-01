#ifndef ARGUMENTS_H_
#define ARGUMENTS_H_

struct Arguments {
    int port = 50000;
};

Arguments parseArgs(int argc, char **argv, bool no_exit = false);

#endif /* ARGUMENTS_H_ */
