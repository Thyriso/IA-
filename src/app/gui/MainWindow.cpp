#include "MainWindow.h"
#include "ViewerWidget.h"
#include "SimulationOverlay.h"
#include <QMenuBar>
#include <QAction>
#include <QFileDialog>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent) {
    viewer_ = new ViewerWidget(this);
    overlay_ = new SimulationOverlay(this);
    auto container = new QWidget(this);
    auto layout = new QStackedLayout(container);
    layout->setStackingMode(QStackedLayout::StackAll);
    layout->addWidget(viewer_);
    layout->addWidget(overlay_);
    overlay_->setAttribute(Qt::WA_TransparentForMouseEvents);
    setCentralWidget(container);

    auto fileMenu = menuBar()->addMenu(tr("File"));
    auto openAct = fileMenu->addAction(tr("Open"));
    connect(openAct, &QAction::triggered, this, &MainWindow::openFile);
}

void MainWindow::openFile() {
    QString path = QFileDialog::getOpenFileName(
        this, tr("Open Model"), {}, tr("CAD Files (*.stl *.step *.iges)"));
    if (!path.isEmpty()) {
        viewer_->loadMesh(path);
        overlay_->loadPath("output.gcode");
        overlay_->show();
    }
}

