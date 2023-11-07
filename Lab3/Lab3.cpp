// Lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <windows.h>
#include <wingdi.h>
#include <iostream>
#include <vector>
#include <stack>
#include <ctime>
#include <fstream>
#include <cmath>

using namespace std;

#define PI 3.14159265

struct point
{
    float x;
    float y;
};

//struct RGB
//{
//    BYTE r;
//    BYTE g;
//    BYTE b;
//};

HWND sHwnd;
HDC hdc;
int metricsDDA = 0, metricsBrezenham = 0, metricsA = 0, metricsB = 0;
ofstream file2;

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
    p.y = 200 - 30;
    shape1.push_back(p);
    p.x = 100 - 20;
    p.y = 200 - 50;
    shape1.push_back(p);
    p.x = 100 - 20;
    p.y = 200 - 10;
    shape1.push_back(p);
    shapeAll.push_back(shape1);
    //затравочная точка

    p.x = 100 - 30;
    p.y = 200 - 30;
    zPointAll.push_back(p);
    //color
    color = 0x0000FFFF;
    colorAll.push_back(color);
    //-----------------------------2-------------------------
    shape1.clear();
    p.x = 100 - 20;
    p.y = 200 - 51;
    shape1.push_back(p);
    p.x = 100 - 16;
    p.y = 200 - 53;
    shape1.push_back(p);
    p.x = 100 - 16;
    p.y = 200 - 7;
    shape1.push_back(p);
    p.x = 100 - 20;
    p.y = 200 - 9;
    shape1.push_back(p);
    shapeAll.push_back(shape1);
    //затравочная точка
    p.x = 100 - 18;
    p.y = 200 - 10;
    zPointAll.push_back(p);
    //color
    color = 0x0000A5FF;
    colorAll.push_back(color);
    //------------------------------3-------------------------
    shape1.clear();
    p.x = 100 - 16;
    p.y = 200 - 50;
    shape1.push_back(p);
    p.x = 100 - 6;
    p.y = 200 - 66;
    shape1.push_back(p);
    p.x = 100 + 4;
    p.y = 200 - 66;
    shape1.push_back(p);
    p.x = 100 + 4;
    p.y = 200 - 8;
    shape1.push_back(p);
    p.x = 100 + 2;
    p.y = 200 - 4;
    shape1.push_back(p);
    p.x = 100 - 6;
    p.y = 200 - 4;
    shape1.push_back(p);
    p.x = 100 - 8;
    p.y = 200 - 8;
    shape1.push_back(p);
    p.x = 100 - 16;
    p.y = 200 - 8;
    shape1.push_back(p);
    shapeAll.push_back(shape1);
    //затравочная точка
    p.x = 100 - 10;
    p.y = 200 - 10;
    zPointAll.push_back(p);
    //color
    color = 0x0000FFFF;
    colorAll.push_back(color);
    //------------------------------4-------------------------
    shape1.clear();
    p.x = 100 + 4;
    p.y = 200 - 50;
    shape1.push_back(p);
    p.x = 100 + 30;
    p.y = 200 - 40;
    shape1.push_back(p);
    p.x = 100 + 45;
    p.y = 200 - 45;
    shape1.push_back(p);
    p.x = 100 + 45;
    p.y = 200 - 10;
    shape1.push_back(p);
    p.x = 100 + 30;
    p.y = 200 - 15;
    shape1.push_back(p);
    p.x = 100 + 4;
    p.y = 200 - 8;
    shape1.push_back(p);
    shapeAll.push_back(shape1);
    //затравочная точка
    p.x = 100 + 20;
    p.y = 200 - 20;
    zPointAll.push_back(p);
    //color
    color = 0x0000A5FF;
    colorAll.push_back(color);
    //------------------------------5-------------------------
    shape1.clear();
    p.x = 100 + 45;
    p.y = 200 - 40;
    shape1.push_back(p);
    p.x = 100 + 55;
    p.y = 200 - 45;
    shape1.push_back(p);
    p.x = 100 + 55;
    p.y = 200 - 10;
    shape1.push_back(p);
    p.x = 100 + 45;
    p.y = 200 - 15;
    shape1.push_back(p);
    shapeAll.push_back(shape1);
    //затравочная точка
    p.x = 100 + 50;
    p.y = 200 - 30;
    zPointAll.push_back(p);
    //color
    color = 0x0000FFFF;
    colorAll.push_back(color);
    //------------------------------6-------------------------
    shape1.clear();
    p.x = 100 + 55;
    p.y = 200 - 40;
    shape1.push_back(p);
    p.x = 100 + 65;
    p.y = 200 - 45;
    shape1.push_back(p);
    p.x = 100 + 65;
    p.y = 200 - 10;
    shape1.push_back(p);
    p.x = 100 + 55;
    p.y = 200 - 15;
    shape1.push_back(p);
    shapeAll.push_back(shape1);
    //затравочная точка
    p.x = 100 + 60;
    p.y = 200 - 30;
    zPointAll.push_back(p);
    //color
    color = 0x00C8FFFF;
    colorAll.push_back(color);
    //------------------------------7-------------------------
    shape1.clear();
    p.x = 100 + 36;
    p.y = 200 - 42;
    shape1.push_back(p);
    p.x = 100 + 39;
    p.y = 200 - 43;
    shape1.push_back(p);
    p.x = 100 + 39;
    p.y = 200 - 12;
    shape1.push_back(p);
    p.x = 100 + 36;
    p.y = 200 - 13;
    shape1.push_back(p);
    shapeAll.push_back(shape1);
    //затравочная точка
    p.x = 100 + 38;
    p.y = 200 - 30;
    zPointAll.push_back(p);
    //color
    color = 0x00C8FFFF;
    colorAll.push_back(color);
    //------------------------------8-------------------------
    shape1.clear();
    p.x = 100 - 38;
    p.y = 200 - 30;
    shape1.push_back(p);
    p.x = 100 - 35;
    p.y = 200 - 32;
    shape1.push_back(p);
    p.x = 100 - 35;
    p.y = 200 - 28;
    shape1.push_back(p);
    shapeAll.push_back(shape1);
    //затравочная точка
    p.x = 100 - 37;
    p.y = 200 - 30;
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
            //Sleep(100);
            metricsDDA++;
            x += dx;
            y += dy;
        }
        file2 << " кол-во пикселейDDA: " << metricsDDA << " ";
        metricsDDA = 0;
    }
    //тоже-самое для последней стороны многоугольника 
    int end = shape1.size() - 1;
    l = abs(shape1[0].x - shape1[end].x) >= abs(shape1[0].y - shape1[end].y) ? abs(shape1[0].x - shape1[end].x) : abs(shape1[0].y - shape1[end].y);
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
        metricsDDA++;
        //SetPixel(hdc, round(x), round(y), RGB(255, 0, 0));
        x += dx;
        y += dy;
    }
    file2 << " кол-во пикселейDDA: " << metricsDDA << endl;
    metricsDDA = 0;
}

