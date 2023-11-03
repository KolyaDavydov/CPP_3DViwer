#include "model.h"
#include <iostream>

#include <sys/stat.h>

#include <cmath>

namespace s21 {

/**
 * @brief конструктор с параметром
 *
 * @param filename путь и название файла
 * 
 * Если вайла нет или ошибка чтения, то 'is_valid_' == 1
 */
Model::Model(std::string filename) {
  file_.open(filename);
  if (file_.is_open()) {
    auto size = GetFileSize(filename);
    vertexes_.reserve(size / 3);
    facets_.reserve(size / 2);
    Parce();
    Close();
  } else {
    is_valid_ = 1;
  }
};



/**
 * @brief парсинг файла
 * Метод Parce в которм происходит основной парсин файла. Построчное чтение,
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

// Получение размера файла для предварительного резервирования векторов под
// массивы vertexes_ и facets_. Это сделано для предотвращения перевыделения
// памяти при добавлении элементов в вектора и выделения излишней памяти.
long Model::GetFileSize(std::string str) {
  struct stat stat_buf;
  int rc = stat(str.c_str(), &stat_buf);
  return rc == 0 ? stat_buf.st_size : -1;
}

/**
 * @brief Считывает координаты вершин в вектор 'vertexes_'
 *
 * @param ss строка-поток из файла для считывания
 * 
 * Паралельно проверяет корректность файла
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

// Считываем расположение грани. Строку подразбиваем на подстроки с номерами
// вершин. Мы создаем массив с закольцованными полигонами, поэтому на один
// полигон выделяется х2 вершин.
/**
 * @brief Считывает расположение граней в 'facets_'
 *
 * @param ss строка-поток из файла для считывания
 * 
 * Паралельно проверяет корректность файла
 * и считает количество полигонов
 */
void Model::ReadFacets(std::stringstream& ss) {
  int count{};
  unsigned int num_dbl{};
  std::string substr, num, first;

    int size_facet{};// !!!

  for (count = 0; ss >> substr; ++count) {
    for (auto it = substr.begin(); it != substr.end() && *it != '/'; ++it) {
      num += *it;
    }
    num_dbl = std::stoi(num) - 1; // !!
    num_dbl = std::stoi(num) - 1;
    facets_.push_back(num_dbl);
    if (count)
      facets_.push_back(num_dbl);
    else
      first = num;
    num = "";
    ++size_facet;// !!!
  }
  if (count < 2) {
    is_valid_ = false;
    ResetValues();
  } else {
    facets_.push_back(std::stoi(first) - 1);
    polygon_size_ += count;
    // polygon_size_ += count * 2; // !!!
    size_facets_.push_back(size_facet); // !!!
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

// функция принимает изменяемую структуру data, значение расстояния на которое
// нужно переместить фигуру и направление в котором нужно переместить direction
// = 0 - x direction = 1 - y direction = 2 - z s21_moving(&data, 2, 0); -
// смещение по х на 2
void Model::moving(double distance, int direction) {
  for (int i = direction; i < this->vertexes_.size(); i +=3) {
    this->vertexes_[i] += distance;
    // std::cout << *i << std::endl;
  }

}

// void Model::scaling(std::vector<double> vertexes_, double scale) {
//     //   for (auto i = vertexes_.begin(); i < vertexes_.end(); ++i) {
//     // *i *= scale;
//     for (int i = 0; i < vertexes_.size(); i++) {
//         vertexes_[i] *= scale;
//         std::cout << i << vertexes_[i] << std::endl;
//     } 
// }

void Model::scaling(double scale) {
    //   for (auto i = vertexes_.begin(); i < vertexes_.end(); ++i) {
    // *i *= scale;
    for (int i = 0; i < this->vertexes_.size(); i++) {
        this->vertexes_[i] *= scale;
        std::cout << i << this->vertexes_[i] << std::endl;
    } 
}

} // s21