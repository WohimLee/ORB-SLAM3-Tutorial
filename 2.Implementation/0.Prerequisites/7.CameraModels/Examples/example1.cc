

#include <vector>
#include <opencv2/core/core.hpp>


cv::Point2f project1(const cv::Point3f &p3D, float focal_length=500)
{
    return cv::Point2f(
        p3D.x*focal_length / p3D.z,
        p3D.y*focal_length / p3D.z);
}

cv::Point2f project2(const cv::Point3f &p3D, 
    float alpha=1, float beta=1, float focal_length=500, 
    float cx=320, float cy=240)
{
    return cv::Point2f(
        alpha*(focal_length*p3D.x/p3D.z) + cx,
        beta *(focal_length*p3D.y/p3D.z) + cy);
}


cv::Point2f project3(const cv::Point3f &p3D, const std::vector<float> &parameters)
{
    return cv::Point2f(
        parameters[0]*p3D.x + parameters[2],
        parameters[1]*p3D.x + parameters[3]);
}

int main(int argc, char** argv)
{

    cv::Point3f point = {2, 4, 6};

    cv::Point2f pointProj1 = project1(point);
    printf("(%.2f, %.2f, %.2f) project to: (%f, %f)\n",
        point.x, point.y, point.z, pointProj1.x, pointProj1.y
    );

    cv::Point2f pointProj2 = project2(point);
    printf("(%.2f, %.2f, %.2f) project to: (%f, %f)\n",
        point.x, point.y, point.z, pointProj2.x, pointProj2.y
    );

    std::vector<float> parameters = {500, 500, 320, 240}; // fx, fy, cx, cy
    cv::Point2f pointProj3 = project3(point, parameters);
    printf("(%.2f, %.2f, %.2f) project to: (%f, %f)\n",
        point.x, point.y, point.z, pointProj2.x, pointProj2.y
    );

    return 0;
}