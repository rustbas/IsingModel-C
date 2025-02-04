#include <raylib.h>
#include <stdio.h>

#define HEIGHT 480
#define WIDTH 640
#define PROGRAM_NAME "Ising Model"

#define FPS 60

int main(int argc, char** argv){

  InitWindow(WIDTH, HEIGHT, PROGRAM_NAME);
  SetTargetFPS(FPS);
  SetExitKey(KEY_ESCAPE);

  while (!IsKeyDown(KEY_Q) && !WindowShouldClose()) {
    BeginDrawing();
      ClearBackground(RED);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
