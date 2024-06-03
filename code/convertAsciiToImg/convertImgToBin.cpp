#include <opencv2/opencv.hpp>
#include <fstream>

int main() {
    // Load the image
    cv::Mat img = cv::imread("input.jpg", cv::IMREAD_GRAYSCALE);
    if (img.empty()) {
        std::cerr << "Failed to open image\n";
        return -1;
    }

    // Open the output file in binary mode
    std::ofstream outFile("output.foo", std::ios::binary);
    if (!outFile) {
        std::cerr << "Failed to open output file\n";
        return -1;
    }

    // Write the width and height to the output file
    int width = img.cols;
    int height = img.rows;
    outFile.write(reinterpret_cast<const char*>(&width), sizeof(width));
    outFile.write(reinterpret_cast<const char*>(&height), sizeof(height));

    // Write the pixel data to the output file
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            unsigned char pixel = img.at<unsigned char>(y, x);
            outFile.write(reinterpret_cast<const char*>(&pixel), sizeof(pixel));
        }
    }

    // Close the output file
    outFile.close();

    return 0;
}