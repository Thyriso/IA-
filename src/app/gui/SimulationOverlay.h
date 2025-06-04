#pragma once

// Overlay widget responsible for displaying the simulated toolpath.
// It simply renders the motion path as GL lines.

#include <QOpenGLWidget>

class SimulationOverlay : public QOpenGLWidget {
    Q_OBJECT
public:
    explicit SimulationOverlay(QWidget* parent = nullptr);

    // Load a simple G-code file and extract XY moves for display.
    void loadPath(const QString& path);

protected:
    void initializeGL() override;
    void paintGL() override;

private:
    QVector<QPointF> path_;
};

