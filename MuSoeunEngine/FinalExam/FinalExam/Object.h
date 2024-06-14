#pragma once
#include <GLFW/glfw3.h>

// Base class
class Object {
public:
    virtual void OnCollisionEnter(Object& other) {
    }
};

// Derived classes
class Player : public Object {
public:
    void OnCollisionEnter(Object& other) override {
        DrawSquare();
    }

private:
    void DrawSquare() {
        float aspectRatio = 4.0f / 3.0f; // 가정한 종횡비 예시
        float sideLength = 0.125f;
        float halfSide = sideLength / 2.0f;
        float borderWidth = 0.04f / 4.0f;
        float innerHalfSide = halfSide - borderWidth;

        // 전체 사각형 (가로축 길이를 종횡비로 줄임)
        glColor3f(0.0f, 0.0f, 0.0f); // 검은색 설정
        glBegin(GL_QUADS);
        glVertex2f(-halfSide / aspectRatio, -halfSide);
        glVertex2f(halfSide / aspectRatio, -halfSide);
        glVertex2f(halfSide / aspectRatio, halfSide);
        glVertex2f(-halfSide / aspectRatio, halfSide);
        glEnd();

        // 내부 사각형 (빨간색으로, 가로축 길이를 종횡비로 줄임)
        glColor3f(1.0f, 0.0f, 0.0f); // 빨간색 설정
        glBegin(GL_QUADS);
        glVertex2f(-innerHalfSide / aspectRatio, -innerHalfSide);
        glVertex2f(innerHalfSide / aspectRatio, -innerHalfSide);
        glVertex2f(innerHalfSide / aspectRatio, innerHalfSide);
        glVertex2f(-innerHalfSide / aspectRatio, innerHalfSide);
        glEnd();
    }
};

class EnemyBlock : public Object {
public:
    void OnCollisionEnter(Object& other) override {
        DrawCac();
    }
private:
    void DrawCac()
    {
        glColor3f(0.0f, 1.0f, 0.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-0.7f, -0.66f);
        glVertex2f(-0.7f, -0.33f);
        glVertex2f(-0.54f, -0.33f);
        glVertex2f(-0.54f, -0.66f);
        glEnd();

        glColor3f(0.0f, 1.0f, 0.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-0.5f, -0.66f);
        glVertex2f(-0.5f, 0.33f);
        glVertex2f(-0.34f, 0.33f);
        glVertex2f(-0.34f, -0.66f);
        glEnd();

        glColor3f(0.0f, 1.0f, 0.0f);
        glBegin(GL_POLYGON);
        glVertex2f(0.5f, -0.66f);
        glVertex2f(0.5f, -0.33f);
        glVertex2f(0.66f, -0.33f);
        glVertex2f(0.66f, -0.66f);
        glEnd();

        glColor3f(0.0f, 1.0f, 0.0f);
        glBegin(GL_POLYGON);
        glVertex2f(0.7f, -0.66f);
        glVertex2f(0.7f, 0.33f);
        glVertex2f(0.86f, 0.33f);
        glVertex2f(0.86f, -0.66f);
        glEnd();
    }
};

class Floor : public Object {
public:
    void OnCollisionEnter(Object& other) override {
        DrawYellowRectangle();
    }

private:
    void DrawYellowRectangle()
    {
        glColor3f(1.0f, 0.78f, 0.05f); // 색상 설정
        glBegin(GL_QUADS); // 사각형을 그리기 위해 GL_QUADS 사용
        glVertex2f(-1.0f, -0.66f);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f(1.0f, -1.0f);
        glVertex2f(1.0f, -0.66f);
        glEnd();
    }
};

class Star : public Object {
public:
    void OnCollisionEnter(Object& other) override {
    }
};

int PhysicsAABB(Object A, Object B)
{
    return 0;
}
