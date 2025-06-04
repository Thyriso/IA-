#pragma once

#include <QMainWindow>

class ViewerWidget;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);

private slots:
    void openFile();

private:
    ViewerWidget* viewer_{};
    class SimulationOverlay* overlay_{};
};


