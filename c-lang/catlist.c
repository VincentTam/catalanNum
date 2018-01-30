#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <gmp.h>

void catalan(mpz_t cn, int n);
void quit(); /* write error message and quit */

int main() {
    /* "Correct" way to get user input:
     * https://stackoverflow.com/a/7832033/3184351
     */
    int max = 20;
    char* input_str = (char*) malloc(max); /* allocate buffer */
    if (input_str == 0) quit();

    printf("List Catalan no. up to: ");

    while (1) { /* skip leading whitespace */
        int c = getchar();
        if (c == EOF) break; /* end of file */
        if (!isspace(c)) {
             ungetc(c, stdin);
             break;
        }
    }

    /* Compute time used: https://stackoverflow.com/a/5844605/3184351 */
    time_t t1, t2;
    t1 = time(0);

    int i = 0;
    while (1) {
        int c = getchar();
        if (isspace(c) || c == EOF) { /* at end, add terminating zero */
            input_str[i] = 0;
            break;
        }
        input_str[i] = c;
        if (i == max - 1) { /* buffer full */
            max += max;
            /* get a new and larger buffer */
            input_str = (char*) realloc(input_str, max); 
            if (input_str == 0) quit();
        }
        i++;
    }

    printf("User input: %s\n", input_str);
    /* "Correct" way to get user input end */

    /* Convert input_str into long int:
     * https://stackoverflow.com/a/37044102/3184351
     */
    long N = 150;
    char *Nptr = NULL;
    N = strtol(input_str, &Nptr, 10);
    if (*Nptr == '\0') {

        mpz_t cn;
        mpz_init(cn); // init and set to 0

        for (i = 1; i <= N; i++) {
            catalan(cn, i);
            gmp_printf("%d: %Zd\n", i, cn);
            mpz_set_ui(cn, 0);
        }

        t2 = time(0);
        printf("\n Time elasped: %f seconds\n", difftime(t2, t1));

        return 0; // program exit normally
    }
}

void catalan(mpz_t cn, int n) {
    if (n == 0) {
        mpz_set_ui(cn, 1);
        return;
    }

    mpz_t reccur;
    mpz_init(reccur);
    catalan(reccur, n-1);
    mpz_mul_ui(cn, reccur, 2*(2*n-1));
    mpz_tdiv_q_ui(cn, cn, n+1);
}

void quit() /* write error message and quit */
{
    fprintf(stderr, "memory exhausted\n");
    exit(1);
}
