#include <Windows.h>
#include <iostream>
#include <cmath>
#include "Point3D.h"
#include "Point2D.h"
#include "AffineTransform.h"
#include <vector>
#include "Model3D.h"
#include "Camera.h"
#include "Scene.h"

Scene scene;
AffineTransform affineTransform;

POINT ProjectToScreen(Point2D point2d) {
    POINT point;
    point.x = static_cast<LONG>((((point2d.x) - scene.camera.L) / (scene.camera.R - scene.camera.L)) * scene.camera.W);
    point.y = static_cast<LONG>(((scene.camera.T - (point2d.y)) / (scene.camera.T - scene.camera.B)) * scene.camera.H);
    return point;
}

// Функция для рисования линий между вершинами фигуры
void DrawFigure(HDC hdc) {
    Point2D* points = Matrix::multiplyTo2D(
        affineTransform.viewToProjectMatrix, 
        Matrix::multiplyTo3D(
            affineTransform.worldToViewMatrix, 
            Matrix::multiplyTo3D(
                affineTransform.affineTransfromMatrix,
                scene.model3D.vertices,
                scene.model3D.v_count), 
            scene.model3D.v_count),
        scene.model3D.v_count);

    //scene.set_LRBTWH(points);
    POINT p1;
    POINT p2;

    for (int i = 0; i < scene.model3D.v_count; i++) {
        p1 = ProjectToScreen(points[i]);
        MoveToEx(hdc, p1.x, p1.y, nullptr);
        for (int j = 0; j < 8; j++) {
            if (scene.model3D.edges[i][j] == 1 && i < j) {
                p2 = ProjectToScreen(points[j]);
                LineTo(hdc, p2.x, p2.y);
                MoveToEx(hdc, p1.x, p1.y, nullptr);
            }
        }
    }
}

void Clear(HDC dc)
{
    RECT r;
    GetClientRect(WindowFromDC(dc), &r);
    Rectangle(dc, 0, 0, r.right, r.bottom);
}

// Функция окна
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        Clear(hdc);
        DrawFigure(hdc);
        EndPaint(hwnd, &ps);
        break;
    }
    case WM_CLOSE: {
        PostQuitMessage(0);
        break;
    }
    case WM_KEYDOWN : {
        switch (wParam) {
            case 0x53: {
                affineTransform.transform(1.2f);
                break;
            }
            case 0x44: {
                affineTransform.transform(0.8f);
                break;
            }
            case 0x58: {
                affineTransform.rotateX(5.0f * 3.14f / 180.0f);
                break;
            }
            case 0x59: {
                affineTransform.rotateY(5.0f * 3.14f / 180.0f);
                break;
            }
            case 0x5A: {
                affineTransform.rotateZ(5.0f * 3.14f / 180.0f);
                break;
            }
        }
        InvalidateRect(hwnd, nullptr, false);
    }
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow) {
    scene = Scene(Point3D(0.0f, -5.0f, 0.0f), Point3D(0.0f, 3.0f, 0.0f), Vector3D(0.0f, 0.0f, 1.0f));
    affineTransform.set_worldToViewMatrix(scene.I, scene.J, scene.K, scene.camera.Ov);
    affineTransform.set_viewToProjectMatrix(scene.F);
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
    wc.lpszClassName = L"3DFigure";

    if (!RegisterClass(&wc)) {
        MessageBox(nullptr, L"Failed to register window class", L"Error", MB_OK | MB_ICONERROR);
        return -1;
    }

    HWND hwnd = CreateWindow(L"3DFigure", L"3D Figure", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        nullptr, nullptr, hInstance, nullptr);

    if (!hwnd) {
        MessageBox(nullptr, L"Failed to create window", L"Error", MB_OK | MB_ICONERROR);
        return -1;
    }

    ShowWindow(hwnd, nCmdShow);

    MSG msg = { 0 };
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return static_cast<int>(msg.wParam);
}