#include <iostream>   // output stream
#include <fstream>    // file stream
#include <vector>
#include <algorithm>  // min_element, max_element
#include <numeric>    // accumulate

int main(int argc, char *argv[]) {
  if (argc > 1) {
    using TimeSeriesDataType = int;
    std::ifstream TimeSeriesAsStream(argv[1]);
    std::vector<TimeSeriesDataType> time_series;

    TimeSeriesDataType new_element = 47110815;
    if (TimeSeriesAsStream.is_open()) {
      while (TimeSeriesAsStream.good() && TimeSeriesAsStream >> new_element) {
        time_series.push_back(new_element);
      }

      std::cout << "File : " << argv[1] << std::endl;
      std::cout << "#elements : " << time_series.size() << std::endl;
      std::cout << "Elements : ";
      for (const auto &element : time_series) {
        std::cout << element << " ";
      }
      std::cout << std::endl;
      if (time_series.size() > 0) {
        std::cout << "Min : " << *std::min_element(time_series.begin(), time_series.end()) << std::endl;
        std::cout << "Max : " << *std::max_element(time_series.begin(), time_series.end()) << std::endl;
        std::cout << "Mean : " << std::accumulate(time_series.begin(), time_series.end(), 0.0) / time_series.size() << std::endl;
      }
    } else {
      std::cout << "No such file." << std::endl;
    }
  } else {
    std::cout << "No input file." << std::endl;
  }

  return 0;
}
