#pragma once

#include <QOpenGLWidget>
#include <QMatrix4x4>
#include "core/geometry/Kernel.h"
#include <QPoint>
#include <QVector3D>

class ViewerWidget : public QOpenGLWidget {
    Q_OBJECT
public:
    explicit ViewerWidget(QWidget* parent = nullptr);

    // Load a mesh from disk using the Geometry module.
    // In the future this will take a structured mesh object instead of a path.
    void loadMesh(const QString& path);

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;

private:
    Geometry::Kernel kernel_;
    bool hasMesh_{false};
    float zoom_{1.0f};
    QPoint lastPos_;
    QMatrix4x4 rotation_;
    QVector3D translation_{0.f, 0.f, 0.f};
    bool panning_{false};
};

