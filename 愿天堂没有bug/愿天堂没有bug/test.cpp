#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void write_file() 
{
    FILE* file = NULL;
    file = fopen("teacher.txt", "a+");
    if (file == NULL)
    {
        printf("δ�ɹ����ļ���\n");
        return;
        //exit(0);
    }
    else
    {
        int k, len = 0;
        int c = 0;
        fputc('x', file);
        fputc('x', file);
        fputc('x', file);
        fputc('x', file);
        fputc('x', file);
        return;
        while ((k = fgetc(file)) != EOF)
        {
            if (k == '\n') 
            {
                if (c != 1)
                    len++;
            }
        }
        c++;
    }
    fclose(file);//�ر��ļ�
}
int main()
{
    write_file();
    return 0;
}
//void link_save() {
//    if ((file = fopen("teacher.txt", "w")) == NULL) {
//        printf("�ļ�����ʧ�ܣ�\n");
//        exit(1);
//    }
//    fclose(file);
//}