 #include <stdio.h>
 #include <unistd.h>
 #include <string.h>

void my_scanfstr() { 
    char name[60];
        printf("Введите ваше полное имя \n");
        printf("Сюда: ");

            scanf("%s", name);

            sleep (3);

        printf("Ваше имя %s  \n", name);
            sleep (3);
            if( strcmp(name, "Марина" ) == 0 )
                printf("Ты кисонька, и я тебя любить очень сильно! \n");

            else if ( strcmp(name, "Татьяна") == 0 )
                printf("Ты моя мама, и я тебя люблю ");                        
}

int main()
{
    my_scanfstr();
    return 0;
}