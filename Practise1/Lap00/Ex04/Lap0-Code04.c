#include <stdio.h>

int score = 0;
int A = 80;
int main()
{
    if(score < A)
    {
    printf("study the section\n");
    score = 0;
    printf("work\n");
    score = 20;
    if(score < A)
    {
        printf("test\n");
        score = 80;
        printf("score is %d\n", score);
    }
    if(score == A)
    {
        printf("You have A now\n");
    }
    }
}
