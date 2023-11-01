#include "objectviewer.h"

ObjectViewer::ObjectViewer(QWidget *parent) : QOpenGLWidget{parent} {
  settings = new QSettings(this);
  settings_load();
}

void ObjectViewer::initializeGL() {}

void ObjectViewer::resizeGL(int w, int h) { glViewport(0, 0, w, h); }

void ObjectViewer::paintGL() {
  glClearColor(this->color_bg.red() / 255.0, this->color_bg.green() / 255.0,
               this->color_bg.blue() / 255.0, 0);
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (central_projection) glFrustum(-2, 2, -2, 2, 1, 10);
  if (gl_model_loaded) gl_model_draw();
}

void ObjectViewer::gl_model_draw() {
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glPointSize(this->size_v);
  glLineWidth(this->size_f);

  if (this->dotted_lines) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00ff);
  } else {
    glDisable(GL_LINE_STIPPLE);
  }

  if (this->circle_points) {
    glEnable(GL_POINT_SMOOTH);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
  } else {
    glDisable(GL_POINT_SMOOTH);
  }

  for (int i = 0; i < gl_model.number_f; i++) {
    if (this->draw_vertexes) gl_polygon_draw(GL_POINTS, this->color_v, i);
    if (this->draw_facets) gl_polygon_draw(GL_LINE_LOOP, this->color_f, i);
  }
}

void ObjectViewer::gl_polygon_draw(GLenum gl_type, QColor color,
                                   int polygon_number) {
  glBegin(gl_type);
  glColor3f(color.red() / 255.0, color.green() / 255.0, color.blue() / 255.0);
  for (int j = 0; j < gl_model.polygons[polygon_number].number_v_in_facets;
       j++) {
    unsigned number = gl_model.polygons[polygon_number].v_in_facets[j] - 1;
    glVertex3d(gl_model.matrix.matrix[number][0],
               gl_model.matrix.matrix[number][1],
               gl_model.matrix.matrix[number][2]);
  }
  glEnd();
}

void ObjectViewer::settings_save() {
  this->settings->setValue("color_bg", this->color_bg);
  this->settings->setValue("color_v", this->color_v);
  this->settings->setValue("color_f", this->color_f);

  this->settings->setValue("size_v", this->size_v);
  this->settings->setValue("size_f", this->size_f);

  this->settings->setValue("draw_vertexes", this->draw_vertexes);
  this->settings->setValue("draw_facets", this->draw_facets);
  this->settings->setValue("dotted_lines", this->dotted_lines);
  this->settings->setValue("central_projection", this->central_projection);
  this->settings->setValue("circle_points", this->circle_points);
}

void ObjectViewer::settings_load() {
  QVariant color_bg_setting =
      settings->value("color_bg", QColor(50, 50, 50, 0));
  this->color_bg = color_bg_setting.value<QColor>();

  QVariant color_v_setting = settings->value("color_v", QColor(255, 0, 0, 0));
  this->color_v = color_v_setting.value<QColor>();

  QVariant color_f_setting = settings->value("color_f", QColor(0, 255, 0, 0));
  this->color_f = color_f_setting.value<QColor>();

  this->size_v = this->settings->value("size_v", 2.0).toDouble();
  this->size_f = this->settings->value("size_f", 1.0).toDouble();

  this->draw_vertexes = this->settings->value("draw_vertexes", true).toBool();
  this->draw_facets = this->settings->value("draw_facets", true).toBool();
  this->dotted_lines = this->settings->value("dotted_lines", false).toBool();
  this->central_projection =
      this->settings->value("central_projection", false).toBool();
  this->circle_points = this->settings->value("circle_points", false).toBool();
}
