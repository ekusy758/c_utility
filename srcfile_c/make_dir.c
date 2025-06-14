#include "make_dir.h"
#include <sys/stat.h>
#include <stdio.h>

/******************************************************************************
* ���́Fmake_dir
* �����F�w�肳�ꂽ�p�X�Ƀt�H���_���쐬����
* �����F�t�H���_�p�X
* �ߒl�F����
* �쐬�F2025.06.13 (Shift_JIS)
******************************************************************************/
void make_dir(const char *dirpath) {

    // stat�֐��֓n��stat�\���̕ϐ�(�̈�͌Ăяo�����Ŋm��)
    struct stat buffer;

    if (stat(dirpath, &buffer) == 0) {
        printf("�t�H���_:%s �͊��ɑ��݂��܂�.\n", dirpath);
        return;
    }

    if (mkdir(dirpath) == 0) {
        printf("�t�H���_:%s ���쐬���܂���.\n", dirpath);
    } else {
        fprintf(stderr, "Error: �t�H���_:%s �̍쐬�Ɏ��s���܂���.\n", dirpath);
    }

}

void main(int argc, char **argv) {
    if (argc == 2) {
        make_dir(argv[1]);
    } 
}