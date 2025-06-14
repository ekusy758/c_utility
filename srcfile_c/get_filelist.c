#include "get_filelist.h"
#include <stdio.h>
#include <string.h>
#include <dirent.h>

/******************************************************************************
* ���́Fget_filelist
* �����F�w�肳�ꂽ�p�X�̃t�@�C�����E�t�H���_�����擾����(�ő�255�����܂�)
* �����F�o�b�t�@2�����z��, �t�H���_�p�X
* �ߒl�F[����]�擾�� [�ُ�]-1
* �쐬�F2025.06.14 (Shift_JIS)
******************************************************************************/
int get_filelist(char filelist[][256], const char *basepath) {

    // �f�B���N�g���I�[�v��(DIR�\����)
    DIR *dir = opendir(basepath);
    if (dir == NULL) {
        fprintf(stderr, "Error: ��t�H���_:%s ���I�[�v���ł��܂���.\n", basepath);
        return -1;
    }

    // dirent�\���̃|�C���^(�̈��readdir�֐��Ŋm�ۂ����)
    struct dirent *entry;
    int count = 0;

    // �t�@�C�����E�t�H���_�����擾
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        strncpy(filelist[count], entry->d_name, 255);
        filelist[count][255] = '\0';
        count++;
    }

    closedir(dir);
    return count;

}

void main(int argc, char **argv) {
    char files[500][256] = {0};
    int num = 0;
    if (argc == 2) {
        num = get_filelist(files, argv[1]);
    }
    for (int i = 0; i < num; i++) {
        printf("%s\n", files[i]);
    }
}