#include<stdio.h>
#include<cuda.h>
__global__ void arradd(int *x,int *y, int *z)
{
    int id=threadIdx.x;
/* threadIdx.x gives the respective thread id which starts from 0 */
    z[id]=x[id]+y[id];
}
int main()
{
    int a[6];
    int b[6];
    int c[6];
    int *d,*e,*f;
    int i;
    printf("\n Enter six elements of first array\n");
    for(i=0;i<6;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n Enter six elements of second array\n");
        for(i=0;i<6;i++)
        {
            scanf("%d",&b[i]);
        }
    cudaMalloc((void **)&d,6*sizeof(int));
    cudaMalloc((void **)&e,6*sizeof(int));
    cudaMalloc((void **)&f,6*sizeof(int));
 cudaMemcpy(d,a,6*sizeof(int),cudaMemcpyHostToDevice);   cudaMemcpy(e,b,6*sizeof(int),cudaMemcpyHostToDevice);
    arradd<<<1,6>>>(d,e,f);
 cudaMemcpy(c,f,6*sizeof(int),cudaMemcpyDeviceToHost);
    printf("\nSum of two arrays:\n ");
    for(i=0;i<6;i++)
    {
        printf("%d\t",c[i]);
    }
    cudaFree(d);
    cudaFree(e);
    cudaFree(f);
    return 0;
}