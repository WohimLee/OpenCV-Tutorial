#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;

int main(int argc, char** argv){
    std::string image_path = "./workspace/scene-Iron-Man.jpg";
    Mat img = imread(image_path, IMREAD_COLOR);
    if(img.empty()){
        std::cout << "Could not read the image: " << image_path << std::endl;
        return 1;
    }

    imwrite("./workspace/output.png", img);

    return 0;
}