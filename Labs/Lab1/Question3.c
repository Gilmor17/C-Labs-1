include <stdio.h>

int main(void)
{
    int dogs, cats, total_pets;

    printf("How many dogs do you have?\n");
    scanf("%d", &dogs);

    printf("How many cats do you have?\n");
    scanf("%d", &cats);

    total_pets = dogs + cats;

    printf("So you have %d dog(s) and %d cat(s)!\n", dogs, cats);
    printf("In total, you have %d pet(s)!\n", total_pets);

    return 0;
}