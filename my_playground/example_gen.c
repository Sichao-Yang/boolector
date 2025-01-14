#include <boolector.h>

int
main ()
{
  Btor *btor;
  BoolectorNode *x, *y, *eq;
  BoolectorSort sort;

  btor = boolector_new ();
  sort = boolector_bitvec_sort (btor, 32);

  x  = boolector_var (btor, sort, "x");
  y  = boolector_var (btor, sort, "y");
  eq = boolector_eq (btor, x, y);

  boolector_assert (btor, eq);

  if (boolector_sat (btor) == BOOLECTOR_SAT)
  {
    printf ("SAT\n");
  }
  else
  {
    printf ("UNSAT\n");
  }

  boolector_release (btor, x);
  boolector_release (btor, y);
  boolector_release (btor, eq);
  boolector_release_sort (btor, sort);
  boolector_delete (btor);

  return 0;
}