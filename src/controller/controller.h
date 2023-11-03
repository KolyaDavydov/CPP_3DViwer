#ifndef CPP_3DVIEWER_SRC_CONTROLLER_CONTROLLER_H_
#define CPP_3DVIEWER_SRC_CONTROLLER_CONTROLLER_H_

#include "../model/model.h"

namespace s21 {
class Controller {
 public:
  Controller() : model_{} {};
  Controller(std::string filename) { model_ = Model(filename); };

  double GetMaxCoordinate() const noexcept {
    return model_.GetMaxCoordinate();
  };
  std::vector<double> GetVertexes() const noexcept {
    return model_.GetVertexes();
  };
  std::vector<unsigned int> GetFacets() const noexcept {
    return model_.GetFacets();
  };
  std::size_t GetCountOfFacets() const noexcept {
    return model_.GetCountOfFacets();
  }
  std::size_t GetCountOfVertexes() const noexcept {
    return model_.GetCountOfVertexes();
  }
  std::size_t GetPolygonSize() const noexcept {
    return model_.GetPolygonSize();
  };
  bool IsValid() const noexcept { return model_.IsValid(); };
  std::vector<unsigned int> GetSizeFacets() const noexcept {
    return model_.GetSizeFacets();
  };

  void Moving(double distance, int direction) {
    model_.Moving(distance, direction);
  }
  void Scaling(double scale) { model_.Scaling(scale); }
  void Rotation(double angle, int direction) {
    model_.Rotation(angle, direction);
  }
  void Normalize() { model_.Normalize(); }

 private:
  Model model_;
};
};      // namespace s21
#endif  // CPP_3DVIEWER_SRC_CONTROLLER_CONTROLLER_H_