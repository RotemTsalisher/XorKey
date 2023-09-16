#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initQueries(long** queries);
/*
 * Complete the 'xorKey' function below.
 *
 * The function is expected to return a LONG_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. LONG_INTEGER_ARRAY x
 *  2. 2D_LONG_INTEGER_ARRAY queries
 */

 /*
  * To return the long integer array from the function, you should:
  *     - Store the size of the array to be returned in the result_count variable
  *     - Allocate the array statically or dynamically
  *
  * For example,
  * long* return_long_integer_array_using_static_allocation(int* result_count) {
  *     *result_count = 5;
  *
  *     static long a[5] = {1, 2, 3, 4, 5};
  *
  *     return a;
  * }
  *
  * long* return_long_integer_array_using_dynamic_allocation(int* result_count) {
  *     *result_count = 5;
  *
  *     long *a = malloc(5 * sizeof(long));
  *
  *     for (int i = 0; i < 5; i++) {
  *         *(a + i) = i + 1;
  *     }
  *
  *     return a;
  * }
  *
  */
long* xorKey(int x_count, long* x, int queries_rows, int queries_columns, long** queries, int* result_count) {
    /* result count is the number of queries (queries_rows)
     * for each line (querie), is 'tmp' and 'max' to iterate over the line and find the max value
     * length of return array is (r - l + 1) */

    int i, l, r, j;
    int length = queries_rows;
    long max, tmp, a;

    long* res;
    res = (long*)malloc(sizeof(long) * length);
    *result_count = length;

    for (i = 0;i < queries_rows; i++)
    {
        a = queries[i][0];
        l = queries[i][1] - 1;
        r = queries[i][2] - 1;

        max = x[l] ^ a;
        for (j = l + 1;j < r + 1; j++)
        {
            tmp = x[j] ^ a;
            if (tmp > max)
            {
                max = tmp;
            }
        }
        res[i] = max;
    }

    return res;
}

int main()
{
    int q = 8;
    long* x = malloc(15 * sizeof(long));
    long** queries = malloc(q * sizeof(long*));
    int result_count;
    for (long k = 0; k < 15; k++)
    {
        x[k] = k + 1;
    }

    for (int i = 0; i < q; i++) {
        *(queries + i) = malloc(3 * (sizeof(long)));

    }
    initQueries(queries);
    long* result = xorKey(1, x, q, 3, queries, &result_count);

    for (int k = 0; k < result_count; k++)
    {
        printf("Querie %d result: [%ld]\n", k + 1, result[k]);
    }
}
void initQueries(long** queries)
{
    queries[0][0] = 10;
    queries[0][1] = 6;
    queries[0][2] = 10;
    queries[1][0] = 1023;
    queries[1][1] = 7;
    queries[1][2] = 7;
    queries[2][0] = 33;
    queries[2][1] = 5;
    queries[2][2] = 8;
    queries[3][0] = 182;
    queries[3][1] = 5;
    queries[3][2] = 10;
    queries[4][0] = 181;
    queries[4][1] = 1;
    queries[4][2] = 13;
    queries[5][0] = 5;
    queries[5][1] = 10;
    queries[5][2] = 15;
    queries[6][0] = 99;
    queries[6][1] = 8;
    queries[6][2] = 9;
    queries[7][0] = 33;
    queries[7][1] = 10;
    queries[7][2] = 14;
}

