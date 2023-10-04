&emsp;
# TUM
- [TUM数据集](https://cvg.cit.tum.de/data/datasets/rgbd-dataset/download)
- [associate.py](https://cvg.cit.tum.de/data/datasets/rgbd-dataset/tools): 目的是从rgb.txt 文件和 depth.txt 文件中读取时间戳，并通过查找最佳匹配来连接它们

>修改 associate.py
```py
for diff, a, b in potential_matches:
    if a in first_keys and b in second_keys:
        # first_keys.remove(a)
        # second_keys.remove(b)
        first_keys = list(first_list)
        second_keys = list(second_list)

        matches.append((a, b))
```

>运行 associate.py
```sh
python associate.py \
./rgbd_dataset_freiburg1_desk/rgb.txt \
./rgbd_dataset_freiburg1_desk/depth.txt 
```

>运行 ORB-SLAM3
```sh
# TUM RGB-D
./Examples/Stereo-Inertial/stereo_inertial_euroc \
./Vocabulary/ORBvoc.txt \
./Examples/Stereo-Inertial/EuRoC.yaml \
${dir}/MH01 \
./Examples/Stereo-Inertial/EuRoC_TimeStamps/MH01.txt \
dataset-MH01_stereoi
```