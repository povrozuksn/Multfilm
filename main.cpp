#include "TXLib.h"

void drawNebo(COLORREF colorSky)
{
    txSetColor (TX_NULL);
    txSetFillColor (colorSky);
    txRectangle (0, 0, 1200, 400);
}

void drawZenlya()
{
    txSetColor (TX_NULL);
    txSetFillColor (TX_LIGHTGREEN);
    txRectangle (0, 400, 1200, 600);
}

void drawDom()
{
    txSetColor (TX_BLACK);
    txSetFillColor (TX_GRAY);
    txRectangle (180, 320, 500, 550);  //стена
    //крыша
    txSetFillColor (RGB(255,188,121));
    POINT kpysha[3] = {{180, 320}, {340, 180}, {500, 320}};
    txPolygon (kpysha, 3);
    //окно
    txSetFillColor (RGB(140,255,255));
    txRectangle (230, 360, 330, 460);

    //дверной проем
    txSetFillColor (RGB(0,0,0));
    txRectangle (360, 380, 460, 550);
}

void drawDver(int x_dver, int y_dver)
{
    //дверь
    //x_dver=460
    //y_dver=380
    txSetColor (TX_BLACK);
    txSetFillColor (RGB(255,188,121));
    POINT dver[4] = {{360, 380}, {x_dver, y_dver}, {x_dver, y_dver+170}, {360, 550}};
    txPolygon (dver, 4);
}

void drawSun(int x)
{
    txSetColor (TX_NULL);
    txSetFillColor (TX_YELLOW);
    txCircle (x, 100, 50);
}

void drawMan(int x, int y, float rasm)
{
    //Человек
    txSetColor (TX_WHITE, 4);
    txSetFillColor (TX_WHITE);
    //x=630
    txCircle(x, y, 15*rasm);     //голова
    txLine  (x, y+15*rasm, x,         y+70*rasm); //тело
    txLine  (x, y+70*rasm, x-30*rasm, y+120*rasm); //ноги
    txLine  (x, y+70*rasm, x+30*rasm, y+120*rasm); //ноги
    txLine  (x, y+30*rasm, x-30*rasm, y+80*rasm); //руки
    txLine  (x, y+30*rasm, x+30*rasm, y+80*rasm); //руки
}

void drawCloud(int x, int y)
{
    txSetColor (RGB(62, 197, 255));
    txSetFillColor (RGB (62, 197, 255));
    txEllipse (x+410-410, y+50-50, x+580-410, y+120-50);
    txEllipse (x+530-410, y+30-50, x+660-410, y+130-50);
    txEllipse (x+610-410, y+50-50, x+780-410, y+120-50);
}

void drawTree(int x)
{
    //x=710
    txSetColor (RGB(255, 141, 28));
    txSetFillColor (RGB (255, 141, 28));
    txRectangle(x+710-710, 300, x+720-710, 500);
    txSetColor (RGB(79, 240, 107));
    txSetFillColor (RGB (79, 240, 107));
    txEllipse(x+680-710, 170, x+750-710, 300);
    txEllipse(x+680-710, 250, x+750-710, 380);
}

void drawCar(int x, int y)
{
    txSetColor (TX_BLACK);
    txSetFillColor(RGB(255,0,0));
    txRectangle(x+840-840,y+440-440,x+1060-840,y+480-440);
    txSetFillColor(TX_BLACK);
    txSetFillColor(TX_WHITE);
    POINT kabina[4] = {{x+875-840,y+440-440}, {x+900-840,y+405-440}, {x+970-840,y+405-440}, {x+1025-840,y+440-440}};
    txPolygon (kabina, 4);
}

void drawCircle(int x0, int y0, double a1)
{
    txSetColor(TX_WHITE, 3);
    txSetFillColor(TX_BLACK);

    int x1;
    int y1;
    int x2;
    int y2;
    int x3;
    int y3;
    int r  = 20;

    txCircle (x0, y0, r);

    x1 = x0 + r*cos(a1*3.14/180);
    y1 = y0 + r*sin(a1*3.14/180);
    x2 = x0 + r*cos((a1+120)*3.14/180);
    y2 = y0 + r*sin((a1+120)*3.14/180);
    x3 = x0 + r*cos((a1+240)*3.14/180);
    y3 = y0 + r*sin((a1+240)*3.14/180);

    txLine    (x0, y0, x1, y1);
    txLine    (x0, y0, x2, y2);
    txLine    (x0, y0, x3, y3);
}

