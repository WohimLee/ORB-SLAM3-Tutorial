


cpp_srcs := $(shell find src -name "*.cpp")
cpp_objs := $(patsubst src/%.cpp,objs/%.o,$(cpp_srcs))

include_dirs := 
linking_libs := pthread
library_dirs := 


I_options := $(include_dirs:%=-I%)
l_options := $(linking_libs:%=-l%)
L_options := $(library_dirs:%=-L%)
r_options := $(library_dirs:%=-Wl,-rpath=%)


compile_options := -std=c++11 -fPIC -w $(I_options)
linking_options := $(l_options) $(L_options) $(r_options)

# Compile ORB lib
objs/%.o : src/%.cpp
	@echo [INFO]: Compile $^ to $@
	@mkdir -p $(dir $@)
	@g++ -c $< -o $@ $(compile_options)



workspace/exec : $(cpp_objs)
	@echo [INFO]: Link $^ to $@
	@mkdir -p $(dir $@)
	@g++ $< -o $@ $(linking_options)



run : workspace/exec
	@./$< 

clean :
	@rm -rf objs workspace/exec

debug :
	@echo $(DBoW2_LIBS)

