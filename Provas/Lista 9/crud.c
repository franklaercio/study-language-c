#include <stdio.h>
#include <string.h>

struct person {
    char name[21];
    char age[3];
    char gender;
};

struct person peaple[20];

void create(int personId, char values[256]) {
    char typedName[256];
    char typedGender;
    char typedAge[3];
    int position, index = 0;

    for (int i = 0; i < strlen(values); i++){
        if(values[i] == ',') {
            position = i;

            for (int j = 0; j < position; j++){
                typedName[j] = values[j];
            }
            
            typedName[position] = '\0';
            typedAge[0] = values[position + 1];
            typedAge[1] = values[position + 2];
            typedAge[2] = '\0';
            typedGender = values[position + 4];

            strcpy(peaple[personId].name, typedName);
            strcpy(peaple[personId].age, typedAge);
            peaple[personId].gender = typedGender;

            break;
        }
    }
}

void delete(char typedPerson[256]) {
    for (int i = 0; i < strlen(typedPerson); i++){
      if(typedPerson[i] == ',') {
        for (int i = 0; i < 20; i++){
          if (peaple[i].name[0] == typedPerson[0] && peaple[i].name[1] == typedPerson[1] && peaple[i].name[2] == typedPerson[2]) {
            peaple[i].age[0] = 'X';
            peaple[i].age[1] = 'X';
          }
        }
      }  
    }  
}

void show() {
    for (int i = 0; i < 20; i++){
        if(peaple[i].age[0] != 'X' && strlen(peaple[i].age) > 0) {
            printf("%s,%s,%c\n", peaple[i].name, peaple[i].age, peaple[i].gender);
        }
    }
}

int main() {
    int personId = 0;

    while(1) {
        char instruction[100];
        char values[256];

        fgets(instruction, 256, stdin);

        if(instruction[1] == 'n') {
            fgets(values, 256, stdin);
            values[strcspn(values, "\n")] = 0;

            //printf("%s\n", values);

            create(personId, values);
            personId++;
        }else if(instruction[0] == 'd') {
            char typedPerson[256];
            scanf("%s[^,]", typedPerson);
            delete(typedPerson);
        }else {
            show();
            break;
        }
    }

    return 0;
}