void drawCarWithMan(int x, int y)
{
    txSetColor (TX_BLACK);
    txSetFillColor(RGB(255,0,0));
    txRectangle(x+840-840,y+440-440,x+1060-840,y+480-440);
    txSetFillColor(TX_BLACK);
    txSetFillColor(TX_WHITE);
    POINT kabina[4] = {{x+875-840,y+440-440}, {x+900-840,y+405-440}, {x+970-840,y+405-440}, {x+1025-840,y+440-440}};
    txPolygon (kabina, 4);
    //Человек
    txSetColor (TX_BLACK, 4);
    txSetFillColor (TX_BLACK);
    txCircle(x+955-840, y+423-440, 12);     //голова

}

void drawRoad()
{
    txSetColor (TX_GRAY, 4);
    txSetFillColor (TX_GRAY);
    txRectangle(0, 500, 1200, 600);
    txSetColor (TX_WHITE, 4);
    txSetFillColor (TX_WHITE);
    for(int x=0; x<1200; x+=120)
    {
        txRectangle(x, 545, x+100, 555);
    }
    for(int y=490; y<=580; y+=30)
    {
        txRectangle(600, y, 700, y+20);
    }
}

void drawCityFon()
{
    txSetColor (RGB (91, 78, 133));
    txSetFillColor (RGB (91, 78, 133));
    txRectangle(0, 0, 1200, 600);
    txSetColor (RGB (0, 0, 100));
    txSetFillColor (RGB (0, 0, 100));
    txRectangle(0, 400, 1200, 600);
}

void drawBuilding(int x, int y, int w, int h, int win[])
{
    //x=70 y=400 w=150 h=370
    txSetColor (TX_WHITE);
    txSetFillColor (TX_BLACK);
    txRectangle(x, y-h, x+w, y);

    txSetColor (TX_WHITE);
    int q=0;
    for(int j=0; j<(h/30); j++)
    {
        for(int i=0; i<(w/30); i++)
        {
            if (win[q]%3 == 0)
            txSetFillColor (TX_WHITE);
            else
            txSetFillColor (TX_BLACK);
            txRectangle((x+10)+(30*i), (y-h+10)+(30*j), (x+30)+(30*i), (y-h+30)+(30*j));
            q++;
        }
    }


}

void drawDialog(int x, int y, int rFont, const char* text)
{
    //x=640 y=340
    txSetColor (TX_BLACK);
    txSetFillColor (TX_WHITE);
    txEllipse(x, y, x+900-640, y+410-340);
    txSelectFont ("Times New Roman", rFont);
    txDrawText(x, y, x+900-640, y+410-340, text);
}

void drawBac(int x, int y, double razm)
{
    txSetColor(TX_BLACK,2);
    txSetFillColor(TX_RED);
    POINT bac[17] = {{x-120*razm,y},         {x-50*razm,y-30*razm},   {x-100*razm,y-130*razm},{x-20*razm,y-60*razm}, {x,y-140*razm},
                     {x+30*razm,y-60*razm},  {x+100*razm,y-130*razm}, {x+60*razm,y-30*razm},  {x+130*razm,y},        {x+60*razm,y+20*razm},
                     {x+110*razm,y+100*razm},{x+20*razm,y+60*razm},   {x,y+120*razm},         {x-20*razm,y+60*razm}, {x-120*razm,y+120*razm},
                     {x-60*razm,y+10*razm},  {x-120*razm,y}};
    txPolygon (bac, 17);
}

void drawTitrsBegin(int y)
{
    txSetColor(TX_WHITE);
    txSelectFont ("Arial", 40, 0, FW_BOLD);
    txDrawText   (100, y, 1100, y+200, "Мультипликацинный фильм\n\n");
    txSelectFont ("Arial", 60, 0, FW_BOLD);
    txDrawText   (100, y+100, 1100, y+300, "НОЧНАЯ ПОЕЗДКА");
}

