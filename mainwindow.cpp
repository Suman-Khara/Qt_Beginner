#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPixmap>
#include <QColor>
#include <QTimer>
#include <QMouseEvent>
#include <QStack>
#include <QQueue>
#define lekh qDebug() <<
#define Delay delay(1)
bool axis_shown=false;
bool grids_shown=false;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->workArea->setMouseTracking(true);
    ui->workArea->installEventFilter(this);

    QPixmap canvas = ui->workArea->pixmap(Qt::ReturnByValue);
    if (canvas.isNull())
    {
        canvas = QPixmap(ui->workArea->size());
        canvas.fill(Qt::white);
        ui->workArea->setPixmap(canvas);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::delay(int ms)
{
    QEventLoop loop;
    QTimer::singleShot(ms, &loop, &QEventLoop::quit);
    loop.exec();
}

void MainWindow::colorPointAbsolute(int x, int y, int r, int g, int b, int penwidth = 1)
{
    QPixmap canvas = ui->workArea->pixmap();
    QPainter painter(&canvas);
    QPen pen = QPen(QColor(r, g, b), penwidth);
    painter.setPen(pen);
    painter.drawPoint(x, y);
    ui->workArea->setPixmap(canvas);
}

void MainWindow::colorPointRelative(int x, int y, int r, int g, int b)
{
    // Convert relative position (x, y) to absolute pixel positions
    int absX = centerX + x * gridOffset + gridOffset / 2;
    int absY = centerY - y * gridOffset - gridOffset / 2;

    // Call the colorPointAbsolute function to actually color the pixel
    colorPointAbsolute(absX, absY, r, g, b, gridOffset);
}

void MainWindow::on_showAxis_clicked()
{
    axis_shown=true;
    int gridOffset = (ui->gridOffset->value() == 0) ? 1 : ui->gridOffset->value();
    int width = ui->workArea->width();
    int height = ui->workArea->height();
    int centerX = width / 2;
    int centerY = height / 2;

    // Draw horizontal axis (y = 0)
    for (int x = 0; x < width; ++x)
        colorPointAbsolute(x, centerY - gridOffset / 2.0, 255, 0, 0, gridOffset);

    // Draw vertical axis (x = 0)
    for (int y = 0; y < height; ++y)
        colorPointAbsolute(centerX + gridOffset / 2.0, y, 255, 0, 0, gridOffset);
}

void MainWindow::on_gridlines_clicked()
{
    grids_shown=true;
    int gridOffset = ui->gridOffset->value();
    int width = ui->workArea->width();
    int height = ui->workArea->height();
    if (gridOffset <= 0)
        return;

    int centerX = width / 2;
    int centerY = height / 2;

    QPixmap canvas = ui->workArea->pixmap();
    QPainter painter(&canvas);
    painter.setPen(QColor(0, 0, 0));

    for (int i = 0; (centerX + i < width && centerX - i > 0) || (centerY + i < height && centerY - i > 0); i += gridOffset)
    {
        // Vertical lines
        if (centerX + i < width)
            painter.drawLine(QPoint(centerX + i, 0), QPoint(centerX + i, height));
        if (centerX - i > 0)
            painter.drawLine(QPoint(centerX - i, 0), QPoint(centerX - i, height));

        // Horizontal lines
        if (centerY + i < height)
            painter.drawLine(QPoint(0, centerY + i), QPoint(width, centerY + i));
        if (centerY - i > 0)
            painter.drawLine(QPoint(0, centerY - i), QPoint(width, centerY - i));
    }

    painter.end();

    ui->workArea->setPixmap(canvas);
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->workArea)
    {

        if (event->type() == QEvent::MouseMove)
        {
            QMouseEvent *cursor = static_cast<QMouseEvent *>(event);
            int x = cursor->pos().x();
            int y = cursor->pos().y();
            int gridOffset = (ui->gridOffset->value() == 0) ? 1 : ui->gridOffset->value();
            int width = ui->workArea->width();
            int height = ui->workArea->height();
            int centerX = width / 2;
            int centerY = height / 2;

            int gridX = floor((x - centerX) * 1.0 / gridOffset);
            int gridY = floor((centerY - y) * 1.0 / gridOffset);

            ui->x_coordinate->setText(QString::number(gridX));
            ui->y_coordinate->setText(QString::number(gridY));
            return true;
        }

        if (event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *cursor = static_cast<QMouseEvent *>(event);
            int x = cursor->pos().x();
            int y = cursor->pos().y();
            gridOffset = (ui->gridOffset->value() == 0) ? 1 : ui->gridOffset->value();
            width = ui->workArea->width();
            height = ui->workArea->height();
            centerX = width / 2;
            centerY = height / 2;

            int gridX = floor((x - centerX) * 1.0 / gridOffset);
            int gridY = floor((centerY - y) * 1.0 / gridOffset);

            clickedPoints.push_back({gridX, gridY});
            //lekh gridX<<gridY;
            int calcX = centerX + gridX * gridOffset + gridOffset / 2;
            int calcY = centerY - gridY * gridOffset - gridOffset / 2;
            lastColor=getPixelColor(calcX, calcY);
            colorPointAbsolute(calcX, calcY, 0, 0, 255, gridOffset);

            return true;
        }
    }

    return QMainWindow::eventFilter(watched, event);
}

void MainWindow::draw_DDA_Line(float x1, float y1, float x2, float y2, int r, int g, int b)
{
    float dx, dy, xinc, yinc, steps;

    dx = x2 - x1;
    dy = y2 - y1;
    steps = std::max(abs(dx), abs(dy));

    xinc = dx / steps;
    yinc = dy / steps;

    int gridOffset = (ui->gridOffset->value() == 0) ? 1 : ui->gridOffset->value();
    int width = ui->workArea->width();
    int height = ui->workArea->height();
    int centerX = width / 2;
    int centerY = height / 2;

    float x_float = centerX + x1 * gridOffset + gridOffset / 2.0;
    float y_float = centerY - y1 * gridOffset - gridOffset / 2.0;

    int xn = static_cast<int>(x_float);
    int yn = static_cast<int>(y_float);

    QVector<QPoint> pts;
    pts.push_back(QPoint(xn, yn));

    for (int i = 0; i < steps; i++)
    {
        x_float += xinc * gridOffset;
        y_float -= yinc * gridOffset;
        int x_new = static_cast<int>(x_float);
        int y_new = static_cast<int>(y_float);

        if (x_new != xn || y_new != yn)
        {
            xn = x_new;
            yn = y_new;
            int X = floor((xn - centerX) * 1.0 / gridOffset);
            int Y = floor((centerY - yn) * 1.0 / gridOffset);
            int calcX = centerX + X * gridOffset + gridOffset / 2;
            int calcY = centerY - Y * gridOffset - gridOffset / 2;
            pts.push_back(QPoint(calcX, calcY));
        }
    }

    for (const auto &pt : pts)
    {
        colorPointAbsolute(pt.x(), pt.y(), r, g, b, gridOffset);
        Delay;
    }
}

