#ifndef CPP_3DVIEWER_SRC_MODEL_MODEL_H_
#define CPP_3DVIEWER_SRC_MODEL_MODEL_H_

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

namespace s21 {
class Model {
    public:
        Model() = default;
        Model(std::string filename);

        double GetMaxCoordinate() const noexcept { return max_coordinate_; };
        std::vector<double> GetVertexes() const noexcept { return vertexes_; };
        std::vector<unsigned int> GetFacets() const noexcept { return facets_; };
        std::size_t GetCountOfFacets() const noexcept { return count_of_facets_; }
        std::size_t GetCountOfVertexes() const noexcept { return count_of_vertexes_; }
        std::size_t GetPolygonSize() const noexcept { return polygon_size_; };
        bool IsValid() const noexcept { return is_valid_; };

        std::vector<unsigned int> GetSizeFacets() const noexcept {return size_facets_; };// !!!
    private:
    int error{0};


 public:
    void moving(double distance, int direction);
    // void scaling(std::vector<double> vertexes_, double scale);
    void scaling(double scale);
    void rotation(double angle, int direction);
    void normalize();


 private:
  std::ifstream file_{};
  double max_coordinate_{};
  std::vector<double> vertexes_{};
  std::vector<unsigned int> facets_{};
  bool is_valid_{true};
  std::size_t count_of_facets_{};
  std::size_t count_of_vertexes_{};
  std::size_t polygon_size_{};

  std::vector<unsigned int> size_facets_{};// !!!

  double rotateX_ = 0;
  double rotateY_ = 0;
  double rotateZ_ = 0;

  void Close() {
    if (file_.is_open()) file_.close();
  };
  void Parce();
  long GetFileSize(std::string str);
  void ReadVertexes(std::stringstream& ss);
  void ReadFacets(std::stringstream& ss);
  void ResetValues();
};
}; // s21
#endif // CPP_3DVIEWER_SRC_MODEL_MODEL_H_