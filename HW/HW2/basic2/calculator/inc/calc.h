#ifndef __CALC_H__
#define __CALC_H__

#ifdef __cplusplus
extern "C" {
#endif

enum op
{
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV
};

enum status
{
    STATUS_OKAY,
    STATUS_UNSUPPORTED,
    STATUS_DIV_BY_ZERO
};

enum status calculate(int arg1, int arg2, enum op op, int *result);

const char *op_to_string(enum op op);

#ifdef __cplusplus
}
#endif

#endif//__CALC_H__