void MainWindow::on_DDA_Button_clicked()
{
    if (clickedPoints.size() < 2)
        return;
    qint64 n = clickedPoints.size();
    auto coords1 = clickedPoints[n - 1];
    auto coords2 = clickedPoints[n - 2];
    QElapsedTimer timer;
    timer.start();
    draw_DDA_Line(coords1.x(), coords1.y(), coords2.x(), coords2.y(), 0, 255, 0);
    qint64 elapsedTime = timer.nsecsElapsed();
    ui->DDA_Time->setText(QString("Time Taken: ") + QString::number(elapsedTime) + QString(" ns"));
}

QSet<QPoint> MainWindow::make_Bresenham_Line(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    QSet<QPoint> pts;  // Set to store relative positions

    while (true)
    {
        pts.insert(QPoint(x1, y1));  // Insert the relative point

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }

    return pts;
}

void MainWindow::draw_Bresenham_Line(int x1, int y1, int x2, int y2, int r, int g, int b)
{
    // Store the line
    lineStorage.append(QLine(x1, y1, x2, y2));

    // Call make_Bresenham_Line to get the set of points that make the line
    QSet<QPoint> pts = make_Bresenham_Line(x1, y1, x2, y2);

    // Iterate over the points and color them
    for (const QPoint &pt : pts)
    {
        colorPointRelative(pt.x(), pt.y(), r, g, b);
    }
}

void MainWindow::on_Bresenham_Button_clicked()
{
    if (clickedPoints.size() < 2)
        return;
    qint64 n = clickedPoints.size();
    auto coords1 = clickedPoints[n - 1];
    auto coords2 = clickedPoints[n - 2];
    QElapsedTimer timer;
    timer.start();
    draw_Bresenham_Line(coords1.x(), coords1.y(), coords2.x(), coords2.y(), 200, 0, 255);
    qint64 elapsedTime = timer.nsecsElapsed();
    ui->Bresenham_Time->setText(QString("Time Taken: ") + QString::number(elapsedTime) + QString(" ns"));
}

void MainWindow::drawCirclePoints(int x, int y, int pixelCenterX, int pixelCenterY, int r, int g, int b, int gridOffset)
{

    QSet<QPair<int, int>> uniquePoints;

    uniquePoints.insert(qMakePair(pixelCenterX + x * gridOffset, pixelCenterY - y * gridOffset));
    uniquePoints.insert(qMakePair(pixelCenterX - x * gridOffset, pixelCenterY - y * gridOffset));
    uniquePoints.insert(qMakePair(pixelCenterX + x * gridOffset, pixelCenterY + y * gridOffset));
    uniquePoints.insert(qMakePair(pixelCenterX - x * gridOffset, pixelCenterY + y * gridOffset));
    uniquePoints.insert(qMakePair(pixelCenterX + y * gridOffset, pixelCenterY - x * gridOffset));
    uniquePoints.insert(qMakePair(pixelCenterX - y * gridOffset, pixelCenterY - x * gridOffset));
    uniquePoints.insert(qMakePair(pixelCenterX + y * gridOffset, pixelCenterY + x * gridOffset));
    uniquePoints.insert(qMakePair(pixelCenterX - y * gridOffset, pixelCenterY + x * gridOffset));

    for (const auto &point : uniquePoints)
    {
        colorPointAbsolute(point.first, point.second, r, g, b, gridOffset);
        Delay;
    }
}

void MainWindow::on_Polar_Circle_Button_clicked()
{
    QElapsedTimer timer;
    timer.start();

    int radius = ui->Circle_Radius->value();
    radius++;

    if (clickedPoints.empty())
        return;
    int gridCenterX = clickedPoints.back().x();
    int gridCenterY = clickedPoints.back().y();

    int gridOffset = (ui->gridOffset->value() == 0) ? 1 : ui->gridOffset->value();
    int width = ui->workArea->width();
    int height = ui->workArea->height();
    int centerX = width / 2;
    int centerY = height / 2;

    int pixelCenterX = centerX + gridCenterX * gridOffset + gridOffset / 2;
    int pixelCenterY = centerY - gridCenterY * gridOffset - gridOffset / 2;

    QSet<QPair<int, int>> uniquePoints;

    for (double theta = 0.01; theta <= 45.0; theta += 0.1)
    {
        double rad = qDegreesToRadians(theta);
        int x = static_cast<int>(radius * cos(rad));
        int y = static_cast<int>(radius * sin(rad));
        uniquePoints.insert(qMakePair(x, y));
    }

    for (const auto &point : uniquePoints)
    {
        int x = point.first;
        int y = point.second;
        drawCirclePoints(x, y, pixelCenterX, pixelCenterY, 0, 0, 0, gridOffset);
    }

    qint64 elapsed = timer.elapsed();
    ui->Polar_Circle_Time->setText(QString::number(elapsed) + " ms");
}

