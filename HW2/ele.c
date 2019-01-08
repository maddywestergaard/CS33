#define R 7
#define S 5
#define T 8

long A[R][S][T];

long
ele (long i, long j, long k)
{
  return A[R - i][1 - j][k - 1];
}

/*
for array D[R][S][T]
1.  &D[i][j] = Xd + L((S*T)i + Tj + k). I got this because the offset for each repetition of k is now S*T. To get to the actual offset of each array value, you have to go to S*T*i (to be aligned with the right value for i), then add that to T*j (to to be aligned with the right value of j), then add that to k (to get to the right value for k for that i and j).
2.  from ele.s, the equation involving i, j, and k turns out to be 40i - 8j + k. This means that T=8, S = 40/8 = 5, and R=7.
movl$7, %eax                  // eax = 7
subq%rdi, %rax            // 7 - i
leaq(%rax,%rax,4), %rax   // 5(7-i)
subq%rsi, %rax              // 5(7-i) - j
leaq7(%rdx,%rax,8), %rax   // 8[5(7-i)-j] + k + 7
movqA(,%rax,8), %rax       // 40i - 8j + k + C 
ret
*/
