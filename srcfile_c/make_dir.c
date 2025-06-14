#include "make_dir.h"
#include <sys/stat.h>
#include <stdio.h>

/******************************************************************************
* 名称：make_dir
* 説明：指定されたパスにフォルダを作成する
* 引数：フォルダパス
* 戻値：無し
* 作成：2025.06.13 (Shift_JIS)
******************************************************************************/
void make_dir(const char *dirpath) {

    // stat関数へ渡すstat構造体変数(領域は呼び出し元で確保)
    struct stat buffer;

    if (stat(dirpath, &buffer) == 0) {
        printf("フォルダ:%s は既に存在します.\n", dirpath);
        return;
    }

    if (mkdir(dirpath) == 0) {
        printf("フォルダ:%s を作成しました.\n", dirpath);
    } else {
        fprintf(stderr, "Error: フォルダ:%s の作成に失敗しました.\n", dirpath);
    }

}

void main(int argc, char **argv) {
    if (argc == 2) {
        make_dir(argv[1]);
    } 
}