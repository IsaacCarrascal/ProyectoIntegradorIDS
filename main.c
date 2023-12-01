#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FileName "Scenes.txt"
#define MaxScenes 100
#define MAX_LINE_LENGTH 1000

struct Scene {
    char name[MAX_LINE_LENGTH];
    char description[MAX_LINE_LENGTH];
    char option[MAX_LINE_LENGTH];
    int scenenumber;
    int paths[MaxScenes];
};

void game(struct Scene scenes[], int* scene, int count);
int main(void) {
  struct Scene scenes[MaxScenes];
  int count=0, scene, exit=0;

  FILE *file_pointer;

    file_pointer = fopen("Scenes.txt", "r");

    if (file_pointer == NULL) {
        printf("Error al abrir el archivo.");
      system("Pause");
    }
    else{

    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file_pointer) != NULL && count < MaxScenes) {
        char *token;
        char *delimiter = "//";
        char *context;

        token = strtok_r(line, delimiter, &context);

        if (token != NULL) {
            strcpy(scenes[count].name, token);

            token = strtok_r(NULL, delimiter, &context);
            if (token != NULL) {
                strcpy(scenes[count].description, token);

                token = strtok_r(NULL, delimiter, &context);
                if (token != NULL) {
                    strcpy(scenes[count].option, token);
                    if (token != NULL) {
                        for (int i = 0; i < MaxScenes; ++i) {
                            if (token != NULL) {
                                scenes[count].paths[i] = atoi(token);
                                token = strtok_r(NULL, delimiter, &context);
                            } else {
                                scenes[count].paths[i] = 0;
                            }
                }
            }
        }
        scenes[count].scenenumber=count;
        count++;
    }
        }}
    fclose(file_pointer);

  while(exit!=2){
    scene=1;
    system("cls");
    printf("Bienvenido al juego\n");
    printf("Escribe el numero de la opcion que deseas ejecutar\n");
    printf("1. Jugar\n");
    printf("2. Salir\n");
    scanf("%d", &exit);
    if(exit==1){
      while(scene!=-1){
      game(scenes, &scene, count);
      }
      printf("Juego terminado\n");
      system("pause");
    }else if(exit!=2){
      printf("Opcion no valida\n");
      system("pause");
  }
  }
      printf("Hasta luego! :)");
      system("pause");
    }
  return 0;
}

void game(struct Scene scenes[], int* scene, int count){
  int choice=0, options=0;
  struct Scene PosibleScenes[MaxScenes];
  system("cls");
  printf("Escena %d: %s\n", scenes[*scene].scenenumber,scenes[*scene].name);
  printf("%s\n",scenes[*scene].description);
  int i=1;
  while(scenes[*scene].paths[i]!=0){
    PosibleScenes[options]=scenes[scenes[*scene].paths[i]];
    options++;
    i++;
  }

  if(options!=0){
  for(int i=0;i<options;i++){
    printf("%d. %s\n",i+1,PosibleScenes[i].option);}
    while(choice<1||choice>options){
  printf("Elija una opcion: ");
  scanf("%d",&choice);
  if(choice>0 && choice<=options){
    *scene=PosibleScenes[choice-1].scenenumber;}
  else{
    printf("Opcion no valida.\n");
    system("pause");
  }
  }
  }else{
    *scene=-1;
  }
}
