#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
  char *sN, *sM;
  size_t lN = 0, lM = 0;
  int N = 0, M = 0;
  int i, j, k;

  /**
   * Get String for N
   */
  int ch = EOF;
  sN = (char *) malloc(sizeof(char));
  if (!sN) {
    return 1;
  }
  while ((ch = getchar()) != '\n' && ch != EOF) {
    sN[lN++] = (char) ch;
    sN = realloc(sN, sizeof(char) * lN);
    if (!sN) {
      return 1;
    }
  }
  sN[lN] = '\0';

  sN = realloc(sN, sizeof(char) * lN);

  /**
   * String to Int
   */
  k = lN;
  while (k >= 0) {
    if (sN[lN - k] == '1') {
      N += pow(2, k - 1);
    }
    k--;
  }

  /**
   * Get String for M
   */
  ch = EOF;
  sM = (char *) malloc(sizeof(char));
  if (!sM) {
    return 1;
  }
  while ((ch = getchar()) != '\n' && ch != EOF) {
    sM[lM++] = (char) ch;
    sM = realloc(sM, sizeof(char) * lM);
    if (!sM) {
      return 1;
    }
  }
  sM[lM]='\0';

  sM = realloc(sM, sizeof(char) * lM);

  /**
   * String to Int
   */
  k = lM;
  while (k >= 0) {
    if (sM[lM - k] == '1') {
      M += pow(2, k - 1);
    }
    k--;
  }

  scanf("%d", &i);
  scanf("%d", &j);

  /**
   * Calculate result
   */

  int last = 0, middle = 0, first = 0;

  first = (N >> (j + 1)) << (j + 1);
  middle = (M % (int) pow(2, j - i + 1)) << i;
  last = N % (int) pow(2, i);

  int result = 0;
  result = first | middle | last;

  /**
   * Dec to Bin
   */
  char R[lN];
  int tmp = result;
  k = lN - 1;
  while (k >= 0) {
    R[k--] = (tmp % 2 == 1) ? '1' : '0' ;
    tmp = tmp / 2 - (tmp % 2) / 2;
  }

  /**
   * Print result
   */
  printf("%s\n", R);

  /**
   * Free mamory
   */
  free(sN);
  free(sM);

  return 0;
}