void drawTitrsFinal(int y)
{
    txSetColor(TX_WHITE);
    txSelectFont ("Arial", 60, 0, FW_BOLD);
    txDrawText   (100, y, 1100, y+100, "КОНЕЦ");
    txSelectFont ("Arial", 10);
    txDrawText   (100, y+200, 1100, y+400, "  eriweuiuiu  qwuriqepriu\n"
                                          "wfsdalsdkgsd  wjelkjwkjflskjd\n"
                                          "  eriweuiuiu  qwuriqepriu\n"
                                          "wfsdalsdkgsd  wjelkjwkjflskjd\n"
                                          "  eriweuiuiu  qwuriqepriu\n"
                                          "wfsdalsdkgsd  wjelkjwkjflskjd\n"
                                          "  eriweuiuiu  qwuriqepriu\n"
                                          "wfsdalsdkgsd  wjelkjwkjflskjd\n"
                                          "wfsdalsdkgsd  wjelkjwkjflskjd\n"
                                          "  eriweuiuiu  qwuriqepriu\n"
                                          "wfsdalsdkgsd  wjelkjwkjflskjd\n"
                                          "  eriweuiuiu  qwuriqepriu\n"
                                          "wfsdalsdkgsd  wjelkjwkjflskjd\n"
                                          "  eriweuiuiu  qwuriqepriu\n"
                                          "wfsdalsdkgsd  wjelkjwkjflskjd\n"
                                          "wfsdalsdkgsd  wjelkjwkjflskjd\n"
                                          "  eriweuiuiu  qwuriqepriu\n"
                                          "wfsdalsdkgsd  wjelkjwkjflskjd\n"
                                          "  eriweuiuiu  qwuriqepriu\n"
                                          "wfsdalsdkgsd  wjelkjwkjflskjd\n"
                                          "  eriweuiuiu  qwuriqepriu\n"
                                          "wfsdalsdkgsd  wjelkjwkjflskjd\n"
                                          "wfsdalsdkgsd  wjelkjwkjflskjd\n"
                                          "  eriweuiuiu  qwuriqepriu\n"
                                          "wfsdalsdkgsd  wjelkjwkjflskjd\n"
                                          "  eriweuiuiu  qwuriqepriu\n"
                                          "wfsdalsdkgsd  wjelkjwkjflskjd\n"
                                          "  eriweuiuiu  qwuriqepriu\n"
                                          "wfsdalsdkgsd  wjelkjwkjflskjd\n"
                                          "wfsdalsdkgsd  wjelkjwkjflskjd\n"
                                          "  eriweuiuiu  qwuriqepriu\n"
                                          "wfsdalsdkgsd  wjelkjwkjflskjd\n"
                                          "  eriweuiuiu  qwuriqepriu\n"
                                          "wfsdalsdkgsd  wjelkjwkjflskjd\n"
                                          "  eriweuiuiu  qwuriqepriu\n"
                                          "wfsdalsdkgsd  wjelkjwkjflskjd\n"



                                          );
}

