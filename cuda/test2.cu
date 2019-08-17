#include<iostream>
#define HANDLE_ERROR(ret) \
    {\
        if(ret != cudaSuccess)\
            std::cerr<<"cuda wrong"<<std::endl;\
    }
__global__ void add(int* a,int* b,int* c){
    int idx=threadIdx.x;
    c[idx]=a[idx]+b[idx];
}
int main(){
    int a = 123;
    int b= 234;
    int c;
    int *dev_a,*dev_b,*dev_c;
    HANDLE_ERROR(cudaMalloc(&dev_a,sizeof(int)));
    HANDLE_ERROR(cudaMalloc(&dev_b,sizeof(int)));
    HANDLE_ERROR(cudaMalloc(&dev_c,sizeof(int)));

    HANDLE_ERROR(cudaMemcpy(dev_a,&a,sizeof(int),cudaMemcpyHostToDevice));
    HANDLE_ERROR(cudaMemcpy(dev_b,&b,sizeof(int),cudaMemcpyHostToDevice));

    add<<<1,3,0>>>(dev_a,dev_b,dev_c);
    
    HANDLE_ERROR(cudaMemcpy(&c,dev_c,sizeof(int),cudaMemcpyDeviceToHost));

    cudaFree(dev_a);
    cudaFree(dev_b);
    cudaFree(dev_c);
    std::cout<<c;
}