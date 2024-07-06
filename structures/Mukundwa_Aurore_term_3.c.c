
#include <stdio.h>
#include <string.h>
#include <ctype.h>


struct animal {
    int age;
    char name[30];
    char gender[10];
    char place[50];
};


void getValues(struct animal *a, const char *type);
void outputValues(struct animal a);

int main() {
    
    struct animal dog, cow;
    
    
    printf("ENTER DETAILS FOR DOG:\n");
    getValues(&dog, "dog");
    
  
    printf("\nENTER DETAILS FOR A COW:\n");
    getValues(&cow, "cow");
    
   
    printf("\nDetails for dog:\n");
    outputValues(dog);
    
    
    printf("\nDetails for cow:\n");
    outputValues(cow);
    
    return 0;
}


void getValues(struct animal *a, const char *type) {
    while (1) {
        printf("Enter age: ");
        if (scanf("%d", &a->age) != 1) {
            printf("Invalid input. Age must be an integer. Please try again.\n");
            while (getchar() != '\n'); 
            continue;
        }
        if (a->age <= 0) {
            printf("Invalid input. Age must be a positive integer. Please try again.\n");
            continue;
        }
        break;
    }
    getchar(); 
    
    printf("Enter name: ");
    fgets(a->name, sizeof(a->name), stdin);
    a->name[strcspn(a->name, "\n")] = '\0'; 
    
    while (1) {
        printf("Enter gender (F/M): ");
        fgets(a->gender, sizeof(a->gender), stdin);
        a->gender[strcspn(a->gender, "\n")] = '\0'; 
        if (strlen(a->gender) != 1 || (toupper(a->gender[0]) != 'F' && toupper(a->gender[0]) != 'M')) {
            printf("Invalid input. Gender must be 'F' or 'M'. Please try again.\n");
            continue;
        }
        break;
    }

    printf("Enter place: ");
    fgets(a->place, sizeof(a->place), stdin);
    a->place[strcspn(a->place, "\n")] = '\0'; 
}


void outputValues(struct animal a) {
    printf("Age: %d\n", a.age);
    printf("Name: %s\n", a.name);
    printf("Gender: %s\n", a.gender);
    printf("Place: %s\n", a.place);
}