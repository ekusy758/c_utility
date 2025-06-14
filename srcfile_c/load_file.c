#include "load_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/******************************************************************************
* 名称：load_file
* 説明：指定されたファイルを読み込み、メモリに格納してポインタを返す
* 引数：ファイルパス
* 戻値：[正常]読み込んだファイルのメモリポインタ [異常]NULL
* 作成：2025.06.14 (Shift_JIS)
******************************************************************************/
char *load_file(const char *filepath) {

    char buf[1024];
    size_t sumbyte = 0;

    FILE *fp = fopen(filepath, "r");
    if (!fp) {
        fprintf(stderr, "Error: ファイル:%s をオープンできません.\n", filepath);
        perror("fopen");
        return NULL;
    }

    // ファイルサイズを取得
    fseek(fp, 0, SEEK_END);
    size_t fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    printf("ファイル読み込みを開始します...\n");
    printf("入力ファイル: %s\n", filepath);
    printf("入力バイト数: %ld Byte\n", fsize);

    // 読み込みメモリ確保(+1はcallocの0初期化によるNULL終端担保のため)
    char *filemem = (char *)calloc(fsize + 1, sizeof(char));

    // メモリ先頭から末尾に行を追記
    while (fgets(buf, sizeof(buf), fp) != NULL) {
        strcpy(filemem + sumbyte, buf);
        sumbyte += strlen(buf);
    }

    fclose(fp);
    printf("ファイル読み込みが完了しました.メモリポインタを返却します.\n");
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