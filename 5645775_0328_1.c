#include <stdio.h>

// 다항식 구조체 정의
typedef struct {
    int degree;       // 다항식의 최고 차수 저장
    float coef[100];    // 다항식의 계수 배열 저장
} polynomial;

void print_poly(polynomial p);
polynomial poly_mult(polynomial a, polynomial b);

int main(void) {
    polynomial a = { 3, {1.0, 2.0, 3.0, 4.0} };   //다항식의 최고 차수와 계수 배열을 적음
    polynomial b = { 2, {8.0, 2.0, 3.0} };
    polynomial c;

    print_poly(a);
    print_poly(b);

    c = poly_mult(a, b);   //곱셈 후 c에 할당
    printf("\n");
    print_poly(c);

    return 0;
}

void print_poly(polynomial p) {       //다항식을 출력
    printf("%3.1fx^%d", p.coef[p.degree], p.degree);
    for (int i = p.degree - 1; i >= 0; i--) {
        if (p.coef[i] != 0.0) {
            if (i == 0)
                printf(" + %3.1f", p.coef[i]);
            else
                printf(" + %3.1fx^%d", p.coef[i], i);
        }
    }
    printf("\n");
}

polynomial poly_mult(polynomial a, polynomial b) {    //다항식 곱셈 결과 반환
    polynomial result = { a.degree + b.degree, {0} }; 

    for (int i = 0; i <= a.degree; i++) {
        for (int j = 0; j <= b.degree; j++) {
            result.coef[i + j] += a.coef[i] * b.coef[j];
        }
    }

    return result;
}