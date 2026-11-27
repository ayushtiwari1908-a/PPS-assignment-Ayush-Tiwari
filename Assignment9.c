#include <stdio.h>

void calculateDistance(float *left, float *right,
                       float *circumference, float *distance)
{
    float avgRotations;

    avgRotations = (*left + *right) / 2;

    *distance = avgRotations * (*circumference);
}

int main()
{
    float left, right, circumference, distance;

    printf("Enter left wheel rotations: ");
    scanf("%f", &left);

    printf("Enter right wheel rotations: ");
    scanf("%f", &right);

    printf("Enter wheel circumference: ");
    scanf("%f", &circumference);

    calculateDistance(&left, &right, &circumference, &distance);

    printf("Distance travelled by robot = %.2f", distance);

    return 0;
}
ye chalega?
