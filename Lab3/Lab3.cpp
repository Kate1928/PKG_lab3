// Lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <windows.h>
#include <wingdi.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;


struct point
{
    float x;
    float y;
};

struct RGB
{
    BYTE r;
    BYTE g;
    BYTE b;
};

HWND sHwnd;
HDC hdc;

void coordinateSystem()
{
    
}

//здесь просто все наши координаты, цвета и затравочные точки 

void init(vector<vector<point>>& shapeAll, vector<point>& zPointAll, vector<COLORREF>& colorAll)
{
    //----------------------------1--------------------
    vector <point> shape1;
    point p;
    COLORREF color;
    p.x = 100 - 40;
    p.y = 100 - 30;
    shape1.push_back(p);
    p.x = 100 - 20;
    p.y = 100 - 50;
    shape1.push_back(p);
    p.x = 100 - 20;
    p.y = 100 - 10;
    shape1.push_back(p);
    shapeAll.push_back(shape1);
    //затравочная точка

    p.x = 100 - 30;
    p.y = 100 - 30;
    zPointAll.push_back(p);
    //color
    color = 0x0000FFFF;
    colorAll.push_back(color);
    //-----------------------------2-------------------------
    shape1.clear();
    p.x = 100 - 20;
    p.y = 100 - 51;
    shape1.push_back(p);
    p.x = 100 - 16;
    p.y = 100 - 53;
    shape1.push_back(p);
    p.x = 100 - 16;
    p.y = 100 - 7;
    shape1.push_back(p);
    p.x = 100 - 20;
    p.y = 100 - 9;
    shape1.push_back(p);
    shapeAll.push_back(shape1);
    //затравочная точка
    p.x = 100 - 18;
    p.y = 100 - 10;
    zPointAll.push_back(p);
    //color
    color = 0x0000A5FF;
    colorAll.push_back(color);
    //------------------------------3-------------------------
    shape1.clear();
    p.x = 100 - 16;
    p.y = 100 - 50;
    shape1.push_back(p);
    p.x = 100 - 6;
    p.y = 100 - 66;
    shape1.push_back(p);
    p.x = 100 + 4;
    p.y = 100 - 66;
    shape1.push_back(p);
    p.x = 100 + 4;
    p.y = 100 - 8;
    shape1.push_back(p);
    p.x = 100 + 2;
    p.y = 100 - 4;
    shape1.push_back(p);
    p.x = 100 - 6;
    p.y = 100 - 4;
    shape1.push_back(p);
    p.x = 100 - 8;
    p.y = 100 - 8;
    shape1.push_back(p);
    p.x = 100 - 16;
    p.y = 100 - 8;
    shape1.push_back(p);
    shapeAll.push_back(shape1);
    //затравочная точка
    p.x = 100 - 10;
    p.y = 100 - 10;
    zPointAll.push_back(p);
    //color
    color = 0x0000FFFF;
    colorAll.push_back(color);
    //------------------------------4-------------------------
    shape1.clear();
    p.x = 100 + 4;
    p.y = 100 - 50;
    shape1.push_back(p);
    p.x = 100 + 30;
    p.y = 100 - 40;
    shape1.push_back(p);
    p.x = 100 + 45;
    p.y = 100 - 45;
    shape1.push_back(p);
    p.x = 100 + 45;
    p.y = 100 - 10;
    shape1.push_back(p);
    p.x = 100 + 30;
    p.y = 100 - 15;
    shape1.push_back(p);
    p.x = 100 + 4;
    p.y = 100 - 8;
    shape1.push_back(p);
    shapeAll.push_back(shape1);
    //затравочная точка
    p.x = 100 + 20;
    p.y = 100 - 20;
    zPointAll.push_back(p);
    //color
    color = 0x0000A5FF;
    colorAll.push_back(color);
    //------------------------------5-------------------------
    shape1.clear();
    p.x = 100 + 45;
    p.y = 100 - 40;
    shape1.push_back(p);
    p.x = 100 + 55;
    p.y = 100 - 45;
    shape1.push_back(p);
    p.x = 100 + 55;
    p.y = 100 - 10;
    shape1.push_back(p);
    p.x = 100 + 45;
    p.y = 100 - 15;
    shape1.push_back(p);
    shapeAll.push_back(shape1);
    //затравочная точка
    p.x = 100 + 50;
    p.y = 100 - 30;
    zPointAll.push_back(p);
    //color
    color = 0x0000FFFF;
    colorAll.push_back(color);
    //------------------------------6-------------------------
    shape1.clear();
    p.x = 100 + 55;
    p.y = 100 - 40;
    shape1.push_back(p);
    p.x = 100 + 65;
    p.y = 100 - 45;
    shape1.push_back(p);
    p.x = 100 + 65;
    p.y = 100 - 10;
    shape1.push_back(p);
    p.x = 100 + 55;
    p.y = 100 - 15;
    shape1.push_back(p);
    shapeAll.push_back(shape1);
    //затравочная точка
    p.x = 100 + 60;
    p.y = 100 - 30;
    zPointAll.push_back(p);
    //color
    color = 0x00C8FFFF;
    colorAll.push_back(color);
    //------------------------------7-------------------------
    shape1.clear();
    p.x = 100 + 36;
    p.y = 100 - 42;
    shape1.push_back(p);
    p.x = 100 + 39;
    p.y = 100 - 43;
    shape1.push_back(p);
    p.x = 100 + 39;
    p.y = 100 - 12;
    shape1.push_back(p);
    p.x = 100 + 36;
    p.y = 100 - 13;
    shape1.push_back(p);
    shapeAll.push_back(shape1);
    //затравочная точка
    p.x = 100 + 38;
    p.y = 100 - 30;
    zPointAll.push_back(p);
    //color
    color = 0x00C8FFFF;
    colorAll.push_back(color);
    //------------------------------8-------------------------
    shape1.clear();
    p.x = 100 - 38;
    p.y = 100 - 30;
    shape1.push_back(p);
    p.x = 100 - 35;
    p.y = 100 - 32;
    shape1.push_back(p);
    p.x = 100 - 35;
    p.y = 100 - 28;
    shape1.push_back(p);
    shapeAll.push_back(shape1);
    //затравочная точка
    p.x = 100 - 37;
    p.y = 100 - 30;
    zPointAll.push_back(p);
    //color
    color = 0x00000001;
    colorAll.push_back(color);

}

