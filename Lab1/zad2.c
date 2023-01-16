#include <stdio.h>
#include <stdlib.h>

typedef char const * (*PTRFUN)();

PTRFUN* unary_functions;
PTRFUN* linear_functions;
PTRFUN* square_functions;

typedef struct Unary_Function {
    int lower_bound;
    int upper_bound;
    PTRFUN* table;
} Unary_Function;

Unary_Function* construct_unary(int lb, int ub) {
    Unary_Function* func = malloc(sizeof(Unary_Function));
    func->table = unary_functions;
    func->lower_bound = lb;
    func->upper_bound = ub;
    return func;
}

typedef double (*PTRFUN_unary)(Unary_Function*, double);

void tabulate(Unary_Function* func) {
    PTRFUN_unary value_at = (PTRFUN_unary) func->table[0];
    for (int x = func->lower_bound; x <= func->upper_bound; x++) {
        printf("f(%d)=%lf\n", x, value_at(func, x));
    }
}

double negative_value_at(Unary_Function* func, double x) {
    PTRFUN_unary value_at = (PTRFUN_unary) func->table[0];
    return -value_at(func, x);
}

int same_functions_for_ints(Unary_Function* f1, Unary_Function* f2, double tolerance) {
    PTRFUN_unary value_at_f1 = (PTRFUN_unary) f1->table[0];
    PTRFUN_unary value_at_f2 = (PTRFUN_unary) f2->table[0];
    if (f1->upper_bound != f2->upper_bound || f1->lower_bound != f2->lower_bound) return 0;
    for (int x = f1->lower_bound; x <= f1->upper_bound; x++) {
        double delta = value_at_f1(f1, x) - value_at_f2(f2, x);
        if (delta < 0) delta = -delta;
        if (delta > tolerance) return 0;
    }
    return 1;
}


typedef struct Square {
    Unary_Function parent;
} Square;

Square* construct_square(int lb, int ub) {
    Square* func = (Square*) construct_unary(lb, ub);
    func->parent.table = square_functions;
    return func;
}

double value_at_square(double x) {
    return x*x;
}

typedef struct Linear {
    Unary_Function parent;
    double a;
    double b;
} Linear;

Linear* construct_linear(int lb, int ub, double a, double b) {
    Linear* func = (Linear*) construct_unary(lb, ub);
    func->a = a;
    func->b = b;
    func->parent.table = linear_functions;
    return func;
}

double value_at_linear(struct Linear* func, double x) {
    return func->a * x + func->b;
}


int main() {
    unary_functions = malloc(sizeof(PTRFUN));
    unary_functions[0] = 0;
    unary_functions[1] = (PTRFUN) negative_value_at;

    square_functions = malloc(2* sizeof(PTRFUN));
    square_functions[0] = (PTRFUN) value_at_square;
    square_functions[1] = (PTRFUN) negative_value_at;

    linear_functions = malloc(2* sizeof(PTRFUN));
    linear_functions[0] = (PTRFUN) value_at_linear;
    linear_functions[1] = (PTRFUN) negative_value_at;

    Unary_Function* f1 = (Unary_Function*) construct_square(-2, 2);
    tabulate(f1);
    Unary_Function* f2 = (Unary_Function*) construct_linear(-2, 2, 5, -2);
    tabulate(f2);
    printf("f1==f2: %s\n", same_functions_for_ints(f1, f2, 1E-6) ? "DA" : "NE");
    printf("neg_val f2(1) = %lf\n", negative_value_at(f2, 1.0));
    free(f1);
    free(f2);
    return 0;
}