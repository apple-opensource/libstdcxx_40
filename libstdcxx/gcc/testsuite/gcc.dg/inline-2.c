/* Ensure that we continue to consider FOO local, even though
   it has been deferred.  */
/* { dg-do compile } */
/* { dg-options "-O3 -finline-limit=0 -fpic" } */
/* { dg-warning "not supported" "PIC unsupported" { target cris-*-elf* cris-*-aout* mmix-*-* } 0 } */

static int foo(void)
{
  return 3;
}

int bar(void)
{
  /* Call twice to avoid bypassing the limit for functions called once.  */
  return foo() + foo() + 1;
}

/* { dg-final { scan-assembler-not "jsr" { target alpha*-*-* } } } */
/* { dg-final { scan-assembler-not "PLT" { target i?86-*-* x86_64-*-* } } } */
/* { dg-final { scan-assembler-not "plt" { target powerpc*-*-* } } } */
