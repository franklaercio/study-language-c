#include <stdio.h>

int main() {
    float m1;
    float c1;

    float m2;
    float c2;

    float px;
    float py;

    scanf("%f", &m1);
    scanf("%f", &c1);
    scanf("%f", &m2);
    scanf("%f", &c2);

    if (m1 == m2) {
        if (c1 == c2) {
            printf("Retas Colineares!");
        }else {
            printf("Retas paralelas!");
        }
    }else {
        px = (c1-c2)/(m2-m1);
        py = m1*px + c1;
        printf("Interseção Pi = (%.1f, %.1f)", px, py);
    }

    return 0;
}
    
