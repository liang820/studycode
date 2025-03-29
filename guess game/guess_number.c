#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define DEFAULT_MIN 1
#define DEFAULT_MAX 100
#define HIGHSCORE_FILE "highscore.txt"

int getHighScore() {
    FILE *file = fopen(HIGHSCORE_FILE, "r");
    if (file == NULL) return 0;
    
    int highscore;
    fscanf(file, "%d", &highscore);
    fclose(file);
    return highscore;
}

void saveHighScore(int score) {
    FILE *file = fopen(HIGHSCORE_FILE, "w");
    if (file == NULL) return;
    
    fprintf(file, "%d", score);
    fclose(file);
}

int main() {
    srand(time(0));
    int min = DEFAULT_MIN, max = DEFAULT_MAX;
    int highscore = getHighScore();
    
    printf("欢迎来到猜数字游戏！\n");
    printf("当前最佳成绩: %d次\n", highscore);
    printf("请选择难度(1-简单 2-中等 3-困难): ");
    
    int difficulty;
    scanf("%d", &difficulty);
    
    switch(difficulty) {
        case 1: max = 50; break;
        case 2: max = 100; break;
        case 3: max = 200; break;
        default: printf("无效输入，使用默认难度(1-100)\n");
    }
    
    int target = rand() % (max - min + 1) + min;
    int guess, attempts = 0;
    bool correct = false;
    
    printf("我已经想好了一个%d到%d之间的数字，开始猜吧！\n", min, max);
    
    while (!correct) {
        printf("你的猜测: ");
        scanf("%d", &guess);
        attempts++;
        
        if (guess < target) {
            printf("小了！\n");
        } else if (guess > target) {
            printf("大了！\n");
        } else {
            correct = true;
            printf("恭喜你猜对了！用了%d次尝试。\n", attempts);
            
            if (highscore == 0 || attempts < highscore) {
                printf("新纪录！\n");
                saveHighScore(attempts);
            }
        }
    }
    
    return 0;
}