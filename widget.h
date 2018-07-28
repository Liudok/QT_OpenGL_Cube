#ifndef WIDGET_H
#define WIDGET_H

#include <QOpenGLWidget>
#include <QMatrix4x4>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLBuffer>


struct VertexData
{
    VertexData(){}
    VertexData(QVector3D p, QVector2D t, QVector3D n) :
        position(p),
        texCoord(t),
        normal(n){}
    QVector3D position;
    QVector2D texCoord;
    QVector3D normal;
};


namespace Ui {
class Widget;
}

class Widget : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QOpenGLTexture *m_texture;
    QOpenGLBuffer m_indexBuffer;
    QMatrix4x4 m_projectionMatrix;
    QOpenGLShaderProgram m_program;
    QOpenGLBuffer m_arrayBuffer;


protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void initShaders();
    void initCube(float width);
};

#endif // WIDGET_H
