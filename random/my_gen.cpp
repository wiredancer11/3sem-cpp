#include <cstdlib>
int gen_rand(int a, int b) {
    return ((int)(rand() / (1.0+RAND_MAX)*(b-a+1)) + a);
}

int gen_rand_mod(int a, int b) {
    return rand()%(b-a+1) + a;
}