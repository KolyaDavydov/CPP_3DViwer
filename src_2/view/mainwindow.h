#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCloseEvent>
#include <QColor>
#include <QColorDialog>
#include <QFileDialog>
#include <QMainWindow>
#include <QThread>
#include <QTime>

#define GIF_WIDTH 640
#define GIF_HIGHT 480

#ifdef __cplusplus
extern "C" {
#endif
#include "../s21_get_data_viewer.h"
#include "../s21_matrix.h"
#ifdef __cplusplus
}
#endif

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  QVector<QImage> image_array;

 protected:
  void closeEvent(QCloseEvent *event) override;

 private slots:
  void on_pushButton_open_clicked();

  void on_pushButton_moveX_minus_clicked();

  void on_pushButton_moveX_plus_clicked();

  void on_pushButton_moveY_minus_clicked();

  void on_pushButton_moveY_plus_clicked();

  void on_pushButton_moveZ_minus_clicked();

  void on_pushButton_moveZ_plus_clicked();

  void on_pushButton_rotateX_plus_clicked();

  void on_pushButton_rotateX_minus_clicked();

  void on_pushButton_rotateY_minus_clicked();

  void on_pushButton_rotateY_plus_clicked();

  void on_pushButton_rotateZ_minus_clicked();

  void on_pushButton_rotateZ_plus_clicked();

  void on_pushButton_scale_minus_clicked();

  void on_pushButton_scale_plus_clicked();

  void on_pushButton_scale_clicked();

  void on_pushButton_color_background_clicked();

  void on_pushButton_color_v_clicked();

  void on_pushButton_color_f_clicked();

  void on_pushButton_sizeV_ok_clicked();

  void on_pushButton_sizeF_ok_clicked();

  void on_checkBox_drawV_stateChanged(int arg1);

  void on_checkBox_drawF_stateChanged(int arg1);

  void on_pushButton_take_screenshoot_clicked();

  void on_pushButton_screencast_clicked();

  void on_checkBox_dotted_stateChanged(int arg1);

  void on_checkBox_central_projection_stateChanged(int arg1);

  void on_checkBox_circle_vertex_stateChanged(int arg1);

 private:
  Ui::MainWindow *ui;
  void button_setColor(QPushButton *pushButton, QColor color);
};
#endif  // MAINWINDOW_H
