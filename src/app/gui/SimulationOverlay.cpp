#include "SimulationOverlay.h"
#include <QOpenGLFunctions>
#include <QFile>

SimulationOverlay::SimulationOverlay(QWidget* parent)
    : QOpenGLWidget(parent) {}

void SimulationOverlay::loadPath(const QString& path) {
    path_.clear();
    QFile f(path);
    if (f.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream ts(&f);
        while (!ts.atEnd()) {
            const QString line = ts.readLine();
            QRegExp rx("[XY]([\-0-9\.]+)");
            double x = 0, y = 0;
            if (line.contains('X')) {
                int idx = line.indexOf('X');
                x = line.mid(idx + 1).split(QRegExp("[ \tY]")).first().toDouble();
            }
            if (line.contains('Y')) {
                int idx = line.indexOf('Y');
                y = line.mid(idx + 1).split(QRegExp("[ \tX]")).first().toDouble();
            }
            if (line.startsWith("G")) {
                path_.append(QPointF(x, y));
            }
        }
    }
    update();
}

void SimulationOverlay::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(0, 0, 0, 0);
}

void SimulationOverlay::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if (path_.isEmpty())
        return;
    QOpenGLFunctions* f = QOpenGLContext::currentContext()->functions();
    QVector<GLfloat> verts;
    verts.reserve(path_.size() * 2);
    for (const QPointF& p : path_) {
        verts << p.x() << p.y();
    }
    f->glEnableClientState(GL_VERTEX_ARRAY);
    f->glVertexPointer(2, GL_FLOAT, 0, verts.constData());
    f->glDrawArrays(GL_LINE_STRIP, 0, verts.size() / 2);
    f->glDisableClientState(GL_VERTEX_ARRAY);
}