void DDAtest(int x1, int x2, int y1, int y2)
{
    float i, l;
    float x, y, dx, dy;
    l = abs(x2 - x1) >= abs(y2 - y1) ? abs(x2 - x1) : abs(y2 - y1);
    //определяем приращения по оси x и y, полагая большее из них равным единице
    dx = (x2 - x1) / l;
    dy = (y2 - y1) / l;
    //начинаем с точки (x,y)
    x = x1;
    y = y1;
    //цикл по большей длине отрезка
    for (int j = 0; j < l; j++)
    {
        SetPixel(hdc, round(x), round(y), 0x000000FF);
        metricsDDA++;
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
        metricsBrezenham++;
        while (x != shape1[i + 1].x || y != shape1[i + 1].y)
        {
            if (GetPixel(hdc, round(x), round(y)) == 0x00CCCCCC)
            {
                SetPixel(hdc, round(x), round(y), 0x00FFFFFF);
            }
            else
            {
                SetPixel(hdc, round(x), round(y), color);
            }
            metricsBrezenham++;
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
        file2 << " кол-во пикселейBr: " << metricsBrezenham << " ";
        metricsBrezenham = 0;
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
    metricsBrezenham++;
    while (x != shape1[0].x || y != shape1[0].y)
    {
        if (GetPixel(hdc, round(x), round(y)) == 0x00CCCCCC)
        {
            SetPixel(hdc, round(x), round(y), 0x00FFFFFF);
        }
        else
        {
            SetPixel(hdc, round(x), round(y), color);
        }
        metricsBrezenham++;
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
    file2 << " кол-во пикселейBr: " << metricsBrezenham << endl;
    metricsBrezenham = 0;
}

void brezenhamTest(int x1, int x2, int y1, int y2)
{
    float x, y, dx, dy, signX, signY;
    int error, error2;
    x = x1;
    y = y1;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    signX = x1 < x2 ? 1 : -1; //1
    signY = y1 < y2 ? 1 : -1; //1
    error = dx - dy;
    //auto color = 0x0000FF00;// | GetPixel(hdc, round(x), round(y));
    SetPixel(hdc, round(x2), round(y2), 0x0000FF00);
    metricsBrezenham++;
    while (x != x2 || y != y2)
    {
        /*color = GetPixel(hdc, round(x), round(y));
        color = color | 0x0000FF00;*/
        SetPixel(hdc, round(x), round(y), 0x0000FF00);
        metricsBrezenham++;
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
        
        metricsA++;
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
        //Sleep(10);
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
        if (GetPixel(hdc, x + 1, y) != color && GetPixel(hdc, x + 1, y) != 0x00FFFFFF)
        {
            p.x = x + 1;
            SetPixel(hdc, p.x, p.y, color);
            metricsB++;
            stack.push(p);
        }
        if (GetPixel(hdc, x - 1, y) != color && GetPixel(hdc, x - 1, y) != 0x00FFFFFF)
        {
            p.x = x - 1;
            SetPixel(hdc, p.x, p.y, color);
            metricsB++;
            stack.push(p);
        }
        p.x = x;
        if (GetPixel(hdc, x, y + 1) != color && GetPixel(hdc, x, y + 1) != 0x00FFFFFF)
        {
            p.y = y + 1;
            SetPixel(hdc, p.x, p.y, color);
            metricsB++;
            stack.push(p);
        }
        if (GetPixel(hdc, x, y - 1) != color && GetPixel(hdc, x, y - 1) != 0x00FFFFFF)
        {
            p.y = y - 1;
            SetPixel(hdc, p.x, p.y, color);
            metricsB++;
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
    MoveToEx(hdc, 100, 100, 0);
    LineTo(hdc, 100, 300);
    MoveToEx(hdc, 0, 200, 0);
    LineTo(hdc, 200, 200);
    //----------------------------------------
    vector<vector<point>> shapeAll;
    vector<point> zPointAll;
    vector<COLORREF> colorAll;
    init(shapeAll, zPointAll, colorAll);

    unsigned int start_time; 
    unsigned int end_time;
    unsigned int search_time;
    ofstream file;
    
    file.open("File1.txt");
    file2.open("File2.txt");

    int test = 1;
    if (test == 0)
    {        
        for (int i = 0; i < 8; i++)
        {
            brezenham(shapeAll[i], colorAll[i]);
            areaB(zPointAll[i].x, zPointAll[i].y, colorAll[i]);
        }
    }
    if(test == 1)
    {
        for (int i = 0; i < 8; i++)
        {
            DDA(shapeAll[i], colorAll[i]);
            start_time = clock(); // начальное время
            areaA(zPointAll[i].x, zPointAll[i].y, colorAll[i]);
            end_time = clock(); // конечное время
            search_time = end_time - start_time; // искомое время
            file << "искомое времяA:" << search_time << " кол-во пикселейA: " << metricsA << " ";
            cout << "A:" << search_time << " ";
            metricsA = 0;

            brezenham(shapeAll[i], 0x00FF0000);
            start_time = clock(); // начальное время
            areaB(zPointAll[i].x, zPointAll[i].y, 0x00FF0000);
            end_time = clock(); // конечное время
            search_time = end_time - start_time; // искомое время
            file << "искомое времяB:" << search_time << " кол-во пикселейB: " << metricsB << " ";
            cout << "B:" << search_time << " ";
            file << endl;
            metricsB = 0;
        }
        cout << endl;
        metricsDDA = 0;
        metricsBrezenham = 0;

        //----------------------------------------------------------------------
        
        float x2 = 0;
        float y2 = 0;
        int a, L = 50, x, y;
        for (int i = 0; i < 10; i++)
        {
            a = i * 10;
            x2 = 100 + cos(a * PI / 180) * L;
            y2 = 200 + sin(a * PI / 180) * L;
            /*if (i != 0)
            {
                y2 = 200 - y2;
            }*/
            //line[0] = p;
            start_time = clock(); // начальное время
            DDAtest(100, round(x2), 200, round(y2));
            end_time = clock(); // конечное время
            search_time = end_time - start_time; // искомое время
            cout << "DDA:" << search_time << " ";
            metricsDDA = 0;
            start_time = clock(); // начальное время
            brezenhamTest(100, round(x2), 200, round(y2));
            end_time = clock(); // конечное время
            search_time = end_time - start_time; // искомое время
            cout << "Brezenham:" << search_time << " ";
            metricsBrezenham = 0;
        }
    }

    while (true)
    {

    }
}
