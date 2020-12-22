#include "calc.h"

const char *op_to_string(enum op op)
{
#define _(x) case(OP_##x): return #x;
    switch (op) {
    _(ADD)
    _(SUB)
    _(MUL)
    _(DIV)
    default: return "(unknown op)";
    }
#undef _
}

enum status calculate(int arg1, int arg2, enum op op, int *result)
{
    switch(op) {
    case OP_ADD:
        *result = arg1 + arg2;
        return STATUS_OKAY;
    case OP_SUB:
        *result = arg1 - arg2;
        return STATUS_OKAY;
    case OP_MUL:
        *result = arg1 * arg2;
        return STATUS_OKAY;
    case OP_DIV:
        if (arg2 == 0) return STATUS_DIV_BY_ZERO;
        *result = arg1 / arg2;
        return STATUS_OKAY;
    }
    return STATUS_UNSUPPORTED;
}
