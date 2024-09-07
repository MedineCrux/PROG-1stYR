#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  // For _kbhit() and _getch()
#include <windows.h> // For Sleep()

#define WIDTH 20
#define HEIGHT 10

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point body[100];
    int length;
    int dx, dy;
} Snake;

typedef struct {
    Point pos;
    int is_food;
} Food;

void setup(Snake* snake, Food* food) {
    snake->length = 1;
    snake->body[0].x = WIDTH / 2;
    snake->body[0].y = HEIGHT / 2;
    snake->dx = 1;
    snake->dy = 0;

    food->pos.x = rand() % WIDTH;
    food->pos.y = rand() % HEIGHT;
    food->is_food = 1;
}

void draw(Snake* snake, Food* food) {
    system("cls"); // Clear screen
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == 0 || x == WIDTH - 1 || y == 0 || y == HEIGHT - 1) {
                printf("#");
            } else if (x == snake->body[0].x && y == snake->body[0].y) {
                printf("O"); // Head of the snake
            } else if (x == food->pos.x && y == food->pos.y) {
                printf("*"); // Food
            } else {
                int printed = 0;
                for (int i = 1; i < snake->length; i++) {
                    if (x == snake->body[i].x && y == snake->body[i].y) {
                        printf("o"); // Body of the snake
                        printed = 1;
                        break;
                    }
                }
                if (!printed) printf(" ");
            }
        }
        printf("\n");
    }
}

void input(Snake* snake) {
    if (_kbhit()) {
        char ch = _getch();
        switch (ch) {
            case 'a': if (snake->dx == 0) { snake->dx = -1; snake->dy = 0; } break;
            case 'd': if (snake->dx == 0) { snake->dx = 1; snake->dy = 0; } break;
            case 'w': if (snake->dy == 0) { snake->dx = 0; snake->dy = -1; } break;
            case 's': if (snake->dy == 0) { snake->dx = 0; snake->dy = 1; } break;
        }
    }
}

void logic(Snake* snake, Food* food) {
    Point prev_head = snake->body[0];
    Point prev_segment;
    snake->body[0].x += snake->dx;
    snake->body[0].y += snake->dy;

    for (int i = 1; i < snake->length; i++) {
        prev_segment = snake->body[i];
        snake->body[i] = prev_head;
        prev_head = prev_segment;
    }

    if (snake->body[0].x == food->pos.x && snake->body[0].y == food->pos.y) {
        snake->length++;
        food->pos.x = rand() % WIDTH;
        food->pos.y = rand() % HEIGHT;
    }

    if (snake->body[0].x >= WIDTH - 1 || snake->body[0].x <= 0 ||
        snake->body[0].y >= HEIGHT - 1 || snake->body[0].y <= 0) {
        exit(0); // End game on wall collision
    }

    for (int i = 1; i < snake->length; i++) {
        if (snake->body[i].x == snake->body[0].x && snake->body[i].y == snake->body[0].y) {
            exit(0); // End game on self collision
        }
    }
}

int main() {
    Snake snake;
    Food food;
    setup(&snake, &food);

    while (1) {
        draw(&snake, &food);
        input(&snake);
        logic(&snake, &food);
        Sleep(100); // Sleep to control game speed
    }

    return 0;
}
