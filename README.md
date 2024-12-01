---

## **Qt_Beginner**

This project is designed to demonstrate fundamental concepts and techniques in computer graphics using the Qt framework. It is a beginner-friendly project created to learn and explore graphical algorithms for drawing and manipulating shapes such as lines, circles, ellipses, and polygons, as well as performing transformations and clipping operations.

---

## **Features**

### **Line Drawing**
- **DDA Line Algorithm**
- **Bresenham Line Algorithm**

### **Circle Drawing**
- **Polar Circle Algorithm**
- **Bresenham Circle Algorithm**
- **Cartesian Circle Algorithm**

### **Ellipse Drawing**
- **Polar Ellipse Algorithm**
- **Bresenham Ellipse Algorithm**

### **Polygon Drawing**
- Interactive polygon creation using clicked points.
- Polygon Scanline Filling Algorithm.

### **Filling Algorithms**
- **Flood Fill** (with selectable connectivity: 4 or 8).
- **Boundary Fill** (color-based).

### **Transformations**
- **Translation**: Move shapes to a new position.
- **Scaling**: Enlarge or shrink shapes.
- **Shearing**: Distort shapes along X or Y axes.
- **Reflection**:
  - About X-axis
  - About Y-axis
  - About arbitrary lines.
- **Rotation**:
  - Around the origin.
  - Around arbitrary points.

### **Clipping**
- **Line Clipping**: Using the Cohen-Sutherland algorithm.
- **Polygon Clipping**: Using the Sutherland-Hodgman algorithm.

---

## **Code Structure**

### **Key Variables**
- `clickedPoints`: Stores points clicked on the canvas.
- `lineStorage`: Stores lines drawn, used for clipping operations.
- `polygonVertices`: Stores vertices of the polygon being drawn or manipulated.

### **Key Functions**
- **Drawing Functions**: 
  - `draw_DDA_Line()`
  - `draw_Bresenham_Line()`
  - `drawCirclePoints()`
  - `drawEllipsePoints()`
  - `draw_polygon()`
- **Transformations**:
  - `on_Translate_Button_clicked()`
  - `on_Scale_Button_clicked()`
  - `on_Rotate_AC_Button_clicked()`
- **Clipping Algorithms**:
  - `on_Clip_Line_clicked()`
  - `on_Clip_Polygon_clicked()`

---

## **Learning Objectives**
This project is ideal for those new to graphics programming. By working on this project, you will learn:
1. Fundamental algorithms for drawing and filling.
2. How to handle user inputs for interactive graphics.
3. Implementing transformations using homogeneous coordinates.
4. Advanced concepts like clipping for lines and polygons.

---

## **Credits**
This project was developed as a hands-on learning experience for computer graphics programming using Qt. Contributions and feedback are welcome!

---

## **Future Enhancements**
- Add support for Bezier curves and splines.
- Implement 3D graphics transformations and projections.
- Support exporting and importing graphical scenes. 

---