void MainWindow::on_Bresenham_Circle_Button_clicked()
{
    // Start the timer
    QElapsedTimer timer;
    timer.start();

    // Get the radius from the Circle_Radius QSpinBox
    int radius = ui->Circle_Radius->value();

    // Get the center of the circle from the last clicked point
    if (clickedPoints.empty())
        return;
    int gridCenterX = clickedPoints.back().x();
    int gridCenterY = clickedPoints.back().y();

    int gridOffset = (ui->gridOffset->value() == 0) ? 1 : ui->gridOffset->value();
    int width = ui->workArea->width();
    int height = ui->workArea->height();
    int centerX = width / 2;
    int centerY = height / 2;

    // Convert grid center to actual pixel coordinates
    int pixelCenterX = centerX + gridCenterX * gridOffset + gridOffset / 2;
    int pixelCenterY = centerY - gridCenterY * gridOffset - gridOffset / 2;

    // Use QSet to store unique points
    QSet<QPair<int, int>> uniquePoints;

    // Bresenham's Circle Algorithm
    int x = 0, y = radius;
    int d = 3 - 2 * radius;

    while (y >= x)
    {
        uniquePoints.insert(qMakePair(x, y));
        x++;
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
        {
            d = d + 4 * x + 6;
        }
        uniquePoints.insert(qMakePair(x, y));
    }

    // Draw the unique points using 8-point symmetry
    for (const auto &point : uniquePoints)
    {
        int x = point.first;
        int y = point.second;
        drawCirclePoints(x, y, pixelCenterX, pixelCenterY, 0, 255, 255, gridOffset);
    }

    qint64 elapsed = timer.elapsed();

    ui->Bresenham_Circle_Time->setText(QString::number(elapsed) + " ms");
}

void MainWindow::on_Cartesian_Circle_Button_clicked()
{
    QElapsedTimer timer;
    timer.start();

    int radius = ui->Circle_Radius->value();

    if (clickedPoints.empty())
        return;
    int gridCenterX = clickedPoints.back().x();
    int gridCenterY = clickedPoints.back().y();

    int gridOffset = (ui->gridOffset->value() == 0) ? 1 : ui->gridOffset->value();
    int width = ui->workArea->width();
    int height = ui->workArea->height();
    int centerX = width / 2;
    int centerY = height / 2;
    int pixelCenterX = centerX + gridCenterX * gridOffset + gridOffset / 2;
    int pixelCenterY = centerY - gridCenterY * gridOffset - gridOffset / 2;

    QSet<QPair<int, int>> uniquePoints;

    for (int x = 0; x <= radius; x++)
    {
        int y = static_cast<int>(sqrt(radius * radius - x * x));
        uniquePoints.insert(qMakePair(x, y));
    }

    for (const auto &point : uniquePoints)
    {
        int x = point.first;
        int y = point.second;
        drawCirclePoints(x, y, pixelCenterX, pixelCenterY, 255, 0, 255, gridOffset);
    }

    qint64 elapsed = timer.elapsed();

    ui->Cartesian_Circle_Time->setText(QString::number(elapsed) + " ms");
}

void MainWindow::on_Reset_Screen_Button_clicked()
{
    QPixmap clearPixmap(ui->workArea->size());
    clearPixmap.fill(Qt::white);
    ui->workArea->setPixmap(clearPixmap);

    //clickedPoints.clear();

    ui->x_coordinate->clear();
    ui->y_coordinate->clear();

    ui->Polar_Circle_Time->clear();
    ui->Bresenham_Circle_Time->clear();
    ui->Cartesian_Circle_Time->clear();

    ui->Circle_Radius->setValue(0);

    ui->workArea->update();
}

void MainWindow::drawEllipsePoints(int x, int y, int pixelCenterX, int pixelCenterY, int r, int g, int b, int gridOffset)
{

    colorPointAbsolute(pixelCenterX + x * gridOffset, pixelCenterY - y * gridOffset, r, g, b, gridOffset);
    Delay;
    colorPointAbsolute(pixelCenterX - x * gridOffset, pixelCenterY - y * gridOffset, r, g, b, gridOffset);
    Delay;
    colorPointAbsolute(pixelCenterX + x * gridOffset, pixelCenterY + y * gridOffset, r, g, b, gridOffset);
    Delay;
    colorPointAbsolute(pixelCenterX - x * gridOffset, pixelCenterY + y * gridOffset, r, g, b, gridOffset);
    Delay;
}

void MainWindow::on_Polar_Ellipse_Button_clicked()
{
    QElapsedTimer timer;
    timer.start();

    int axisA = ui->ellipse_axis_1->value();
    int axisB = ui->ellipse_axis_2->value();
    axisA++;
    axisB++;

    if (clickedPoints.empty())
        return;
    int gridCenterX = clickedPoints.back().x();
    int gridCenterY = clickedPoints.back().y();

    int gridOffset = (ui->gridOffset->value() == 0) ? 1 : ui->gridOffset->value();
    int width = ui->workArea->width();
    int height = ui->workArea->height();
    int centerX = width / 2;
    int centerY = height / 2;

    int pixelCenterX = centerX + gridCenterX * gridOffset + gridOffset / 2;
    int pixelCenterY = centerY - gridCenterY * gridOffset - gridOffset / 2;

    QSet<QPair<int, int>> ellipsePoints;

    for (double theta = 0.01; theta <= 90.0; theta += 0.1)
    {
        double rad = qDegreesToRadians(theta);
        int x = static_cast<int>(axisA * cos(rad));
        int y = static_cast<int>(axisB * sin(rad));

        ellipsePoints.insert({x, y});
    }

    for (const auto &point : ellipsePoints)
    {
        drawEllipsePoints(point.first, point.second, pixelCenterX, pixelCenterY, 85, 85, 85, gridOffset);
    }

    qint64 elapsed = timer.elapsed();
    ui->Polar_Ellipse_Time->setText(QString::number(elapsed) + " ms");
}