//Алгоритм растеризации отрезка «А»: алгоритм ЦДА (DDA) –алгоритм цифрового дифференциального анализатора)

void DDA(vector<point>& shape1, COLORREF color)
{
    float i, l;
    float x, y, dx, dy;
    for (int i = 0; i < shape1.size() - 1; i++)
    {
        //вычисляем большую из длин l отрезка по оси x и y
        l = abs(shape1[i + 1].x - shape1[i].x) >= abs(shape1[i + 1].y - shape1[i].y) ? abs(shape1[i + 1].x - shape1[i].x) : abs(shape1[i + 1].y - shape1[i].y);
        //l = l / 10;
        //определяем приращения по оси x и y, полагая большее из них равным единице
        dx = (shape1[i + 1].x - shape1[i].x) / l;
        dy = (shape1[i + 1].y - shape1[i].y) / l;
        //начинаем с точки (x,y)
        x = shape1[i].x;
        y = shape1[i].y;

        //цикл по большей длине отрезка
        for (int j = 0; j < l; j++)
        {
            SetPixel(hdc, round(x), round(y), color);
            x += dx;
            y += dy;
        }
    }
    int end = shape1.size() - 1;
    l = abs(shape1[0].x - shape1[end].x) >= abs(shape1[0].y - shape1[end].y) ? abs(shape1[0].x - shape1[end].x) : abs(shape1[0].y - shape1[end].y);
    //l = l / 10;
    //l.push_back(maxL);
    //определяем приращения по оси x и y, полагая большее из них равным единице
    dx = (shape1[0].x - shape1[end].x) / l;
    dy = (shape1[0].y - shape1[end].y) / l;
    //начинаем с точки (x,y)
    x = shape1[end].x;
    y = shape1[end].y;
    //цикл по большей длине отрезка
    for (int j = 0; j < l; j++)
    {
        SetPixel(hdc, round(x), round(y), color);
        //SetPixel(hdc, round(x), round(y), RGB(255, 0, 0));
        x += dx;
        y += dy;
    }
}

//Алгоритм растеризации отрезка «Б»: алгоритм Брезенхема для отрезка;

