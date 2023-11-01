#include "mainwindow.h"

#include "qgifimage.h"
#include "ui_mainwindow.h"

void delay(int millisecondsToWait) {
  QTime dieTime = QTime::currentTime().addMSecs(millisecondsToWait);
  while (QTime::currentTime() < dieTime) {
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
  }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // Установка свойств элементов

  button_setColor(ui->pushButton_color_background, ui->widget->color_bg);
  button_setColor(ui->pushButton_color_v, ui->widget->color_v);
  button_setColor(ui->pushButton_color_f, ui->widget->color_f);

  ui->lineEdit_sizeV->setText(QString("%1").arg(ui->widget->size_v));
  ui->lineEdit_sizeF->setText(QString("%1").arg(ui->widget->size_f));

  ui->checkBox_drawV->setChecked(ui->widget->draw_vertexes);
  ui->checkBox_drawF->setChecked(ui->widget->draw_facets);
  ui->checkBox_dotted->setChecked(ui->widget->dotted_lines);
  ui->checkBox_central_projection->setChecked(ui->widget->central_projection);
  ui->checkBox_circle_vertex->setChecked(ui->widget->circle_points);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_open_clicked() {
  QString file_name = QFileDialog::getOpenFileName(
      this, tr("Открыть модель"), "../Objects", "Объектные файлы (*.obj)");
  if (!file_name.isEmpty() && !file_name.isNull()) {
    QByteArray file_name_ba = file_name.toLocal8Bit();
    char *file_name_char = file_name_ba.data();

    int error = 0;
    ui->widget->gl_model = s21_get_data_viewer(file_name_char, &error);
    if (!error) {
      ui->widget->gl_model_loaded = true;
      ui->widget->update();
      ui->label_fileName->setText(file_name);
      ui->label_countV->setText(
          QString("%1").arg(ui->widget->gl_model.number_v));
      ui->label_countF->setText(
          QString("%1").arg(ui->widget->gl_model.number_facets_all));
    }
  }
}

void MainWindow::on_pushButton_moveX_minus_clicked() {
  if (ui->widget->gl_model_loaded) {
    double X = (-1) * ui->lineEdit_move->text().toDouble();
    s21_moving(&ui->widget->gl_model, X, 0);
    ui->widget->update();
  }
}

void MainWindow::on_pushButton_moveX_plus_clicked() {
  if (ui->widget->gl_model_loaded) {
    double X = ui->lineEdit_move->text().toDouble();
    s21_moving(&ui->widget->gl_model, X, 0);
    ui->widget->update();
  }
}

void MainWindow::on_pushButton_moveY_minus_clicked() {
  if (ui->widget->gl_model_loaded) {
    double Y = (-1) * ui->lineEdit_move->text().toDouble();
    s21_moving(&ui->widget->gl_model, Y, 1);
    ui->widget->update();
  }
}

void MainWindow::on_pushButton_moveY_plus_clicked() {
  if (ui->widget->gl_model_loaded) {
    double Y = ui->lineEdit_move->text().toDouble();
    s21_moving(&ui->widget->gl_model, Y, 1);
    ui->widget->update();
  }
}

void MainWindow::on_pushButton_moveZ_minus_clicked() {
  if (ui->widget->gl_model_loaded) {
    double Z = (-1) * ui->lineEdit_move->text().toDouble();
    s21_moving(&ui->widget->gl_model, Z, 2);
    ui->widget->update();
  }
}

void MainWindow::on_pushButton_moveZ_plus_clicked() {
  if (ui->widget->gl_model_loaded) {
    double Z = ui->lineEdit_move->text().toDouble();
    s21_moving(&ui->widget->gl_model, Z, 2);
    ui->widget->update();
  }
}

void MainWindow::on_pushButton_rotateX_plus_clicked() {
  if (ui->widget->gl_model_loaded) {
    double angle = ui->lineEdit_rotate->text().toDouble();
    s21_rotation(&ui->widget->gl_model, angle, 0);
    ui->widget->update();
  }
}

void MainWindow::on_pushButton_rotateX_minus_clicked() {
  if (ui->widget->gl_model_loaded) {
    double angle = (-1) * ui->lineEdit_rotate->text().toDouble();
    s21_rotation(&ui->widget->gl_model, angle, 0);
    ui->widget->update();
  }
}

void MainWindow::on_pushButton_rotateY_plus_clicked() {
  if (ui->widget->gl_model_loaded) {
    double angle = ui->lineEdit_rotate->text().toDouble();
    s21_rotation(&ui->widget->gl_model, angle, 1);
    ui->widget->update();
  }
}

void MainWindow::on_pushButton_rotateY_minus_clicked() {
  if (ui->widget->gl_model_loaded) {
    double angle = (-1) * ui->lineEdit_rotate->text().toDouble();
    s21_rotation(&ui->widget->gl_model, angle, 1);
    ui->widget->update();
  }
}

void MainWindow::on_pushButton_rotateZ_plus_clicked() {
  if (ui->widget->gl_model_loaded) {
    double angle = ui->lineEdit_rotate->text().toDouble();
    s21_rotation(&ui->widget->gl_model, angle, 2);
    ui->widget->update();
  }
}

void MainWindow::on_pushButton_rotateZ_minus_clicked() {
  if (ui->widget->gl_model_loaded) {
    double angle = (-1) * ui->lineEdit_rotate->text().toDouble();
    s21_rotation(&ui->widget->gl_model, angle, 2);
    ui->widget->update();
  }
}

void MainWindow::on_pushButton_scale_minus_clicked() {
  if (ui->widget->gl_model_loaded) {
    s21_scaling(&ui->widget->gl_model, 0.5);
    ui->widget->update();
  }
}

void MainWindow::on_pushButton_scale_plus_clicked() {
  if (ui->widget->gl_model_loaded) {
    s21_scaling(&ui->widget->gl_model, 2);
    ui->widget->update();
  }
}

void MainWindow::on_pushButton_scale_clicked() {
  if (ui->widget->gl_model_loaded) {
    double scale = ui->lineEdit_scale->text().toDouble();
    if (scale != 0) s21_scaling(&ui->widget->gl_model, scale);
    ui->widget->update();
  }
}

void MainWindow::on_pushButton_color_background_clicked() {
  QColor color = QColorDialog::getColor(Qt::white, this, "Выбор цвета точек");
  if (color.isValid()) {
    ui->widget->color_bg = color;
    ui->widget->update();

    button_setColor(ui->pushButton_color_background, color);
  }
}

void MainWindow::on_pushButton_color_v_clicked() {
  QColor color = QColorDialog::getColor(Qt::white, this, "Выбор цвета точек");
  if (color.isValid()) {
    ui->widget->color_v = color;
    ui->widget->update();

    button_setColor(ui->pushButton_color_v, color);
  }
}

void MainWindow::on_pushButton_color_f_clicked() {
  QColor color = QColorDialog::getColor(Qt::white, this, "Выбор цвета точек");
  if (color.isValid()) {
    ui->widget->color_f = color;
    ui->widget->update();

    button_setColor(ui->pushButton_color_f, color);
  }
}

void MainWindow::button_setColor(QPushButton *pushButton, QColor color) {
  int color_red = 0;
  int color_green = 0;
  int color_blue = 0;
  color.getRgb(&color_red, &color_green, &color_blue);
  QString color_font = "color: black;";
  if (color_red < 128 && color_green < 128 && color_blue < 128)
    color_font = "color: white;";
  QString qss =
      QString("QPushButton {background-color: rgb(%1, %2, %3); %4}")
          .arg(QString::number(color_red), QString::number(color_green),
               QString::number(color_blue), color_font);
  pushButton->setStyleSheet(qss);
}

void MainWindow::on_pushButton_sizeV_ok_clicked() {
  ui->widget->size_v = ui->lineEdit_sizeV->text().toDouble();
  ui->widget->update();
}

void MainWindow::on_pushButton_sizeF_ok_clicked() {
  ui->widget->size_f = ui->lineEdit_sizeF->text().toDouble();
  ui->widget->update();
}

void MainWindow::on_checkBox_drawV_stateChanged(int arg1) {
  if (arg1)
    ui->widget->draw_vertexes = true;
  else
    ui->widget->draw_vertexes = false;
  ui->widget->update();
}

void MainWindow::on_checkBox_drawF_stateChanged(int arg1) {
  if (arg1)
    ui->widget->draw_facets = true;
  else
    ui->widget->draw_facets = false;
  ui->widget->update();
  image_array.push_back(ui->widget->grab().toImage());
}

void MainWindow::on_pushButton_take_screenshoot_clicked() {
  QFileDialog::Options options;
  QString selectedFilter;

  QString fileName = "";

  fileName = QFileDialog::getSaveFileName(
      this, "Save Image", ".", "BMP Files (*.bmp);;JPG Files (*.jpg)",
      &selectedFilter, options);

  if (fileName.length() == 0) return;

  QImage ui_img = ui->widget->grab().toImage();
  ui_img.save(fileName);
}

void MainWindow::on_pushButton_screencast_clicked() {
  QFileDialog::Options options;
  QString selectedFilter;
  QString fileName = "";
  ui->pushButton_screencast->setEnabled(false);
  ui->pushButton_take_screenshoot->setEnabled(false);
  ui->pushButton_open->setEnabled(false);
  QGifImage gif;
  gif.setDefaultDelay(100);
  for (int i = 0; i < 50; i++) {
    image_array.push_back(ui->widget->grab().toImage());
    delay(100);
  }

  ui->pushButton_screencast->setEnabled(true);
  ui->pushButton_take_screenshoot->setEnabled(true);
  ui->pushButton_open->setEnabled(true);

  fileName = QFileDialog::getSaveFileName(
      this, "Save Screencast", ".", "GIF Files (*.gif);;GIF Files (*.gif)",
      &selectedFilter, options);

  if (fileName.length() == 0) return;

  for (QVector<QImage>::Iterator img = image_array.begin();
       img != image_array.end(); ++img) {
    gif.addFrame(img->scaled(GIF_WIDTH, GIF_HIGHT, Qt::IgnoreAspectRatio));
  }
  gif.save(fileName);
}

void MainWindow::on_checkBox_dotted_stateChanged(int arg1) {
  if (arg1)
    ui->widget->dotted_lines = true;
  else
    ui->widget->dotted_lines = false;
  ui->widget->update();
}

void MainWindow::on_checkBox_central_projection_stateChanged(int arg1) {
  if (arg1)
    ui->widget->central_projection = true;
  else
    ui->widget->central_projection = false;
  ui->widget->update();
}

void MainWindow::on_checkBox_circle_vertex_stateChanged(int arg1) {
  if (arg1)
    ui->widget->circle_points = true;
  else
    ui->widget->circle_points = false;
  ui->widget->update();
}

void MainWindow::closeEvent(QCloseEvent *event) {
  ui->widget->settings_save();
  if (ui->widget->gl_model_loaded)
    s21_remove_data_viewer(&ui->widget->gl_model);
  event->accept();
}