void MainWindow::on_Bresenham_Ellipse_Button_clicked()
{
    QElapsedTimer timer;
    timer.start();

    int a = ui->ellipse_axis_1->value();
    int b = ui->ellipse_axis_2->value();

    if (clickedPoints.empty())
        return;
    int gridCenterX = clickedPoints.back().x();
    int gridCenterY = clickedPoints.back().y();

    int gridOffset = (ui->gridOffset->value() == 0) ? 1 : ui->gridOffset->value();
    int width = ui->workArea->width();
    int height = ui->workArea->height();
    int centerX = width / 2;
    int centerY = height / 2;

    int pixelCenterX = centerX + gridCenterX * gridOffset + gridOffset / 2;
    int pixelCenterY = centerY - gridCenterY * gridOffset - gridOffset / 2;

    QSet<QPair<int, int>> ellipsePoints;

    int x = 0, y = b;
    long long a2 = a * a;
    long long b2 = b * b;
    long long d1 = b2 - (a2 * b) + (0.25 * a2);
    long long dx = 2 * b2 * x;
    long long dy = 2 * a2 * y;

    while (dx < dy)
    {
        ellipsePoints.insert({x, y});
        if (d1 < 0)
        {
            x++;
            dx = dx + 2 * b2;
            d1 = d1 + dx + b2;
        }
        else
        {
            x++;
            y--;
            dx = dx + 2 * b2;
            dy = dy - 2 * a2;
            d1 = d1 + dx - dy + b2;
        }
    }

    long long d2 = b2 * (x + 0.5) * (x + 0.5) + a2 * (y - 1) * (y - 1) - a2 * b2;
    while (y >= 0)
    {
        ellipsePoints.insert({x, y});
        if (d2 > 0)
        {
            y--;
            dy = dy - 2 * a2;
            d2 = d2 + a2 - dy;
        }
        else
        {
            y--;
            x++;
            dx = dx + 2 * b2;
            dy = dy - 2 * a2;
            d2 = d2 + dx - dy + a2;
        }
    }

    for (const QPair<int, int> &p : ellipsePoints)
    {
        drawEllipsePoints(p.first, p.second, pixelCenterX, pixelCenterY, 170, 170, 170, gridOffset);
    }

    qint64 elapsed = timer.elapsed();
    ui->Bresenham_Ellipse_Time->setText(QString::number(elapsed) + " ms");
}

QHash<QPoint, QVector<QPoint>> MainWindow::make_polygon(int n)
{
    allPolygonPoints.clear();
    belongsToEdge.clear();
    polygonVertices.clear();  // Clear the previous vertices
    QSet<QPoint> distinctPoints;
    QList<QPoint> orderedPoints;
    QHash<QPoint, QVector<QPoint>> connections;  // Use QHash instead of QMap

    // Gather last 'n' distinct points from clickedPoints
    for (auto it = clickedPoints.rbegin(); it != clickedPoints.rend() && distinctPoints.size() < n; ++it)
    {
        if (!distinctPoints.contains(*it))
        {
            distinctPoints.insert(*it);
            orderedPoints.push_front(*it); // Keep the points in reverse order
        }
    }

    // If there are not enough distinct points, return an empty hash
    if (distinctPoints.size() < n)
    {
        return QHash<QPoint, QVector<QPoint>>();  // Return empty hash
    }

    // Store the ordered points (vertices) in polygonVertices
    polygonVertices = orderedPoints.toVector();

    // Iterate through the points to create the polygon lines and track connections
    for (int i = 0; i < orderedPoints.size(); ++i)
    {
        QPoint p1 = orderedPoints[i];
        QPoint p2 = orderedPoints[(i + 1) % orderedPoints.size()]; // Connect last point to the first one
        QSet<QPoint> linePoints = make_Bresenham_Line(p1.x(), p1.y(), p2.x(), p2.y());
        allPolygonPoints.unite(linePoints); // Add the line points to the overall polygon points

        // Store non-vertex points and their associated edges in belongsToEdge
        for(QPoint p: linePoints)
        {
            if (p != p1 && p != p2)
            {
                if (!belongsToEdge.contains(p))
                    belongsToEdge[p] = QVector<QPoint>();
                belongsToEdge[p].append(p1);
                belongsToEdge[p].append(p2);
            }
        }

        // Add the connection p1 -> p2 and p2 -> p1 to the hash
        if (!connections.contains(p1)) {
            connections[p1] = QVector<QPoint>();
        }
        connections[p1].append(p2);

        if (!connections.contains(p2)) {
            connections[p2] = QVector<QPoint>();
        }
        connections[p2].append(p1);
    }

    // Return the hash of connections
    return connections;
}

void MainWindow::on_Polygon_Button_clicked()
{
    QElapsedTimer timer;
    timer.start();

    int n = ui->Polygon_Side_Count->value();

    // Get the set of points that make the polygon
    make_polygon(n);

    // If the set is empty, it means we don't have enough points
    if (allPolygonPoints.isEmpty())
    {
        ui->Polygon_Label->setText("Not enough points");
        return;
    }

    // Color the polygon points
    int r = 255, g = 165, b = 0;
    draw_polygon(r, g, b);
    qint64 elapsed = timer.elapsed();
    ui->Polygon_Label->setText(QString::number(elapsed) + " ms");
    //lekh polygonVertices;
}

