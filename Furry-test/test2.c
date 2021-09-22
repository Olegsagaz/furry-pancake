 #include <stdio.h>
 #include <unistd.h>

void my_scanfstr()
{ 
    char name[60];
        printf("Введите ваше имя \n");
        printf("Сюда: ");
        scanf("%s",  &name);
        sleep (2);
        //printf("Ваше имя %s  \n", name);
        if (name == "Марина"){
            printf("chto to");
        }            
}

int main()
{
    my_scanfstr();
    return 0;
}