void brezenham(vector<point>& shape1, COLORREF color)
{
    float x, y, dx, dy, signX, signY;
    int error, error2;
    for (int i = 0; i < shape1.size() - 1; i++)
    {
        x = shape1[i].x;
        y = shape1[i].y;
        dx = abs(shape1[i + 1].x - shape1[i].x);
        dy = abs(shape1[i + 1].y - shape1[i].y);
        signX = shape1[i].x < shape1[i + 1].x ? 1 : -1; //1
        signY = shape1[i].y < shape1[i + 1].y ? 1 : -1; //1
        error = dx - dy;
        SetPixel(hdc, round(shape1[i + 1].x), round(shape1[i + 1].y), color);
        while (x != shape1[i + 1].x || y != shape1[i + 1].y)
        {
            SetPixel(hdc, round(x), round(y), color);
            error2 = error * 2;
            if (error2 > -dy)
            {
                error -= dy;
                x += signX;
            }
            if (error2 < dx)
            {
                error += dx;
                y += signY;
            }
        }
    }
    int end = shape1.size() - 1;
    x = shape1[end].x;
    y = shape1[end].y;
    dx = abs(shape1[0].x - shape1[end].x);
    dy = abs(shape1[0].y - shape1[end].y);
    signX = shape1[end].x < shape1[0].x ? 1 : -1; //1
    signY = shape1[end].y < shape1[0].y ? 1 : -1; //1
    error = dx - dy;
    SetPixel(hdc, round(shape1[0].x), round(shape1[0].y), color);
    while (x != shape1[0].x || y != shape1[0].y)
    {
        SetPixel(hdc, round(x), round(y), color);
        error2 = error * 2;
        if (error2 > -dy)
        {
            error -= dy;
            x += signX;
        }
        if (error2 < dx)
        {
            error += dx;
            y += signY;
        }
    }
}

//Алгоритм растеризации сплошной области «А»: рекурсивный алгоритм заливки внутренне - определённой 4 - х связной области;

void areaA(int xz, int yz, COLORREF color)
{
    stack <point> stack;
    point p;
    p.x = xz;
    p.y = yz;
    stack.push(p);
    while (!stack.empty())
    {
        p = stack.top();
        stack.pop();
        SetPixel(hdc, p.x, p.y, color);
        int x = p.x;
        int y = p.y;
        if (GetPixel(hdc, x + 1, y) != color)
        {
            p.x = x + 1;
            stack.push(p);
        }
        if (GetPixel(hdc, x - 1, y) != color)
        {
            p.x = x - 1;
            stack.push(p);
        }
        p.x = x;
        if (GetPixel(hdc, x, y + 1) != color)
        {
            p.y = y + 1;
            stack.push(p);
        }
        if (GetPixel(hdc, x, y - 1) != color)
        {
            p.y = y - 1;
            stack.push(p);
        }
    }
}

//Алгоритм растеризации сплошной области «Б»: модифицированный стэковый алгоритм заливки внутренне - определённой 4 - х связной области

void areaB(int xz, int yz, COLORREF color)
{
    stack <point> stack;
    point p;
    p.x = xz;
    p.y = yz;
    stack.push(p);
    //auto color2 = GetPixel(hdc, 1, 1);
    while (!stack.empty())
    {
        p = stack.top();
        stack.pop();
        
        int x = p.x;
        int y = p.y;
        if (GetPixel(hdc, x + 1, y) != color)
        {
            p.x = x + 1;
            SetPixel(hdc, p.x, p.y, color);
            stack.push(p);
        }
        if (GetPixel(hdc, x - 1, y) != color)
        {
            p.x = x - 1;
            SetPixel(hdc, p.x, p.y, color);
            stack.push(p);
        }
        p.x = x;
        if (GetPixel(hdc, x, y + 1) != color)
        {
            p.y = y + 1;
            SetPixel(hdc, p.x, p.y, color);
            stack.push(p);
        }
        if (GetPixel(hdc, x, y - 1) != color)
        {
            p.y = y - 1;
            SetPixel(hdc, p.x, p.y, color);
            stack.push(p);
        }
    }
}


int main()
{
    sHwnd = GetConsoleWindow();
    hdc = GetDC(sHwnd);
    //-----------CoordinateSistem------------
    
    system("color 70");
    MoveToEx(hdc, 100, 0, 0);
    LineTo(hdc, 100, 200);
    MoveToEx(hdc, 0, 100, 0);
    LineTo(hdc, 200, 100);
    //----------------------------------------
    vector<vector<point>> shapeAll;
    vector<point> zPointAll;
    vector<COLORREF> colorAll;
    init(shapeAll, zPointAll, colorAll);
    
    for (int i = 0; i < 4; i++)
    {
         DDA(shapeAll[i], colorAll[i]);
         areaA(zPointAll[i].x, zPointAll[i].y, colorAll[i]);
    }
    for (int i = 4; i < 8; i++)
    {
        brezenham(shapeAll[i], colorAll[i]);
        areaB(zPointAll[i].x, zPointAll[i].y, colorAll[i]);
    }

    while (true)
    {

    }
}
