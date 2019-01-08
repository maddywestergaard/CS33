// uses conditional move instead of jump for both -o and -o2

long t=-1;

long cread_alt(long *xp)
{
   long *p = &t;
   return *( xp ? (xp-1) : p );
}
