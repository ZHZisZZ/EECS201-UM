#include <stdio.h>
#include <string.h>

#include "calc.h"

int main(int argc, char *argv[])
{
    if (argc < 4) {
        printf(
        "calculate v0.9\n"
        "usage: <int 1> <operator> <int 2>\n"
        "\n"
        "operators:\n"
        "  + addition\n"
        "  - subtraction\n"
        "  x multiplication\n"
        "  / division\n"
        "\n"
        "return codes:\n"
        "  0: success\n"
        "  1: insufficient arguments\n"
        "  2: integer parse error\n"
        "  3: unrecognized operator\n"
        "  4: unsupported operator\n"
        "  5: divide by 0\n"
        );
        return 1;
    }

    // parse
    //  parse int
    int arg1, arg2;
    enum op op;

    int fail_parse = 0;
    if (sscanf(argv[1], "%d", &arg1) == 0) {
        fprintf(stderr, "int 1 (arg 1) is not an integer: '%s'\n", argv[1]);
        fail_parse = 1;
        return 2;
    }
    if (sscanf(argv[3], "%d", &arg2) == 0) {
        fprintf(stderr, "int 2 (arg 3) is not an integer: '%s'\n", argv[3]);
        fail_parse = 1;
    }
    if (fail_parse) return 2;

    //   parse op
    if (!strcmp(argv[2], "+")) {
        op = OP_ADD;
    } else if (!strcmp(argv[2], "-")) {
        op = OP_SUB;
    } else if (!strcmp(argv[2], "x")) {
        op = OP_MUL;
    } else if (!strcmp(argv[2], "/")) {
        op = OP_DIV;
    } else {
        fprintf(stderr, "operator (arg 2) '%s' not recognized\n", argv[2]);
        return 3;
    }

    // calculate
    int output;
    enum status status = calculate(arg1, arg2, op, &output);

    switch (status) {
    case STATUS_OKAY:
        printf("%d\n", output);
        return 0;
    case STATUS_UNSUPPORTED:
        fprintf(stderr, "Unsupported operation: %s\n", op_to_string(op));
        return 4;
    case STATUS_DIV_BY_ZERO:
        fprintf(stderr, "Divide by Zero\n");
        return 5;
    }

    return 255;
}
