#ifndef OBJECTVIEWER_H
#define OBJECTVIEWER_H

#include <QColor>
#include <QOpenGLWidget>
#include <QSettings>
#include <QWidget>

#ifdef __cplusplus
extern "C" {
#endif
#include "../s21_get_data_viewer.h"
#include "../s21_matrix.h"
#ifdef __cplusplus
}
#endif

class ObjectViewer : public QOpenGLWidget {
  Q_OBJECT

 public:
  ObjectViewer(QWidget *parent = nullptr);
  void gl_model_draw();
  void gl_polygon_draw(GLenum gl_type, QColor color, int polygon_number);

  QSettings *settings;
  void settings_load();
  void settings_save();

  data_viewer_t gl_model;
  bool gl_model_loaded = 0;

  // Свойства интерфейса
  QColor color_bg = QColor(50, 50, 50, 0);
  QColor color_v = QColor(255, 0, 0, 0);
  QColor color_f = QColor(0, 255, 0, 0);

  double size_v = 1.0;
  double size_f = 1.0;

  bool draw_vertexes = true;
  bool draw_facets = true;

  bool dotted_lines = false;
  bool central_projection = false;
  bool circle_points = false;

 protected:
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;
};

#endif  // OBJECTVIEWER_H
