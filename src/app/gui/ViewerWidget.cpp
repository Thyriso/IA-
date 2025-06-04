#include "ViewerWidget.h"
#include <QMouseEvent>
#include <QOpenGLFunctions>

ViewerWidget::ViewerWidget(QWidget* parent)
    : QOpenGLWidget(parent) {
    rotation_.setToIdentity();
}

void ViewerWidget::loadMesh(const QString& path) {
    hasMesh_ = kernel_.loadModel(path.toStdString().c_str());
    update();
}

void ViewerWidget::initializeGL() {
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.1f, 0.1f, 0.1f, 1.f);
}

void ViewerWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if (!hasMesh_)
        return;

    // For now simply draw the bounding box as lines
    QOpenGLFunctions* f = QOpenGLContext::currentContext()->functions();
    auto box = kernel_.getBoundingBox();
    GLfloat verts[] = {
        (GLfloat)box.minX, (GLfloat)box.minY, (GLfloat)box.minZ,
        (GLfloat)box.maxX, (GLfloat)box.minY, (GLfloat)box.minZ,
        (GLfloat)box.maxX, (GLfloat)box.maxY, (GLfloat)box.minZ,
        (GLfloat)box.minX, (GLfloat)box.maxY, (GLfloat)box.minZ,
        (GLfloat)box.minX, (GLfloat)box.minY, (GLfloat)box.maxZ,
        (GLfloat)box.maxX, (GLfloat)box.minY, (GLfloat)box.maxZ,
        (GLfloat)box.maxX, (GLfloat)box.maxY, (GLfloat)box.maxZ,
        (GLfloat)box.minX, (GLfloat)box.maxY, (GLfloat)box.maxZ
    };
    static const GLuint indices[] = {
        0,1,1,2,2,3,3,0,
        4,5,5,6,6,7,7,4,
        0,4,1,5,2,6,3,7
    };
    f->glMatrixMode(GL_MODELVIEW);
    QMatrix4x4 m = rotation_;
    m.translate(translation_);
    m.scale(zoom_);
    f->glLoadMatrixf(m.constData());
    f->glEnableClientState(GL_VERTEX_ARRAY);
    f->glVertexPointer(3, GL_FLOAT, 0, verts);
    f->glDrawElements(GL_LINES, 24, GL_UNSIGNED_INT, indices);
    f->glDisableClientState(GL_VERTEX_ARRAY);
}

void ViewerWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
}

void ViewerWidget::mousePressEvent(QMouseEvent* event) {
    lastPos_ = event->pos();
    if(event->button() == Qt::RightButton)
        panning_ = true;
}

void ViewerWidget::mouseMoveEvent(QMouseEvent* event) {
    QPoint delta = event->pos() - lastPos_;
    lastPos_ = event->pos();
    if(panning_) {
        translation_.setX(translation_.x() + delta.x() / 100.0f);
        translation_.setY(translation_.y() - delta.y() / 100.0f);
    } else {
        rotation_.rotate(delta.x(), 0.f, 1.f, 0.f);
        rotation_.rotate(delta.y(), 1.f, 0.f, 0.f);
    }
    update();
}

void ViewerWidget::mouseReleaseEvent(QMouseEvent* event) {
    if(event->button() == Qt::RightButton)
        panning_ = false;
}

void ViewerWidget::wheelEvent(QWheelEvent* event) {
    zoom_ += event->angleDelta().y() / 1200.0f;
    if (zoom_ < 0.1f) zoom_ = 0.1f;
    update();
}


