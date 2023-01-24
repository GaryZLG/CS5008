// Calculate area of shapes : rectangle, circle, square using structures and pointers.

// Hint: Use structure to define the variable parameters.
// Use pointers to pass parameters to the function (call by reference).

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct circle
{
    double radius;
};

struct rectangle
{
    double length;
    double width;
};

struct square
{
    double length;
};

void areaOfCircle(struct circle *c)
{
    double r = M_PI * pow(c->radius, 2.0);
    printf("The area of the circle is: %f\n", r);
}

void areaOfRectangle(struct rectangle *r)
{
    double a = r->length * r->width;
    printf("The area of the rectangle is: %f\n", a);
}

void areaOfSquare(struct square *s)
{
    double a = s->length * s->length;
    printf("The area of the square is: %f\n", a);
}

int main()
{
    while (1)
    {
        int select;
        printf("Please select the shape you want to calculate:\n");
        printf("1. Circle\n2. Rectangle\n3. Square\n4. Eixt\n");

        scanf("%d", &select);
        switch (select)
        {
        case 1:
        {
            struct circle c;
            printf("Please input the radius:\n");
            scanf("%lf", &c.radius);
            areaOfCircle(&c);
            printf("\n");
            break;
        }
        case 2:
        {
            struct rectangle r;
            printf("Please input the length:\n");
            scanf("%lf", &r.length);
            printf("Please input the width:\n");
            scanf("%lf", &r.width);
            areaOfRectangle(&r);
            printf("\n");
            break;
        }
        case 3:
        {
            struct square s;
            printf("Please input the length:\n");
            scanf("%lf", &s.length);
            areaOfSquare(&s);
            printf("\n");
            break;
        }
        case 4:
            exit(0);
        default:
            printf("Invalid input!");
            break;
        }
    }

    return 0;
}