#include "get_localtime.h"
#include <stdio.h>
#include <time.h>

/******************************************************************************
* 名称：get_localtime
* 説明：C言語標準関数でローカル日時を取得し、フォーマットしてバッファに格納する
* 引数：バッファポインタ
* 戻値：無し
* 作成：2025.06.13 (Shift_JIS)
******************************************************************************/
void get_localtime(char *buffer) {

    // Unixtimeを取得(戻り値を取得するにはNULLを指定)
    time_t t = time(NULL);

    // ローカルタイムゾーンに修正し、tm構造体へ取得
    struct tm *local_time = localtime(&t);
    
    // tm構造体メンバを変数に取得
    int year = local_time->tm_year + 1900;
    int mon  = local_time->tm_mon + 1;
    int day  = local_time->tm_mday;
    int hour = local_time->tm_hour;
    int min  = local_time->tm_min;
    int sec  = local_time->tm_sec;

    // 日時フォーマット文字列19文字を作成し、バッファに格納
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