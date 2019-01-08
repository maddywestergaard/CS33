#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *thread(void *vargp);

struct node {
  int num;
  int label;
};

int leonum(int n){
  if (n==1 || n==0) {
    return 1;
  } else if ( n < 0) {
    fprintf(stderr, "error with determining leonardo number");
    exit(1);
  }

  return (leonum(n-1) + leonum(n-2) + 1);  
}

int main(int argc, char **argv){
  if (argc != 2) {
    fprintf(stderr, "wrong number of arguments");
    exit(1);
  }

  int n =atoi(argv[1]);

  if (n==0){
    printf("[0]\n");
    return 1;
  } else if(n==1){
    printf("[1]\n");
  }

  printf("(0\n");
  struct node root;
  root.num = n;
  root.label = 0;

  pthread_t tid;
  pthread_create(&tid, NULL, thread, &root);
  pthread_join(tid, NULL);
  
  printf("0)\n");
  exit(0);
}

void *thread(void *vargp)
{
  struct node* root = (struct node*) vargp;

  if (root->num <=1){
    printf("[%d]\n", root->label);
    pthread_exit(NULL);
  } else {
  
    struct node left;
    struct node right;

    left.num = root->num-1;
    left.label = root->label+1;

    right.num = root->num-2;
    right.label = root->label+1 + leonum(root->num-1);
  
    if (left.num > 1){
      printf("(%d\n", left.label);
    } 

    pthread_t tid;
    pthread_create(&tid,NULL,thread,&left);
    pthread_join(tid,NULL);

    if (left.num > 1){
      printf("%d)\n", left.label);
    }
    
    if (right.num > 1){
      printf("(%d\n", right.label);
    }

    pthread_t tid2;
    pthread_create(&tid2,NULL,thread,&right);
    pthread_join(tid2,NULL);

    if (right.num > 1){
      printf("%d)\n", right.label);
    }

  }
  return NULL;
}