void MainWindow::on_Polygon_Scanline_Fill_clicked()
{
    QElapsedTimer timer;
    timer.start();

    int n = ui->Polygon_Side_Count->value();
    //int gridOffset=fmax(ui->gridOffset->value(), 1);
    // Get the set of points that make the polygon
    QHash<QPoint, QVector<QPoint>> connections=make_polygon(n);

    // If the set is empty, it means we don't have enough points
    if (allPolygonPoints.isEmpty())
    {
        ui->Polygon_Label->setText("Not enough points");
        return;
    }
    int r=ui->Polygon_Scanline_R->value();
    int g=ui->Polygon_Scanline_G->value();
    int b=ui->Polygon_Scanline_B->value();
    int maxY=INT_MIN, minY=INT_MAX;
    for(QPoint p:allPolygonPoints){
        maxY=fmax(maxY, p.y());
        minY=fmin(minY, p.y());
    }
    for(int y=minY;y<=maxY;y++){
        int minX=INT_MAX, maxX=INT_MIN;
        for(QPoint p:allPolygonPoints){
            if(y!=p.y())
                continue;
            minX=fmin(minX, p.x());
            maxX=fmax(maxX, p.x());
        }
        bool colorable=false;
        int down=-1, up=-1, final=-1;
        QPoint edge1=QPoint(INT_MIN, INT_MIN), edge2=QPoint(INT_MIN, INT_MIN);
        for(int x=minX;x<=maxX;x++){
            QPoint p(x, y);
            if(allPolygonPoints.contains(p)){ //(x, y) is an edge point
                if(final==-1)
                    final=0;
                if(connections.contains(p)){ //(x,y) is a vertex
                    //check if this is a new edge or not

                    if(edge1!=p && edge2!=p){
                        colorable=!colorable;
                        edge1=p, edge2=p;
                    }
                    QPoint p1=connections[p][0], p2=connections[p][1];
                    if((p1.y()<y && p2.y()<y) || (p1.y()>y && p2.y()>y)){ //same side. untoggle the toggled boolean and finalise it
                        colorable=!colorable;
                        final=1;
                    }
                    else if(p1.y()!=y && p2.y()!=y) //different side. finalise the toggled boolean.
                        final=1;
                    else{ //one connected vertex is at the same level with current vertex. cannot be determined simply.
                        if(p1.y()>y || p2.y()>y){
                            if(up==-1)
                                up=1;
                        }
                        else if(p1.y()<y || p2.y()<y){
                            if(down==-1)
                                down=1;
                        }
                        //skip to the next vertex, if any on the right side
                        int new_x;
                        if(p1.y()==y)
                            new_x=fmax(x, p1.x());
                        if(p2.y()==y)
                            new_x=fmax(x, p2.x());
                        if(new_x==x){ //we are at the rightmost point of the horizontal edge
                            if(up==1 && down==1) //different side
                                colorable=!colorable; //toggle (DOUBLE MISTAKE LEADING TO CORRECT BEHAVIOR XD)
                            final=1;
                        }
                        else
                            final=0; //we are not in a position to determine yet
                        //go to the next x coordinate
                        if(x!=new_x)
                            x=new_x-1;
                    }
                }
                else{
                    if(belongsToEdge[p].size()==4) //OSTRICH METHOD LMFAOOOO
                        continue;
                    QPoint e1=belongsToEdge[p][0], e2=belongsToEdge[p][1];
                    if(edge1==edge2){ //previous edge point was a new edge and a vertex
                        if(edge1==e1) //vertex was e1
                            edge2=e2;
                        else if(edge1==e2) //vertex was e2
                            edge2=e1;
                        else{ //neither are vertex. hence new edge
                            colorable=!colorable;
                            final=0;
                            edge1=e1, edge2=e2;
                        }
                    }
                    else if((e1==edge1 && e2==edge2) || (e2==edge1 && e1==edge2)) // same as previous edge
                        continue;
                    else{
                        colorable=!colorable; //toggle boolean if new edge is found
                        final=0;
                    }
                    edge1=e1, edge2=e2;
                }
            }
            else{ //(x, y) is an interior/exterior point
                final=-1;
                up=-1;
                down=-1;
                if(colorable){
                    colorPointRelative(x, y, r, g, b);
                    Delay;
                }
            }
        }
    }

    qint64 elapsed = timer.elapsed();
    ui->Polygon_Label->setText(QString::number(elapsed) + " ms");
}

void MainWindow::on_Flood_Fill_clicked()
{
    QElapsedTimer timer;
    timer.start();

    int r = ui->Seed_Color_R->value();
    int g = ui->Seed_Color_G->value();
    int b = ui->Seed_Color_B->value();
    int c = ui->Connected->value();
    if (c != 4 && c != 8)
    {
        ui->Flood_Fill_Time->setText("Wrong connectedness");
        return;
    }
    if (clickedPoints.empty())
    {
        ui->Flood_Fill_Time->setText("Not enough points");
        return;
    }
    QPoint seedPoint = clickedPoints.back();

    int gridOffset = (ui->gridOffset->value() == 0) ? 1 : ui->gridOffset->value();
    int width = ui->workArea->width();
    int height = ui->workArea->height();
    int centerX = width / 2;
    int centerY = height / 2;

    QStack<QPoint> stack;
    stack.push(seedPoint);
    // lekh stack;
    // lekh allPolygonPoints;
    bool start=true;
    while (!stack.isEmpty())
    {
        QPoint point = stack.pop();
        int x = point.x();
        int y = point.y();
        int pixelX = centerX + x * gridOffset + gridOffset / 2;
        int pixelY = centerY - y * gridOffset - gridOffset / 2;

        if (pixelX < 0 || pixelY < 0 || pixelX >= width || pixelY >= height)
        {
            continue;
        }
        QColor color=getPixelColor(pixelX, pixelY);
        if (color==lastColor || start)
        {
            start=false;
            colorPointAbsolute(pixelX, pixelY, r, g, b, gridOffset);
            Delay;

            stack.push(QPoint(x + 1, y));
            stack.push(QPoint(x, y + 1));
            stack.push(QPoint(x - 1, y));
            stack.push(QPoint(x, y - 1));
            if (c == 8)
            {
                stack.push(QPoint(x + 1, y + 1));
                stack.push(QPoint(x - 1, y - 1));
                stack.push(QPoint(x - 1, y + 1));
                stack.push(QPoint(x + 1, y - 1));
            }
        }
    }

    qint64 elapsed = timer.elapsed();
    ui->Flood_Fill_Time->setText(QString::number(elapsed) + " ms");
}

QColor MainWindow::getPixelColor(int x, int y)
{
    QImage image = ui->workArea->pixmap(Qt::ReturnByValue).toImage();
    return image.pixelColor(x, y);
}

void MainWindow::on_Boundary_Fill_clicked()
{
    QElapsedTimer timer;
    timer.start();

    int r = ui->Seed_Color_R->value();
    int g = ui->Seed_Color_G->value();
    int b = ui->Seed_Color_B->value();
    int c = ui->Connected->value();
    if (c != 4 && c != 8)
    {
        ui->Flood_Fill_Time->setText("Wrong connectedness");
        return;
    }
    if (clickedPoints.empty())
    {
        ui->Boundary_Fill_Time->setText("Not enough points");
        return;
    }

    QPoint seedPoint = clickedPoints.back();

    int gridOffset = (ui->gridOffset->value() == 0) ? 1 : ui->gridOffset->value();
    int width = ui->workArea->width();
    int height = ui->workArea->height();
    int centerX = width / 2;
    int centerY = height / 2;
    QQueue<QPoint> queue;
    queue.enqueue(seedPoint);

    while (!queue.isEmpty())
    {
        QPoint point = queue.dequeue();
        int x = point.x();
        int y = point.y();
        int pixelX = centerX + x * gridOffset + gridOffset / 2;
        int pixelY = centerY - y * gridOffset - gridOffset / 2;

        if (pixelX < 0 || pixelY < 0 || pixelX >= width || pixelY >= height)
        {
            continue;
        }
        QColor currentColor = getPixelColor(pixelX, pixelY);

        if (currentColor == QColor(r, g, b) || allPolygonPoints.contains({x, y}))
        {
            continue;
        }
        colorPointAbsolute(pixelX, pixelY, r, g, b, gridOffset);
        Delay;

        // Enqueue neighbors
        queue.enqueue(QPoint(x + 1, y));
        queue.enqueue(QPoint(x - 1, y));
        queue.enqueue(QPoint(x, y + 1));
        queue.enqueue(QPoint(x, y - 1));
        if (c == 8)
        {
            queue.enqueue(QPoint(x + 1, y + 1));
            queue.enqueue(QPoint(x - 1, y - 1));
            queue.enqueue(QPoint(x - 1, y + 1));
            queue.enqueue(QPoint(x + 1, y - 1));
        }
    }

    qint64 elapsed = timer.elapsed();
    ui->Boundary_Fill_Time->setText(QString::number(elapsed) + " ms");
}

