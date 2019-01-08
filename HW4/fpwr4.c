float u2f(unsigned u){
  float f = 0|u;
  return f;
}

float fpwr4(int x)
{
  unsigned exp, frac;
  unsigned u;

  if (x < -74){
    /* Too small. Return 0.0 */
    exp=0;
    frac=0;
  } else if (x < -63){
    /* Denormalized result */
    exp=0;
    frac=1<<(2x+149);
  } else if (x < 64){
    /* Normalized result */
    exp= 2*x + 127;
    frac=0;
  } else {
    /*Too big. return +oo */
    exp=255;
    frac=0;
  }
  /* Pack exp and frac into 32 bits */
  u = exp << 23 | frac;
  /* Return as float */
  return u2f(u);
}
