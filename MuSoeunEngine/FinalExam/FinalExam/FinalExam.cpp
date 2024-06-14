#pragma comment(lib, "OpenGL32.lib")
#include <crtdbg.h>
#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <chrono>
#include <thread>
#include <cmath>
#include "Object.h" // Object.h 파일을 포함합니다.

void errorCallback(int error, const char* description)
{
    printf("GLFW Error: %s\n", description);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{

}

int Physics()
{
    return 0;
}

int Initialize()
{
    // 배경 색깔 설정: R, G, B : 0, 30, 100
    glClearColor(0.0f, 30.0f / 255.0f, 100.0f / 255.0f, 1.0f);
    return 0;
}

int Update()
{
    return 0;
}

int Render()
{
    // 화면을 설정한 배경색으로 지우기
    glClear(GL_COLOR_BUFFER_BIT);

    // Player 객체 생성 및 충돌 처리 테스트
    Player player;
    Object other;
    player.OnCollisionEnter(other);

    // Floor 객체 생성 및 충돌 처리 테스트
    Floor floor;
    floor.OnCollisionEnter(other);

    EnemyBlock enemyblock;
    enemyblock.OnCollisionEnter(other);

    return 1;
}

int main(void)
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // glfw라이브러리 초기화
    if (!glfwInit())
        return -1;

    GLFWwindow* window;
    window = glfwCreateWindow(800, 600, "Google Dino Run Copy Game", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);

    Initialize();

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        Physics();
        Update();
        Render();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
