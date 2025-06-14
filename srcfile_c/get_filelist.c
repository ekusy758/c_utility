#include "get_filelist.h"
#include <stdio.h>
#include <string.h>
#include <dirent.h>

/******************************************************************************
* 名称：get_filelist
* 説明：指定されたパスのファイル名・フォルダ名を取得する(最大255文字まで)
* 引数：バッファ2次元配列, フォルダパス
* 戻値：[正常]取得数 [異常]-1
* 作成：2025.06.14 (Shift_JIS)
******************************************************************************/
int get_filelist(char filelist[][256], const char *basepath) {

    // ディレクトリオープン(DIR構造体)
    DIR *dir = opendir(basepath);
    if (dir == NULL) {
        fprintf(stderr, "Error: 基準フォルダ:%s をオープンできません.\n", basepath);
        return -1;
    }

    // dirent構造体ポインタ(領域はreaddir関数で確保される)
    struct dirent *entry;
    int count = 0;

    // ファイル名・フォルダ名を取得
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