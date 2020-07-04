#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMessageBox>
#include <QFileDialog>
#include <QPainter>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

protected:


private slots:
    void on_browseButton_clicked();
    void on_img1_clicked();
    void on_img2_clicked();
    void on_img3_clicked();
    void on_img4_clicked();
    void on_submit_clicked();
    void on_clear_clicked();

private:
    Ui::MainWindow *ui;
	bool canDraw;
	QPixmap* pix;
	QSize imageSize;
	QSize drawSize;
	QPoint drawPos;
};

#endif // MAINWINDOW_H
