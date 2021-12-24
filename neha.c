#include <stdio.h>
int main(){
  float x[10], y[10][10]={0}, xx, h, a, u,term,sum;
  int i, j, n;
  printf("Give number of observations: ");
  scanf("%d", &n);
  for(i=0; i<n; i++){
    printf("Give %dth data point: ", i+1);
    scanf( "%f%f", &x[i], &y[i][0] );
  }
  printf( "Given points are: \nx\t\ty\n" );
  for( j=1; j<n; j++ ){
    for(i=0; i+j< n; i++){
      y[i][j] = y[i+1][j-1]-y[i][j-1];
    }
  }
  for( i=0; i<n; i++ ){
    printf( "%.1f\t", x[i] );
    for(j=0; j < n-i; j++){
      printf( "%.1f\t", y[i][j] );
    }
    puts("");
  }
  printf("give value of xx: ");
  scanf("%f", &xx);
  printf("give value of a: ");
  scanf("%f",&a);
  printf("give value of h: ");
  scanf("%f",&h);
  u = (xx-a)/h;
  term=1;
  sum=0;
  for(i=1; i<10; i++){
    term = term*y[i][n-1]*n/y[i][n]/(u-(n-1));
    sum = sum + term;
  }
  printf("%f\n", sum);
}
