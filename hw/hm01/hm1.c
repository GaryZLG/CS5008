
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    int id;
    char *name;
    float gpa;
} student_t;

student_t *makeStudent(int id, char *name, float gpa)
{
    student_t *s = (student_t *)malloc(sizeof(student_t));
    if (s == NULL)
    {
        return NULL;
    }
    s->id = id;
    s->name = (char *)malloc(sizeof(char) * 20);
    if (s->name == NULL)
    {
        free(s);
        return NULL;
    }
    strcpy(s->name, name);
    // Check gpa
    if (gpa > 4.0)
    {
        printf("GPA is greater than 4.0\n");
        s->gpa = 0;
    }
    else
    {
        s->gpa = gpa;
    }

    return s;
}

void freeStudent(student_t *s)
{
    if (s == NULL)
    {
        return;
    }
    if (s->name != NULL)
    {
        free(s->name);
    }
    free(s);
}

void alterRecord(student_t *s)
{
    if (s == NULL)
    {
        printf("No information of this student.\n");
        return;
    }
    while (1)
    {
        printf("1. ID\n");
        printf("2. Name\n");
        printf("3. GPA\n");
        printf("4. Exit alter and print the student altered info\n");
        printf("Please selecet the information you need to alter:\n");

        int select;
        scanf("%d", &select);

        if (select == 4)
        {
            break;
        }

        switch (select)
        {
        case 1:
        {
            int newID;
            printf("Please input the new ID:");
            scanf("%d", &newID);
            s->id = newID;
            printf("\n");
            break;
        }
        case 2:
        {
            char *newName = (char *)malloc(sizeof(char) * 20);
            printf("Please input the new name:");
            scanf("%s", newName);
            if (newName == NULL)
            {
                printf("New name is NULL");
                return;
            }
            strcpy(s->name, newName);
            free(newName);
            printf("\n");
            break;
        }
        case 3:
        {
            float newGPA;
            printf("Please input the new gpa:");
            scanf("%f", &newGPA);
            if (newGPA > 4.0)
            {
                printf("GPA is greater than 4.0");
                s->gpa = 0;
            }
            else
            {
                s->gpa = newGPA;
            }
            printf("\n");
            break;
        }
        default:
            break;
        }
    }
}

void printStudent(student_t *s)
{
    if (s == NULL)
    {
        printf("No information of this student.\n");
        return;
    }
    else if (s->name == NULL)
    {
        printf("Missing student's name.");
        printf("Student ID:%d, GPA:%f\n", s->id, s->gpa);
        return;
    }

    printf("Student ID:%d, Name:%s, GPA:%f\n", s->id, s->name, s->gpa);
}

int main()
{
    printf("-----------Original info of Student1----------\n");
    student_t *s1 = makeStudent(1001, "Mary", 3.5);
    printStudent(s1);
    alterRecord(s1);
    printf("-----------Altered info of Student1----------\n");
    printStudent(s1);

    printf("\n");
    printf("-----------Original info of Student2----------\n");
    student_t *s2 = makeStudent(1002, "Jack", 4.1);
    printStudent(s2);

    // free the heap memory
    freeStudent(s1);
    freeStudent(s2);
    return 0;
}