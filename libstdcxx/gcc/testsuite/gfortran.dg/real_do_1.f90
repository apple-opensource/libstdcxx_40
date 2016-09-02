! { dg-do run }
! Test REAL type iterators in DO loops
program real_do_1
  real x, y
  integer n

  n = 0
  y = 1.0
  do x = 1.0, 2.05, 0.1 ! { dg-warning "REAL DO loop" "" }
    call check (x, y)
    y = y + 0.1
    n = n + 1
  end do
  if (n .ne. 11) call abort()
contains
subroutine check (a, b)
  real, intent(in) :: a, b

  if (abs (a - b) .gt. 0.00001) call abort()
end subroutine
end program
