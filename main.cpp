#include "TXLib.h"

void drawSky(COLORREF color)
{
//RGB(200, 250, 252)
    txSetColor (color);
    txSetFillColor (color);
    txRectangle (0, 0, 800, 600);
}

void drawLand()
{
    //����� �����
    txSetColor (TX_GREEN);
    txSetFillColor (TX_GREEN);
    txRectangle (0, 400, 800, 600);

}

void drawHouse(COLORREF colorWin)
{

    //����� ���
    txSetColor (TX_BLACK);
    txSetFillColor (TX_BROWN);
    txRectangle (70, 290, 330, 480);     //�����
    txSetColor (TX_BLACK);
    txSetFillColor (RGB(136, 0, 21));
    POINT kr[3] = {{70, 290}, {200, 180}, {330, 290}};      //�����
    txPolygon (kr, 3);
    txSetColor (TX_BLACK);
//RGB(225, 244, 249)
    txSetFillColor (colorWin);
    txRectangle (100, 320, 180, 420);


}

void drawTree(int x)
{
//x=440
    //����� ������
    txSetColor (TX_BLACK);
    txSetFillColor (TX_BLACK);
    txRectangle (x+430-440, 300, x+440-440, 480);      //�����
    txSetColor (TX_GREEN);
    txSetFillColor (TX_GREEN);
    txEllipse (x+400-440, 160, x+470-440, 390);        //�����

}

void drawSun(int x, int y)
{
    txSetColor (TX_YELLOW);
    txSetFillColor (TX_YELLOW);
    txCircle (x, y, 50);
}

void drawCloude(int x)
{
//x=360
    txSetColor (TX_BLUE);
    txSetFillColor (TX_BLUE);
    txEllipse (x+360-360, 60, x+510-360, 130);
    txEllipse (x+440-360, 40, x+600-360, 120);
    txEllipse (x+540-360, 50, x+690-360, 120);
}

void drawMan(int x, int xLegs)
{
//x=610
    //����� ��������
    txSetColor (TX_PINK);
    txSetFillColor (TX_PINK);
    txCircle (x, 350, 20);        //������
    txSetColor (TX_PINK, 7);
    txLine(x, 440, x, 350);     //��������
    txLine(x, 440, x+30+xLegs, 480);     //������ ����
    txLine(x, 440, x-30-xLegs, 480);     //����� ����
    txLine(x, 380, x+30, 420);     //������ ����
    txLine(x, 380, x-30, 420);     //����� ����

}

int main()
{
txCreateWindow (800, 600);

    int xSun = 100;
    int ySun = 110;
    int xCloude = 360;
    int xMan = 610;
    int xManLegs = 0;

    while(xSun<900)
    {
        txBegin();
        drawSky(RGB(200, 250, 252));
        drawSun(xSun, ySun);
        drawCloude(xCloude);
        drawLand();
        drawHouse(RGB(225, 244, 249));
        drawTree(360);
        drawTree(440);
        drawTree(520);
        drawMan(xMan, xManLegs);
        xSun = xSun + 5;
        ySun = ySun + 2;
        xMan = xMan - 2;
        xManLegs = xManLegs - 15;
        txEnd();
        txSleep(100);

        txBegin();
        drawSky(RGB(200, 250, 252));
        drawSun(xSun, ySun);
        drawCloude(xCloude);
        drawLand();
        drawHouse(RGB(225, 244, 249));
        drawTree(360);
        drawTree(440);
        drawTree(520);
        drawMan(xMan, xManLegs);
        xSun = xSun + 5;
        ySun = ySun + 2;
        xMan = xMan - 3;
        xManLegs = xManLegs + 15;
        txEnd();
        txSleep(100);
    }
    while(xCloude>-400)
    {
        txBegin();
        drawSky(RGB(0, 0, 64));
        drawSun(xSun, ySun);
        drawCloude(xCloude);
        drawLand();
        drawHouse(RGB(255, 255, 128));
        drawTree(360);
        drawTree(440);
        drawTree(520);
        drawMan(xMan, xManLegs);
        xCloude = xCloude - 5;
        xMan = xMan - 5;
        xManLegs = xManLegs - 15;
        txEnd();
        txSleep(50);

        txBegin();
        drawSky(RGB(0, 0, 64));
        drawSun(xSun, ySun);
        drawCloude(xCloude);
        drawLand();
        drawHouse(RGB(255, 255, 128));
        drawTree(360);
        drawTree(440);
        drawTree(520);
        drawMan(xMan, xManLegs);
        xCloude = xCloude - 5;
        xMan = xMan - 5;
        xManLegs = xManLegs + 15;
        txEnd();
        txSleep(50);
    }



txTextCursor (false);
return 0;
}

