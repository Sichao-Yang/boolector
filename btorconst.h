#ifndef BTORCONST_H_INCLUDED
#define BTORCONST_H_INCLUDED

#include "btormem.h"

/*------------------------------------------------------------------------*/
/* PRIVATE INTERFACE                                                      */
/*------------------------------------------------------------------------*/

char *btor_int_to_bin (BtorMemMgr *mm, int x, int len);

/*------------------------------------------------------------------------*/
/* Unbounded bit width operators.
 */
char *btor_add_unbounded_const (BtorMemMgr *mm, const char *a, const char *b);

char *btor_mult_unbounded_const (BtorMemMgr *mm, const char *a, const char *b);

char *btor_sub_unbounded_const (BtorMemMgr *mm, const char *a, const char *b);

char *btor_udiv_unbounded_const (BtorMemMgr *mm,
                                 const char *a,
                                 const char *b,
                                 char **rest_ptr);

char *btor_decimal_to_const (BtorMemMgr *mm, const char *str);
char *btor_decimal_to_const_n (BtorMemMgr *mm, const char *str, int len);

char *btor_hex_to_const (BtorMemMgr *mm, const char *str);
char *btor_hex_to_const_n (BtorMemMgr *mm, const char *str, int len);

/*------------------------------------------------------------------------*/
/* Fixed width operators.  The arguments and the result have the same width.
 */
char *btor_not_const (BtorMemMgr *mm, const char *a);

char *btor_and_const (BtorMemMgr *mm, const char *a, const char *b);

char *btor_eq_const (BtorMemMgr *mm, const char *a, const char *b);

char *btor_add_const (BtorMemMgr *mm, const char *a, const char *b);

char *btor_neg_const (BtorMemMgr *mm, const char *a);

char *btor_sub_const (BtorMemMgr *mm, const char *a, const char *b);

char *btor_umul_const (BtorMemMgr *mm, const char *a, const char *b);

char *btor_udiv_const (BtorMemMgr *mm, const char *a, const char *b);

char *btor_urem_const (BtorMemMgr *mm, const char *a, const char *b);

char *btor_sll_const (BtorMemMgr *mm, const char *a, const char *b);

char *btor_srl_const (BtorMemMgr *mm, const char *a, const char *b);

char *btor_uext_const (BtorMemMgr *mm, const char *c, int len);

char *btor_ult_const (BtorMemMgr *mm, const char *a, const char *b);

char *btor_concat_const (BtorMemMgr *mm, const char *a, const char *b);

/*------------------------------------------------------------------------*/
/* Work for both fixed and unbounded bit width constants.
 */
char *btor_copy_const (BtorMemMgr *mm, const char *c);

void btor_delete_const (BtorMemMgr *mm, char *c);

int btor_cmp_const (const char *a, const char *b);

char *btor_const2decimal (BtorMemMgr *mm, const char *c);

char *btor_slice_const (BtorMemMgr *mm, const char *a, int upper, int lower);

/*------------------------------------------------------------------------*/
/* Output functions.
 */
char *btor_const_to_hex (BtorMemMgr *mm, const char *c);
char *btor_const_to_decimal (BtorMemMgr *mm, const char *c);

#endif
