#include<iostream>

__global__  void add(int a,int b,int *c){
    *c = a+b;
}
int main(){
    int *c;
    int result;
    int devicecount;
    cudaDeviceProp prop;
    cudaGetDeviceCount(&devicecount);
    std::cout<<"device:"<<devicecount<<std::endl;
    cudaMalloc(&c,sizeof(int));
    add<<<1,1>>>(2,3,c);
    cudaMemcpy(&result,c,sizeof(int),cudaMemcpyDeviceToHost);
    cudaGetDeviceProperties(&prop,0);
    std::cout<<prop.name;te
    std::cout<<result;
    
}