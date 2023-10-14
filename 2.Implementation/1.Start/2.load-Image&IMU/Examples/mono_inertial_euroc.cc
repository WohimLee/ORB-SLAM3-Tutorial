
#include <iostream>
#include <fstream> // ifstream, getline
#include <vector>
#include <string>
#include <opencv2/core/core.hpp> // cv::Point3f
using namespace std;

void LoadImages(const string &strImagePath, const string &strPathTimes,
                vector<string> &vstrImages, vector<double> &vTimeStamps);

void LoadIMU(const string &strImuPath, 
             vector<double> &vTimeStamps, 
             vector<cv::Point3f> &vAcc, 
             vector<cv::Point3f> &vGyro);


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
    vector< vector<string> > vstrImageFilenames; // 2D-vector, 每个seq的所有images路径
    vector< vector<double> > vTimestampsCam;     // 2D-vector, 每个seq的所有时间戳
    vector< vector<cv::Point3f> > vAcc, vGyro;   // 2D-vector, 每个seq的所有IMU数据
    vector< vector<double> > vTimestampsImu;     // 2D-vector, 每个seq的所有IMU时间戳
    vector<int> nImages; // 图片数量
    vector<int> nImu;    // IMU 数据条数
    vector<int> first_imu(num_seq,0); // vector(n, elem);构造函数将n个elem拷贝给本身

    // 把所有 vector 容器 resize 成 seq 的数量
    vstrImageFilenames.resize(num_seq);
    vTimestampsCam.resize(num_seq);
    vAcc.resize(num_seq);
    vGyro.resize(num_seq);
    vTimestampsImu.resize(num_seq);
    nImages.resize(num_seq);
    nImu.resize(num_seq);

    int tot_images = 0;
    // 读取每个 seq 的数据
    for (seq = 0; seq<num_seq; seq++)
    {

        string pathSeq(argv[(2*seq) + 3]);
        string pathTimeStamps(argv[(2*seq) + 4]);

        string pathCam0 = pathSeq + "/mav0/cam0/data";
        string pathImu = pathSeq + "/mav0/imu0/data.csv";
        // Check the path and filename
        printf("pathSeq       : %s\n", pathSeq.c_str());
        printf("pathTimeStamps: %s\n", pathTimeStamps.c_str());
        printf("pathCam0      : %s\n", pathCam0.c_str());
        printf("pathImu       : %s\n", pathImu.c_str());

        cout << "Loading images for sequence " << seq << "...";
        LoadImages(pathCam0, pathTimeStamps, vstrImageFilenames[seq], vTimestampsCam[seq]);
        cout << "LOADED!" << endl;

        cout << "Loading IMU for sequence " << seq << "...";
        LoadIMU(pathImu, vTimestampsImu[seq], vAcc[seq], vGyro[seq]);
        cout << "LOADED!" << endl;

        nImages[seq] = vstrImageFilenames[seq].size(); // 每个 seq 的图片数量
        tot_images += nImages[seq]; // 所有 seq 图片数量的总和
        nImu[seq] = vTimestampsImu[seq].size(); // 每个 seq 包含的 IMU 数据条数

        if((nImages[seq]<=0)||(nImu[seq]<=0))
        {
            cerr << "ERROR: Failed to load images or IMU for sequence" << seq << endl;
            return 1;
        }

        // 找到每个seq中最后一个小于或者等于 Cam 时间戳的 IMU 时间
        while(vTimestampsImu[seq][first_imu[seq]]<=vTimestampsCam[seq][0])
            first_imu[seq]++;
        first_imu[seq]--; // first imu measurement to be considered
        printf("first imu measurement to be considered: %d, %f\n", first_imu[seq], vTimestampsImu[seq][first_imu[seq]]);
    }
}


void LoadImages(const string &strImagePath, const string &strPathTimes,
                vector<string> &vstrImages, vector<double> &vTimeStamps)
{
    ifstream fTimes;
    fTimes.open(strPathTimes.c_str());
    vTimeStamps.reserve(5000); // MH01 大概有 3000 多条数据
    vstrImages.reserve(5000);  // 多留点可以避免动态内存分配这种重操作
    while(!fTimes.eof()) // End of File 判断是否读完所有内容
    {
        string s;
        getline(fTimes,s); // 按行读取
        if(!s.empty()) // 内容非空
        {
            stringstream ss; // stringstream 可以用于类型转换
            ss << s; // 
            vstrImages.push_back(strImagePath + "/" + ss.str() + ".png"); // 拼接每一张图片路径
            double t;
            ss >> t; // stringstream 将数据转换成 double 型
            vTimeStamps.push_back(t/1e9); // 纳秒转换成秒
        }
    }
}

void LoadIMU(const string &strImuPath, vector<double> &vTimeStamps, vector<cv::Point3f> &vAcc, vector<cv::Point3f> &vGyro)
{
    ifstream fImu;
    fImu.open(strImuPath.c_str());
    vTimeStamps.reserve(5000);
    vAcc.reserve(5000);
    vGyro.reserve(5000);

    while(!fImu.eof())
    {
        string s;
        // 读取每一行, 存到 s
        getline(fImu,s);
        if (s[0] == '#')
            continue;

        if(!s.empty())
        {
            string item;
            size_t pos = 0;
            double data[7]; // 时间戳 
            int count = 0;
            // 对 getline 得到的每一行数据逐个读取
            while ((pos = s.find(',')) != string::npos) {
                item = s.substr(0, pos); // 从开始到 , 的内容
                data[count++] = stod(item); // 转换成 double 存入data[7]
                s.erase(0, pos + 1); // 删除已读取的数据
            }
            item = s.substr(0, pos); // 最后一个数据
            data[6] = stod(item);

            vTimeStamps.push_back(data[0]/1e9); // 纳秒转成秒
            // 分别存入对应的 Acc 和 Gyro 容器
            vAcc.push_back(cv::Point3f(data[4],data[5],data[6]));
            vGyro.push_back(cv::Point3f(data[1],data[2],data[3]));
        }
    }
}