void MainWindow::draw_polygon(int r, int g, int b)
{
    // Iterate over the vertices and draw a line between each consecutive pair of points
    for (int i = 0; i < polygonVertices.size(); ++i)
    {
        QPoint p1 = polygonVertices[i];
        QPoint p2 = polygonVertices[(i + 1) % polygonVertices.size()]; // Connect the last point to the first one

        // Draw the Bresenham line between p1 and p2
        draw_Bresenham_Line(p1.x(), p1.y(), p2.x(), p2.y(), r, g, b);
    }
}

void MainWindow::on_Translate_Button_clicked()
{
    // Step 1: Reset the screen
    on_Reset_Screen_Button_clicked();

    // Step 2: Show gridlines
    on_gridlines_clicked();

    // Step 3: Get the translation values from the spin boxes
    int translateX = ui->Translate_X->value();
    int translateY = ui->Translate_Y->value();

    // Step 4: Translate each point in the polygon
    for (int i = 0; i < polygonVertices.size(); ++i)
    {
        // Translate the point by adding translateX and translateY
        polygonVertices[i].setX(polygonVertices[i].x() + translateX);
        polygonVertices[i].setY(polygonVertices[i].y() + translateY);
    }

    // Step 5: Redraw the polygon with the translated vertices
    draw_polygon(255, 165, 0);
}

void MainWindow::on_Shear_Button_clicked()
{
    // Step 1: Reset the screen
    on_Reset_Screen_Button_clicked();

    // Step 2: Show gridlines
    on_gridlines_clicked();

    // Step 3: Get the shear values from the spin boxes
    double shearX = ui->Shear_X->value();
    double shearY = ui->Shear_Y->value();

    // Step 4: Apply shear transformation to each vertex
    for (int i = 0; i < polygonVertices.size(); ++i)
    {
        double x = polygonVertices[i].x();
        double y = polygonVertices[i].y();

        // Apply the shear transformation
        int newX = static_cast<int>(x + shearX * y);  // Shearing in x-direction
        int newY = static_cast<int>(y + shearY * x);  // Shearing in y-direction

        // Update the vertex with the new coordinates
        polygonVertices[i].setX(newX);
        polygonVertices[i].setY(newY);
    }

    // Step 5: Redraw the polygon with the sheared vertices
    draw_polygon(255, 165, 0);
}

void MainWindow::on_Scale_Button_clicked()
{
    // Step 1: Reset the screen
    on_Reset_Screen_Button_clicked();

    // Step 2: Show gridlines
    on_gridlines_clicked();

    // Step 3: Get the scaling factors from the spin boxes
    double scaleX = ui->Scale_X->value();
    double scaleY = ui->Scale_Y->value();

    // Step 4: Apply scaling transformation to each vertex
    for (int i = 0; i < polygonVertices.size(); ++i)
    {
        double x = polygonVertices[i].x();
        double y = polygonVertices[i].y();

        // Apply the scaling transformation
        int newX = static_cast<int>(x * scaleX);  // Scale in the x-direction
        int newY = static_cast<int>(y * scaleY);  // Scale in the y-direction

        // Update the vertex with the new coordinates
        polygonVertices[i].setX(newX);
        polygonVertices[i].setY(newY);
    }

    // Step 5: Redraw the polygon with the scaled vertices
    draw_polygon(255, 165, 0);
}


void MainWindow::on_Reflect_X_clicked()
{
    // Step 1: Reset the screen
    on_Reset_Screen_Button_clicked();

    // Step 2: Show gridlines
    on_gridlines_clicked();

    // Step 3: Apply reflection across the x-axis
    for (int i = 0; i < polygonVertices.size(); ++i)
    {
        int y = polygonVertices[i].y();

        // Reflect across the x-axis (negate the y-coordinate)
        int newY = -y;

        // Update the vertex with the new coordinates
        polygonVertices[i].setY(newY);
    }

    // Step 4: Redraw the polygon with the reflected vertices
    draw_polygon(255, 165, 0);
}


void MainWindow::on_Reflect_Y_clicked()
{
    // Step 1: Reset the screen
    on_Reset_Screen_Button_clicked();

    // Step 2: Show gridlines
    on_gridlines_clicked();

    // Step 3: Apply reflection across the x-axis
    for (int i = 0; i < polygonVertices.size(); ++i)
    {
        int x = polygonVertices[i].x();

        // Reflect across the x-axis (negate the y-coordinate)
        int newX = -x;

        // Update the vertex with the new coordinates
        polygonVertices[i].setX(newX);
    }

    // Step 4: Redraw the polygon with the reflected vertices
    draw_polygon(255, 165, 0);
}

void MainWindow::on_Rotate_AC_Button_clicked()
{
    // Step 1: Reset the screen
    on_Reset_Screen_Button_clicked();

    // Step 2: Show gridlines
    on_gridlines_clicked();

    // Step 3: Get the angle from the Rotate_Degrees QSpinBox
    int angleDegrees = ui->Rotate_Degrees->value();

    // Convert the angle to radians
    double angleRadians = qDegreesToRadians(static_cast<double>(angleDegrees));

    // Step 4: Apply rotation to each vertex
    for (int i = 0; i < polygonVertices.size(); ++i)
    {
        double x = polygonVertices[i].x();
        double y = polygonVertices[i].y();

        // Calculate the new coordinates after rotation
        int newX = static_cast<int>(x * cos(angleRadians) - y * sin(angleRadians));
        int newY = static_cast<int>(x * sin(angleRadians) + y * cos(angleRadians));

        // Update the vertex with the new coordinates
        polygonVertices[i].setX(newX);
        polygonVertices[i].setY(newY);
    }

    // Step 5: Redraw the polygon with the rotated vertices
    draw_polygon(255, 165, 0);
}

