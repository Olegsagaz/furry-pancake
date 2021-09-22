 #include <stdio.h>
 #include <unistd.h>

void my_scanfstr(){ 
    char name[60];
        printf("Введите ваше имя \n");
        printf("Сюда: ");
        scanf("%s", name);
        sleep (3);
        printf("Ваше имя %s  \n", name);          
}

int main()
{
    my_scanfstr();
    return 0;
}