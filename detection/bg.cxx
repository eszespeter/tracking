#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>
 
int main(int argc, char *argv[])
{
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " in.file out.file" << std::endl;
        return -1;
    }

    cv::Mat frame;
    cv::Mat back;
    cv::Mat fore;
    std::cerr << "opening " << argv[1] << std::endl;
    cv::VideoCapture cap(argv[1]);
    cv::BackgroundSubtractorMOG2 bg;
    //bg.nmixtures = 3;
    //bg.bShadowDetection = false;

    cv::VideoWriter output;
    int ex = static_cast<int>(cap.get(CV_CAP_PROP_FOURCC));
    ex = CV_FOURCC('P','I','M','1');
    cv::Size size = cv::Size((int) cap.get(CV_CAP_PROP_FRAME_WIDTH),
                             (int) cap.get(CV_CAP_PROP_FRAME_HEIGHT));
    std::cerr << "saving to " << argv[2] << std::endl;
    output.open(argv[2], ex, cap.get(CV_CAP_PROP_FPS), size, true);
 
    std::vector<std::vector<cv::Point> > contours;
 
    cv::namedWindow("Frame");
    cv::namedWindow("Background");
 
    for(;;)
    {
        cap >> frame;
        bg.operator ()(frame,fore);
        bg.getBackgroundImage(back);
        cv::erode(fore,fore,cv::Mat());
        cv::dilate(fore,fore,cv::Mat());
        cv::findContours(fore,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);
        cv::drawContours(frame,contours,-1,cv::Scalar(0,0,255),2);
        cv::imshow("Frame",frame);
        cv::imshow("Background",back);

        output << frame;

        if(cv::waitKey(30) >= 0) break;
    }
    return 0;
}
