# GPGPU Tutorial


## Introduce
the tutorial is used to learning demo about gpgpu using opengl or opencl.
Both of them can be used to finish Matrix-Multiply or Vector-Add tasks.
The real computation is controled by `kernel file`, like `glsl` file in opengl or
`cl` file in opencl.


## Installation

### Prerequisite
```bash
# opengl libs
sudo apt install libglfw3-dev
sudo apt install libegl1-mesa-dev

# other utils
# should build glog from source due to cmake find_package command
```

both of them are compiled using cmake
### OpenCL
```bash
# in the root directory
cd opencl_sdk
mkdir build && cd build && cmake .. && make -j`nproc`

# run demo of vector add
./main
```


### OpenGL
```bash
cd opengl_sdk
mkdir build && cd build && cmake .. && make -j`nproc`

# run demo
# use glfw wrapper
./fbo_glfw

# use egl directly
./fbo_egl
```


## Development

```cpp
//first Init Context
device = CreateDevice();
InitContext();

// allocate memory in cpu and gpu
void* a_cpu = malloc(bytes);
void* a_gpu = DeviceMalloc(bytes);

// store output in host
void* b_cpu = malloc(bytes);

// then upload data from host(cpu) to device(gpu)
memcpyH2D(a_gpu, a_cpu, bytes);

// compile kernel, glsl or cl
auto kernel = BuildKernel(kernel_fname);

// create executor to run kernel, 
// means command queue in opencl
// but in opengl, it will be created internally
stream = CreateStream(device);
stream.LaunchKernel(kernel);

// copy back to host
memcpyD2H(b_cpu, a_gpu, bytes);

// finally check the result
CheckTheSame(a_cpu, b_cpu);
```

