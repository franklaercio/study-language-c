#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct person {
    char name[21];
    int age;
    char gender;
} Person;

struct person peaple[20];

void create(int personId, Person person) {
    peaple[personId] = person;
}

void delete(Person person) {
    for (int i = 0; i < 20; i++){
      bool isNameEquals = true;
      
      for(int j = 0; j < strlen(peaple[i].name); j++) {
        if(peaple[i].name[j] != person.name[j]) {
          isNameEquals = false;
          break;
        }  
      }

      if (isNameEquals && peaple[i].age == person.age && peaple[i].gender == person.gender) {
        peaple[i].age = -1;
      }
    }  
}

void show() {
    for (int i = 0; i < 20; i++){
        if(peaple[i].age > 0) {
            printf("%s,%i,%c\n", peaple[i].name, peaple[i].age, peaple[i].gender);
        }
    }
}

int main() {
    int personId = 0;

    while(1) {
        char instruction[100];
        char values[256];
        Person person;
        fgets(instruction, 256, stdin);

        if(instruction[1] == 'n') {
            char name[256];
            int age;
            char gender;
            fgets(values, 256, stdin);
            values[strcspn(values, "\n")] = 0;
            sscanf(values, "%[^,],%d,%c", name, &age, &gender);

            Person person = {.age = age, .gender = gender};
            strcpy(person.name, name);

            create(personId, person);
            personId++;
        }else if(instruction[0] == 'd') {
            char name[256];
            int age;
            char gender;
            fgets(values, 256, stdin);
            values[strcspn(values, "\n")] = 0;
            sscanf(values, "%[^,],%d,%c", name, &age, &gender);

            Person person = {.age = age, .gender = gender};
            strcpy(person.name, name);
            delete(person);
        }else {
            show();
            break;
        }
    }

    return 0;
}