void MainWindow::on_Scale_Button_AP_clicked()
{
    // Step 1: Reset the screen
    on_Reset_Screen_Button_clicked();

    // Step 2: Show gridlines
    on_gridlines_clicked();

    // Step 3: Get the last clicked point (AP) for scaling
    if (clickedPoints.size() < 1) return;  // Ensure we have at least one point clicked
    QPoint AP = clickedPoints.back();  // The last point clicked

    double scaleX = ui->Scale_X_AP->value();
    double scaleY = ui->Scale_Y_AP->value();

    // Step 4: Translate the polygon such that AP becomes the origin
    for (int i = 0; i < polygonVertices.size(); ++i)
    {
        double x = polygonVertices[i].x() - AP.x();
        double y = polygonVertices[i].y() - AP.y();

        // Step 5: Scale with respect to AP
        int newX = static_cast<int>(x * scaleX);
        int newY = static_cast<int>(y * scaleY);

        // Step 6: Translate back to original position
        polygonVertices[i].setX(newX + AP.x());
        polygonVertices[i].setY(newY + AP.y());
    }

    // Step 7: Redraw the polygon
    draw_polygon(255, 165, 0);
}

void MainWindow::on_Reflect_AL_clicked()
{
    // Step 1: Reset the screen
    on_Reset_Screen_Button_clicked();

    // Step 2: Show gridlines
    on_gridlines_clicked();

    // Step 3: Get the last two clicked points (AL) for reflection
    if (clickedPoints.size() < 2) return;  // Ensure we have at least two points clicked
    QPoint A1 = clickedPoints[clickedPoints.size() - 2];  // Second last point clicked
    QPoint A2 = clickedPoints.back();  // Last point clicked

    // Calculate the slope of the line A1 -> A2
    double dx = A2.x() - A1.x();
    double dy = A2.y() - A1.y();
    double angle = atan2(dy, dx);  // Angle of the line with respect to the X-axis

    // Step 4: Translate the polygon such that AL passes through the origin
    for (int i = 0; i < polygonVertices.size(); ++i)
    {
        polygonVertices[i] -= A1;  // Translate the points by A1
    }

    // Step 5: Rotate the polygon such that AL aligns with the X-axis
    for (int i = 0; i < polygonVertices.size(); ++i)
    {
        double x = polygonVertices[i].x();
        double y = polygonVertices[i].y();

        int newX = static_cast<int>(x * cos(-angle) - y * sin(-angle));
        int newY = static_cast<int>(x * sin(-angle) + y * cos(-angle));

        polygonVertices[i].setX(newX);
        polygonVertices[i].setY(newY);
    }

    // Step 6: Reflect the points over the X-axis (invert Y coordinates)
    for (int i = 0; i < polygonVertices.size(); ++i)
    {
        polygonVertices[i].setY(-polygonVertices[i].y());
    }

    // Step 7: Rotate the polygon back to its original position
    for (int i = 0; i < polygonVertices.size(); ++i)
    {
        double x = polygonVertices[i].x();
        double y = polygonVertices[i].y();

        int newX = static_cast<int>(x * cos(angle) - y * sin(angle));
        int newY = static_cast<int>(x * sin(angle) + y * cos(angle));

        polygonVertices[i].setX(newX);
        polygonVertices[i].setY(newY);
    }

    // Step 8: Translate the polygon back to its original position
    for (int i = 0; i < polygonVertices.size(); ++i)
    {
        polygonVertices[i] += A1;
    }

    // Step 9: Redraw the polygon
    draw_polygon(255, 165, 0);
}

void MainWindow::on_Rotate_AC_Button_AP_clicked()
{
    // Step 1: Reset the screen
    on_Reset_Screen_Button_clicked();

    // Step 2: Show gridlines
    on_gridlines_clicked();

    // Step 3: Get the last clicked point (AP) for rotation
    if (clickedPoints.size() < 1) return;  // Ensure we have at least one point clicked
    QPoint AP = clickedPoints.back();  // The last point clicked

    // Step 4: Get the rotation angle from Rotate_Degrees_AP QSpinBox
    int angleDegrees = ui->Rotate_Degrees_AP->value();
    double angleRadians = qDegreesToRadians(static_cast<double>(angleDegrees));

    // Step 5: Translate the polygon such that AP becomes the origin
    for (int i = 0; i < polygonVertices.size(); ++i)
    {
        double x = polygonVertices[i].x() - AP.x();
        double y = polygonVertices[i].y() - AP.y();

        // Step 6: Rotate the polygon
        int newX = static_cast<int>(x * cos(angleRadians) - y * sin(angleRadians));
        int newY = static_cast<int>(x * sin(angleRadians) + y * cos(angleRadians));

        // Step 7: Translate back to original position
        polygonVertices[i].setX(newX + AP.x());
        polygonVertices[i].setY(newY + AP.y());
    }

    // Step 8: Redraw the polygon
    draw_polygon(255, 165, 0);
}

const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

