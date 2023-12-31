#include "model.h"

#include <sys/stat.h>

#include <cmath>
#include <iostream>

namespace s21 {

/**
 * @brief конструктор с параметром
 *
 * @param filename путь и название файла
 *
 * Если Файла нет или ошибка чтения, то 'is_valid_' == 1
 */
Model::Model(std::string filename) {
  file_.open(filename);
  if (file_.is_open()) {
    auto size = GetFileSize(filename);
    vertexes_.reserve(size / 3);
    facets_.reserve(size / 2);
    Parce();
    Close();
    Normalize();
  } else {
    is_valid_ = 1;
  }
};

/**
 * @brief парсинг файла
 * Метод Parce в которм происходит основной парсинг файла. Построчное чтение,
 * строка передается в поток, где разделяется по пробелам. В зависимости от
 * перовго аргумента, оно воспринимается как вершина или грань, после чего
 * вызываются соответствующие методы их валидации и обработок. Операторы
 * обработки исключений стоят для случаев некорретных данных в .obj файле.
 */
void Model::Parce() {
  std::string str;
  while (getline(file_, str) && is_valid_) {
    std::stringstream ss(str);
    ss >> str;
    try {
      if (str == "v") {
        ReadVertexes(ss);
        ++count_of_vertexes_;
      } else if (str == "f") {
        ReadFacets(ss);
        ++count_of_facets_;
      }
    } catch (...) {
      is_valid_ = false;
      ResetValues();
      std::cout << "Ошибка в файле!!" << std::endl;
    }
  }
};

/**
 * @brief Получение размер файла в байтах
 * @param filename путь и название файла
 * Получение размера файла для предварительного резервирования памяти для
 * векторов vertexes_ и facets_, что бы не происходило постоянного расширения
 * памяти для векторов
 */
long Model::GetFileSize(std::string filename) {
  struct stat stat_buf;
  int rc = stat(filename.c_str(), &stat_buf);
  return rc == 0 ? stat_buf.st_size : -1;
}

/**
 * @brief Считывает координаты вершин в вектор 'vertexes_'
 *
 * @param ss строка-поток из файла для считывания
 *
 * Паралельно проверяет корректность файла
 * считываение происходит попорядку,
 * поэтому размер 'vertexes_' = 3*количество вершин
 */
void Model::ReadVertexes(std::stringstream& ss) {
  int count{};
  double num{};
  for (count = 0; ss >> num; ++count) {
    if (count > 2) is_valid_ = false;
    vertexes_.push_back(num);
    max_coordinate_ = fabs(num) > fabs(max_coordinate_) ? num : max_coordinate_;
  }
  if (count < 3) {
    is_valid_ = false;
    ResetValues();
  }
};

/**
 * @brief Считывает расположение граней в 'facets_'
 *
 * @param ss строка-поток из файла для считывания
 *
 * Паралельно проверяет корректность файла
 * и считает количество полигонов
 * на один полигон из трех вершин выделяется 6 значений
 * (1-2, 2-3, 3-1), а не (1, 2, 3)
 */
void Model::ReadFacets(std::stringstream& ss) {
  int count{};
  unsigned int num_dbl{};
  std::string substr, num, first;
  int size_facet{};
  for (count = 0; ss >> substr; ++count) {
    for (auto it = substr.begin(); it != substr.end() && *it != '/'; ++it) {
      num += *it;
    }
    num_dbl = std::stoi(num) - 1;
    num_dbl = std::stoi(num) - 1;
    facets_.push_back(num_dbl);
    if (count)
      facets_.push_back(num_dbl);
    else
      first = num;
    num = "";
    ++size_facet;
  }
  if (count < 2) {
    is_valid_ = false;
    ResetValues();
  } else {
    facets_.push_back(std::stoi(first) - 1);
    polygon_size_ += count;
    size_facets_.push_back(size_facet);
  }
};

/**
 * @brief обнуляет все значения касательно объекта-модели'
 */
void Model::ResetValues() {
  max_coordinate_ = 0;
  vertexes_.clear();
  facets_.clear();
  is_valid_ = false;
  count_of_facets_ = 0;
  polygon_size_ = 0;
}

/**
 * @brief изменение значений 'vertexes_' - как бы движение вдоль осей
 *
 * @param distance расстояние на которое хотим изменить значения
 * элементов вектора
 * @param direction (0 - X, 1 - Y, 2 - Z) вдоль какой оси хотим совершить
 * перемещение
 */
void Model::Moving(double distance, int direction) {
  for (auto i = direction; i < this->vertexes_.size(); i += 3) {
    this->vertexes_[i] += distance;
    // std::cout << *i << std::endl;
  }
}

/**
 * @brief изменение каждого элемента вектора вершин
 *
 * @param scale во сколько раз хотим изменить размер
 */
void Model::Scaling(double scale) {
  for (auto i = 0; i < this->vertexes_.size(); ++i) {
    this->vertexes_[i] *= scale;
  }
}

/**
 * @brief изменение значений 'vertexes_' для вращения
 *
 * @param angle угол на который хотим повернуть объект
 * элементов вектора
 * @param direction (0 - X, 1 - Y, 2 - Z) вдоль какой оси хотим совершить
 * вращение
 */
void Model::Rotation(double angle, int direction) {
  if (direction == 0) {
    double Y = 0;
    double Z = 0;
    for (long unsigned int i = 0; i < this->vertexes_.size(); ++i) {
      if (i % 3 == 0) {
        Y = this->vertexes_[i + 1];
        Z = this->vertexes_[i + 2];
        this->vertexes_[i + 1] = Y * cos(angle) + Z * sin(angle);
        this->vertexes_[i + 2] = (-Y) * sin(angle) + Z * cos(angle);
      }
    }
  }
  if (direction == 1) {
    double X = 0;
    double Z = 0;
    for (long unsigned int i = 0; i < this->vertexes_.size(); ++i) {
      if (i % 3 == 0) {
        X = this->vertexes_[i];
        Z = this->vertexes_[i + 2];
        this->vertexes_[i] = X * cos(angle) + Z * sin(angle);
        this->vertexes_[i + 2] = (-X) * sin(angle) + Z * cos(angle);
      }
    }
  }
  if (direction == 2) {
    double X = 0;
    double Y = 0;
    for (long unsigned int i = 0; i < this->vertexes_.size(); ++i) {
      if (i % 3 == 0) {
        X = this->vertexes_[i];
        Y = this->vertexes_[i + 1];
        this->vertexes_[i] = X * cos(angle) + Y * sin(angle);
        this->vertexes_[i + 1] = (-X) * sin(angle) + Y * cos(angle);
      }
    }
  }
}

/**
 * @brief нормализация объекта, что б сразу при открытии
 * поместился на экран приложения. Если самое большое значение
 * вершин выше 1, то уменьшяет все координаты пропорционально
 */
void Model::Normalize() { Scaling(1 / max_coordinate_); }
}  // namespace s21