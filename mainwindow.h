#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    class Vertex;
protected:
    bool eventFilter(QObject *watched, QEvent *event) override;
private slots:
    void on_showAxis_clicked();

    void on_gridlines_clicked();

    void on_DDA_Button_clicked();

    void on_Bresenham_Button_clicked();

    void on_Polar_Circle_Button_clicked();

    void on_Bresenham_Circle_Button_clicked();

    void on_Cartesian_Circle_Button_clicked();

    void on_Reset_Screen_Button_clicked();

    void on_Polar_Ellipse_Button_clicked();

    void on_Bresenham_Ellipse_Button_clicked();

    void on_Polygon_Button_clicked();

    void on_Polygon_Scanline_Fill_clicked();

    void on_Flood_Fill_clicked();

    void on_Boundary_Fill_clicked();

    void on_Translate_Button_clicked();

    void on_Shear_Button_clicked();

    void on_Scale_Button_clicked();

    void on_Reflect_X_clicked();

    void on_Reflect_Y_clicked();

    void on_Rotate_AC_Button_clicked();

    void on_Scale_Button_AP_clicked();

    void on_Reflect_AL_clicked();

    void on_Rotate_AC_Button_AP_clicked();

    void on_Clip_Line_clicked();

    void on_Clip_Polygon_clicked();

private:
    Ui::MainWindow *ui;
    void delay(int ms);
    void colorPointAbsolute(int x,int y,int r,int g, int b, int penwidth);
    void colorPointRelative(int x,int y,int r,int g, int b);
    void draw_DDA_Line(float x1, float y1, float x2, float y2, int r, int g, int b);
    QSet<QPoint> make_Bresenham_Line(int x1, int y1, int x2, int y2);
    void draw_Bresenham_Line(int x1, int y1, int x2, int y2, int r, int g, int b);
    QPoint clickedPoint;
    QVector<QPoint> clickedPoints; // To store clicked points
    void drawCirclePoints(int x, int y, int pixelCenterX, int pixelCenterY, int r, int g, int b, int gridOffset);
    void drawEllipsePoints(int x, int y, int pixelCenterX, int pixelCenterY, int r, int g, int b, int gridOffset);
    QHash<QPoint, QVector<QPoint>> make_polygon(int n);
    void draw_polygon(int r, int g, int b);
    QSet<QPoint> allPolygonPoints;
    QColor getPixelColor(int x, int y);
    QColor lastColor;
    int gridOffset;
    int width;
    int height;
    int centerX;
    int centerY;
    QVector<QLine> lineStorage;
    QHash<QPoint, QVector<QPoint>> belongsToEdge;
    QVector<QPoint> polygonVertices;
    bool inside(const QPoint &p, int edge, int xmin, int ymin, int xmax, int ymax);
    QPoint intersect(const QPoint &p1, const QPoint &p2, int edge, int xmin, int ymin, int xmax, int ymax);
};
#endif // MAINWINDOW_H