int main()
{
txCreateWindow (1200, 600);

    int yTitrs = 100;
    int xSun = 100;
    int xMan = 410;
    int yMan = 430;
    double rasmMan = 1;
    int xCloud = 400;
    int yCloud = 50;
    int x_dver = 460;
    int y_dver = 380;
    COLORREF colorSky = RGB (168, 247, 249);
    int xCar = 800;
    int yCar = 450;
    double aCar = 0;
    int win[100];


    drawNebo(TX_BLACK);
    drawTitrsBegin(yTitrs);
    txSleep(2000);


    while(yTitrs>-300)
    {
        drawNebo(TX_BLACK);
        drawTitrsBegin(yTitrs);
        yTitrs -= 1;

        txSleep(20);
    }

    //Меняется погода
    while(xSun < xCloud+200)
    {
        txBegin();
        drawNebo(colorSky);
        drawSun(xSun);
        drawCloud(xCloud, yCloud);
        drawZenlya();
        drawDom();
        drawCar(xCar, yCar);
        drawCircle(xCar+35, yCar+40, aCar);
        drawCircle(xCar+185, yCar+40, aCar);
        drawMan(1100, yMan, rasmMan);

        drawDver(x_dver, y_dver);

        xSun = xSun + 1;
        xCloud = xCloud - 5;
        txSleep(1);
        txEnd();
    }

    //Дверь открывается
    while(x_dver > 370)
    {
        txBegin();
        drawNebo(RGB (91, 78, 133));
        drawSun(xSun);
        drawCloud(xCloud, yCloud);
        drawZenlya();
        drawDom();
        drawCar(xCar, yCar);
        drawCircle(xCar+35, yCar+40, aCar);
        drawCircle(xCar+185, yCar+40, aCar);
        drawDver(x_dver, y_dver);
        drawMan(1100, yMan, rasmMan);

        x_dver -= 1;
        y_dver += 1;
        txSleep(1);
        txEnd();
    }

    //Человек идет из дома
    while(xMan < 630)
    {
        txBegin();
        drawNebo(RGB (91, 78, 133));
        drawSun(xSun);
        drawCloud(xCloud, yCloud);
        drawZenlya();
        drawDom();
        drawCar(xCar, yCar);
        drawCircle(xCar+35, yCar+40, aCar);
        drawCircle(xCar+185, yCar+40, aCar);
        drawDver(x_dver, y_dver);
        drawMan(xMan, yMan, rasmMan);
        drawMan(1100, yMan, rasmMan);
        drawDialog(xMan+50, yMan-100, 25, "Привет");


        xMan = xMan + 5;
        txSleep(1);
        txEnd();
    }

    //Дверь закрывается
    while(x_dver < 460)
    {
        txBegin();
        drawNebo(RGB (91, 78, 133));
        drawSun(xSun);
        drawCloud(xCloud, yCloud);
        drawZenlya();
        drawDom();
        drawCar(xCar, yCar);
        drawCircle(xCar+35, yCar+40, aCar);
        drawCircle(xCar+185, yCar+40, aCar);
        drawDver(x_dver, y_dver);
        drawMan(xMan, yMan, rasmMan);
        drawMan(1100, yMan, rasmMan);


        x_dver += 1;
        y_dver -= 1;
        txSleep(1);
        txEnd();
    }

    //Человек идет к машине
    while(xMan < 850)
    {
        txBegin();
        drawNebo(RGB (91, 78, 133));
        drawSun(xSun);
        drawCloud(xCloud, yCloud);
        drawZenlya();
        drawDom();
        drawDver(x_dver, y_dver);
        drawCar(xCar, yCar);
        drawCircle(xCar+35, yCar+40, aCar);
        drawCircle(xCar+185, yCar+40, aCar);
        drawMan(xMan, yMan, rasmMan);
        drawMan(1100, yMan, rasmMan);

        xMan = xMan + 5;
        txSleep(1);
        txEnd();
    }


    drawNebo(RGB (91, 78, 133));
    drawSun(xSun);
    drawCloud(xCloud, yCloud);
    drawZenlya();
    drawDom();
    drawDver(x_dver, y_dver);
    drawCar(xCar, yCar);
    drawCircle(xCar+35, yCar+40, aCar);
    drawCircle(xCar+185, yCar+40, aCar);
    drawMan(xMan, yMan, rasmMan);
    drawMan(1100, yMan, rasmMan);
    drawDialog(xMan+50, yMan-100, 17, "Меня зовут кататься на машине");
    txSleep(1000);
    drawDialog(1100-300, yMan-100, 17, "Ну и ладно");
    txSleep(1000);


    //Человек садится в машину
        txBegin();
        drawNebo(RGB (91, 78, 133));
        drawSun(xSun);
        drawCloud(xCloud, yCloud);
        drawZenlya();
        drawDom();
        drawDver(x_dver, y_dver);
        drawCarWithMan(xCar, yCar);
        drawCircle(xCar+35, yCar+40, aCar);
        drawCircle(xCar+185, yCar+40, aCar);

        txSleep(50);
        txEnd();

    //Машина едет
     while(xCar < 1250)
     {
        txBegin();
        drawNebo(RGB (91, 78, 133));
        drawSun(xSun);
        drawCloud(xCloud, yCloud);
        drawZenlya();
        drawDom();
        drawDver(x_dver, y_dver);
        drawCarWithMan(xCar, yCar);
        drawCircle(xCar+35, yCar+40, aCar);
        drawCircle(xCar+185, yCar+40, aCar);

        xCar += 10;
        aCar +=15;
        txSleep(10);
        txEnd();
      }

    //Смена СЦЕНЫ
    xCar = -50;
    yCar = 500;
    while(xCar < 1250)
    {
        txBegin();
        drawNebo(RGB (91, 78, 133));
        drawZenlya();

        for(int xTree=50; xTree<1200; xTree=xTree+100)
        {
            drawTree(xTree);
        }
        drawRoad();

         drawCarWithMan(xCar, yCar);
        drawCircle(xCar+35, yCar+40, aCar);
        drawCircle(xCar+185, yCar+40, aCar);

        xCar += 10;
        aCar +=15;
        txSleep(1);
        txEnd();
    }

    //Человек идет по ночному городу

    for (int i=0; i<100; i++)
    {
        win[i] = random(0, 1000);
    }

    xMan = -10;
    while(xMan < 500)
    {
        txBegin();
        drawCityFon();
        drawBuilding(70,  400, 160, 370, win);
        drawBuilding(250, 400, 250, 200, win);
        drawBuilding(530, 400, 460, 300, win);
        drawMan(xMan, yMan, 5);

        xMan = xMan + 5;
        txSleep(1);
        txEnd();
    }

    while(rasmMan > 0.2)
    {
        txBegin();
        drawCityFon();
        drawBuilding(70,  400, 160, 370, win);
        drawBuilding(250, 400, 250, 200, win);
        drawBuilding(530, 400, 460, 300, win);
        drawMan(xMan, yMan, rasmMan);

        rasmMan -= 0.01;
        txSleep(1);
        txEnd();
    }

    double razmBac = 0;
    while(razmBac < 10)
    {
        txBegin();
        drawCityFon();
        drawBuilding(70,  400, 160, 370, win);
        drawBuilding(250, 400, 250, 200, win);
        drawBuilding(530, 400, 460, 300, win);
        drawMan(xMan, yMan, rasmMan);
        drawBac(600, 300, razmBac);

        razmBac += 0.1;
        txEnd();
    }

    yTitrs = 600;
    while(yTitrs>-300)
    {
        txSetFillColor(TX_BLACK);
        txRectangle(0,0,1200,600);
        drawTitrsFinal(yTitrs);
        yTitrs -= 1;

        txSleep(20);
    }



txTextCursor (false);
return 0;
}

