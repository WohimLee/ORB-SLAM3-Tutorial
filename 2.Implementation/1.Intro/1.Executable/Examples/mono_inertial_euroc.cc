
#include <iostream>
#include <fstream> // ifstream, getline
#include <vector>
#include <string>
#include <opencv2/core/core.hpp> // cv::Point3f
using namespace std;

int main(int argc, char** argv)
{
    if(argc < 5)
    {
        cout << endl << "[ERROR]: Usage: ./mono_inertial_euroc path_to_vocabulary path_to_settings path_to_sequence_folder_1 path_to_times_file_1 (path_to_image_folder_2 path_to_times_file_2 ... path_to_image_folder_N path_to_times_file_N) " << endl;
        return 0;
    }
    // 可以输入多个 sequence, 计算用户输入多少个
    const int num_seq = (argc-3)/2;
    cout << "num_seq = " << num_seq << endl;
    // 是否有最后一个参数, 有即为文件名
    bool bFileName= (((argc-3) % 2) == 1);
    string file_name;
    if (bFileName)
    {
        file_name = string(argv[argc-1]);
        cout << "file name: " << file_name << endl;
    }
    // Load all sequences:
    int seq;
    vector< vector<string> > vstrImageFilenames;
    vector< vector<double> > vTimestampsCam;
    vector< vector<cv::Point3f> > vAcc, vGyro; // TODO
    vector< vector<double> > vTimestampsImu;
    vector<int> nImages;
    vector<int> nImu;
    vector<int> first_imu(num_seq,0);

    // 以下 vector 容器全部按照 seq 的数量 resize
    vstrImageFilenames.resize(num_seq); 
    vTimestampsCam.resize(num_seq);
    vAcc.resize(num_seq);
    vGyro.resize(num_seq);
    vTimestampsImu.resize(num_seq);
    nImages.resize(num_seq);
    nImu.resize(num_seq);

    int tot_images = 0;
}

