
MAIN := ./Examples/mono_inertial_euroc.cc
TARGET := $(basename $(notdir $(MAIN)))


cc_srcs := $(shell find src -name "*.cc")
cc_objs := $(patsubst src/%.cc,objs/%.o,$(cc_srcs))


compile_options := -std=c++11


Examples/$(TARGET) : $(MAIN)
	@echo [INFO]: Compile $< to $@
	@mkdir -p $(dir $@)
	@g++ -c $< -o $@ $(compile_options)







run : Examples/$(TARGET)
	@./$< \
		/home/nerf/datav/SLAM/ORB_SLAM3/Vocabulary/ORBvoc.txt \
		/home/nerf/datav/Dataset/EuRoc/MH01 \
		/home/nerf/datav/SLAM/ORB_SLAM3/Examples/Monocular-Inertial/EuRoC.yaml \
		/home/nerf/datav/SLAM/ORB_SLAM3/Examples/Monocular-Inertial/EuRoC_TimeStamps/MH01.txt \
		dataset-MH01_monoi

clean :
	@rm -rf objs Examples/$(TARGET)

debug :
	@echo $(cc_srcs)
