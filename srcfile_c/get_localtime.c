#include "get_localtime.h"
#include <stdio.h>
#include <time.h>

/******************************************************************************
* ���́Fget_localtime
* �����FC����W���֐��Ń��[�J���������擾���A�t�H�[�}�b�g���ăo�b�t�@�Ɋi�[����
* �����F�o�b�t�@�|�C���^
* �ߒl�F����
* �쐬�F2025.06.13 (Shift_JIS)
******************************************************************************/
void get_localtime(char *buffer) {

    // Unixtime���擾(�߂�l���擾����ɂ�NULL���w��)
    time_t t = time(NULL);

    // ���[�J���^�C���]�[���ɏC�����Atm�\���̂֎擾
    struct tm *local_time = localtime(&t);
    
    // tm�\���̃����o��ϐ��Ɏ擾
    int year = local_time->tm_year + 1900;
    int mon  = local_time->tm_mon + 1;
    int day  = local_time->tm_mday;
    int hour = local_time->tm_hour;
    int min  = local_time->tm_min;
    int sec  = local_time->tm_sec;

    // �����t�H�[�}�b�g������19�������쐬���A�o�b�t�@�Ɋi�[
    snprintf(
        buffer, 19, "%04d/%02d/%02d %02d:%02d:%02d", 
        year, mon, day, hour, min, sec
    );

    buffer[19] = '\0';

}

void main() {
    char buffer[20];
    get_localtime(buffer);
    printf("%s\n", buffer);
}