int computeCode(int x, int y, int xMin, int yMin, int xMax, int yMax) {
    int code = INSIDE;
    if (x < xMin) code |= LEFT;
    else if (x > xMax) code |= RIGHT;
    if (y < yMin) code |= BOTTOM;
    else if (y > yMax) code |= TOP;
    return code;
}
bool cohenSutherlandClip(int &x1, int &y1, int &x2, int &y2, int xMin, int yMin, int xMax, int yMax) {
    int code1 = computeCode(x1, y1, xMin, yMin, xMax, yMax);
    int code2 = computeCode(x2, y2, xMin, yMin, xMax, yMax);
    bool accept = false;

    while (true) {
        if (!(code1 | code2)) {
            accept = true; // Both points are inside
            break;
        } else if (code1 & code2) {
            break; // Both points share an outside region, trivially reject
        } else {
            int x, y;
            int codeOut = code1 ? code1 : code2;

            if (codeOut & TOP) {
                x = x1 + (x2 - x1) * (yMax - y1) / (y2 - y1);
                y = yMax;
            } else if (codeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (yMin - y1) / (y2 - y1);
                y = yMin;
            } else if (codeOut & RIGHT) {
                y = y1 + (y2 - y1) * (xMax - x1) / (x2 - x1);
                x = xMax;
            } else if (codeOut & LEFT) {
                y = y1 + (y2 - y1) * (xMin - x1) / (x2 - x1);
                x = xMin;
            }

            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1, xMin, yMin, xMax, yMax);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2, xMin, yMin, xMax, yMax);
            }
        }
    }
    return accept;
}
void MainWindow::on_Clip_Line_clicked() {
    // Ensure there are at least two points to define the rectangular window
    if (clickedPoints.size() < 2) {
        return;
    }

    /*on_Reset_Screen_Button_clicked();
    if(axis_shown)
        on_showAxis_clicked();
    if(grids_shown)
        on_gridlines_clicked();*/
    // Define the clipping rectangle
    QPoint p1 = clickedPoints[clickedPoints.size() - 2];
    QPoint p2 = clickedPoints[clickedPoints.size() - 1];
    int xMin = std::min(p1.x(), p2.x());
    int yMin = std::min(p1.y(), p2.y());
    int xMax = std::max(p1.x(), p2.x());
    int yMax = std::max(p1.y(), p2.y());

    // Draw the clipping window in blue-green color
    draw_DDA_Line(xMin, yMin, xMin, yMax, 0, 128, 128); // Left
    draw_DDA_Line(xMin, yMax, xMax, yMax, 0, 128, 128); // Top
    draw_DDA_Line(xMax, yMax, xMax, yMin, 0, 128, 128); // Right
    draw_DDA_Line(xMax, yMin, xMin, yMin, 0, 128, 128); // Bottom

    // Clip each line in lineStorage using Cohen-Sutherland
    for (auto line : lineStorage) {
        int x1 = line.x1();
        int y1 = line.y1();
        int x2 = line.x2();
        int y2 = line.y2();
        // Clip the line and, if accepted, draw it
        if (cohenSutherlandClip(x1, y1, x2, y2, xMin, yMin, xMax, yMax)) {
            draw_Bresenham_Line(x1, y1, x2, y2, 50, 0, 100);
            //lekh "X1:"<<x1<<" Y1:"<<y1<<" X2:"<<x2<<" Y2:"<<y2;
        }
    }
}

void MainWindow::on_Clip_Polygon_clicked() {
    // Ensure we have at least two points to define the clipping window
    if (clickedPoints.size() < 2) return;
    QPoint p1 = clickedPoints[clickedPoints.size() - 2];
    QPoint p2 = clickedPoints[clickedPoints.size() - 1];
    // Define the clipping window's bounds
    int xmin = std::min(p1.x(), p2.x());
    int ymin = std::min(p1.y(), p2.y());
    int xmax = std::max(p1.x(), p2.x());
    int ymax = std::max(p1.y(), p2.y());

    QVector<QPoint> final_vertices = polygonVertices;  // Temporary storage for clipped polygon vertices

    // Clip against each boundary (left, right, bottom, top) using Sutherland-Hodgman
    for (int edge = 0; edge < 4; ++edge) {
        QVector<QPoint> clippedPolygon;
        int n = final_vertices.size();

        for (int i = 0; i < n; ++i) {
            QPoint current = final_vertices[i];
            QPoint prev = final_vertices[(i + n - 1) % n];

            bool currInside = inside(current, edge, xmin, ymin, xmax, ymax);
            bool prevInside = inside(prev, edge, xmin, ymin, xmax, ymax);

            if (currInside) {
                if (!prevInside) {  // Entering the clipping boundary
                    clippedPolygon.append(intersect(prev, current, edge, xmin, ymin, xmax, ymax));
                }
                clippedPolygon.append(current);  // Always add the current point if it's inside
            } else if (prevInside) {  // Exiting the clipping boundary
                clippedPolygon.append(intersect(prev, current, edge, xmin, ymin, xmax, ymax));
            }
        }
        final_vertices = clippedPolygon;  // Update vertices for the next edge
    }

    // Clear screen, redraw window, and draw clipped polygon
    //on_Reset_Screen_Button_clicked();
    draw_DDA_Line(xmin, ymin, xmax, ymin, 200, 200, 200); // Bottom edge
    draw_DDA_Line(xmax, ymin, xmax, ymax, 200, 200, 200); // Right edge
    draw_DDA_Line(xmax, ymax, xmin, ymax, 200, 200, 200); // Top edge
    draw_DDA_Line(xmin, ymax, xmin, ymin, 200, 200, 200); // Left edge

    // Draw the clipped polygon in the specified color
    for (int i = 0; i < final_vertices.size(); ++i) {
        int x1 = final_vertices[i].x();
        int y1 = final_vertices[i].y();
        int x2 = final_vertices[(i + 1) % final_vertices.size()].x();
        int y2 = final_vertices[(i + 1) % final_vertices.size()].y();
        draw_Bresenham_Line(x1, y1, x2, y2, 50, 50, 0);
    }
}

// Utility function to check if a point is inside a boundary edge
bool MainWindow::inside(const QPoint &p, int edge, int xmin, int ymin, int xmax, int ymax) {
    switch (edge) {
    case 0: return p.x() >= xmin;  // Left boundary
    case 1: return p.x() <= xmax;  // Right boundary
    case 2: return p.y() >= ymin;  // Bottom boundary
    case 3: return p.y() <= ymax;  // Top boundary
    }
    return false;
}

// Utility function to find intersection point for an edge
QPoint MainWindow::intersect(const QPoint &p1, const QPoint &p2, int edge, int xmin, int ymin, int xmax, int ymax) {
    double x, y;
    int dx = p2.x() - p1.x();
    int dy = p2.y() - p1.y();

    switch (edge) {
    case 0:  // Left
        y = p1.y() + dy * (xmin - p1.x()) / double(dx);
        return QPoint(xmin, int(y));
    case 1:  // Right
        y = p1.y() + dy * (xmax - p1.x()) / double(dx);
        return QPoint(xmax, int(y));
    case 2:  // Bottom
        x = p1.x() + dx * (ymin - p1.y()) / double(dy);
        return QPoint(int(x), ymin);
    case 3:  // Top
        x = p1.x() + dx * (ymax - p1.y()) / double(dy);
        return QPoint(int(x), ymax);
    }
    return QPoint();
}
