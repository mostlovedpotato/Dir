#include<stdio.h>

/// <summary>
/// Sum Function
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns>Sum of Two numbers</returns>
/// int(int,int)

int __cdecl sum(int a, int b) {
	return a + b;
}


/// <summary>
/// Squared Difference
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns>Integer</returns>
/// int(int,int)
int __cdecl square_diff(int a, int b) {
	return (a + b) * (a - b);
}

// Function i_ii_ptr
// it return int and take two int's
// int i_ii_ptr(int, int);
// 
// 
//int* i_ii_ptr(int, int);
// Function that returns int * 
// takes two int's

// int (*i_ii_ptr)(int,int);
// now it is function pointer
// which points to the function 
// and return int while taking int and int

// Now it is a type 
// a function pointer
// this points to a function that return int
// takes two int'
typedef int (*i_ii_ptr)(int, int);

int call(i_ii_ptr func, int a, int b) {
	return func(a, b);
}

void test_i_ii_ptr() {
	printf("3+2 = %d\n", call(sum, 3, 2));
	printf("(3+2)(3-2) = %d\n", call(square_diff, 3, 2));
}

/// <summary>
/// Product oF Numbers
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns>Double Value</returns>
/// double(double,double)

double pro(double a, double b) {
	return a * b;
}

double square_pro(double a, double b) {
	return pro(a, b) * pro(a, b);
}

typedef double (*pro_ptr)(double, double);

double call_prod(pro_ptr func, double a, double b) {
	return func(a, b);
}

double call_prod2(double (*func)(double,double), double a, double b) {
	return func(a, b);
}


void test_pro() {
	double d1 = call_prod(pro, 2, 3);
	double d2 = call_prod2(square_pro, 2, 3);

	printf("2 * 3 = %lg\n", d1);
	printf("2 * 3 * 2 * 3 = %lg\n", d2);
}

void typedef_conc() {
	// int is type 
	// age_t is an instance
	// int age_t;
	
	// now age_t is type - a type alias
	// typedef int age_t;

	// func_t is an instance of a function pointer
	// double (*func_t)(double, double);

	// func_t is a type - a type alias
	// typedef double(*func(double, double));
}

// In the other __stdcall calling convention 
// you have to have __stdcall in all the functions calling

double __stdcall sum_product(double a, double b) {
	return (a + b) * (a + b);
}

double __stdcall product_sum(double a, double b) {
	return (a * b) + (a * b);
}

typedef double(__stdcall* std_func_ptr)(double, double);

double call_std_func(std_func_ptr func, double a, double b) {
	return func(a, b);
}

double call_std_func2(double(__stdcall* func)(double, double), double a, double b) {
	return func(a, b);
}

void test_call_std_func() {
	double d1 = call_std_func(sum_product, 2, 3);
	double d2 = call_std_func2(product_sum, 2, 3);

	printf("d1 = %lg\n", d1);
	printf("d2 = %lg\n", d2);
}

// __cdecl is default calling convention 
// it is auto if not called


int main() {
	test_i_ii_ptr();
	test_call_std_func();
}