#include "load_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/******************************************************************************
* ���́Fload_file
* �����F�w�肳�ꂽ�t�@�C����ǂݍ��݁A�������Ɋi�[���ă|�C���^��Ԃ�
* �����F�t�@�C���p�X
* �ߒl�F[����]�ǂݍ��񂾃t�@�C���̃������|�C���^ [�ُ�]NULL
* �쐬�F2025.06.14 (Shift_JIS)
******************************************************************************/
char *load_file(const char *filepath) {

    char buf[1024];
    size_t sumbyte = 0;

    FILE *fp = fopen(filepath, "r");
    if (!fp) {
        fprintf(stderr, "Error: �t�@�C��:%s ���I�[�v���ł��܂���.\n", filepath);
        perror("fopen");
        return NULL;
    }

    // �t�@�C���T�C�Y���擾
    fseek(fp, 0, SEEK_END);
    size_t fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    printf("�t�@�C���ǂݍ��݂��J�n���܂�...\n");
    printf("���̓t�@�C��: %s\n", filepath);
    printf("���̓o�C�g��: %ld Byte\n", fsize);

    // �ǂݍ��݃������m��(+1��calloc��0�������ɂ��NULL�I�[�S�ۂ̂���)
    char *filemem = (char *)calloc(fsize + 1, sizeof(char));

    // �������擪���疖���ɍs��ǋL
    while (fgets(buf, sizeof(buf), fp) != NULL) {
        strcpy(filemem + sumbyte, buf);
        sumbyte += strlen(buf);
    }

    fclose(fp);
    printf("�t�@�C���ǂݍ��݂��������܂���.�������|�C���^��ԋp���܂�.\n");
    return filemem;

}

void main(int argc, char **argv) {
    char *content = NULL;
    if (argc == 2) {
        content = load_file(argv[1]);
        while (*content != '\0') {
            putchar(*content++);
        }
    }
}