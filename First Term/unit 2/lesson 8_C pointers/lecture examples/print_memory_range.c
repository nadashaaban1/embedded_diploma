#include <stdio.h>
struct sDataSet
{
    unsigned char data1;
    unsigned int data2;
    unsigned char data3;
    unsigned short data4;
};
struct sDataSet data1;
void print_memory_range(char* base, int size)
{
    for(int i=0; i<size; i++)
    {
        printf("%p \t %x \n",base,(unsigned char)* base);
        base++;
    }
}
int main ()
{
    data1.data1=0x11;
    data1.data2=0xffffeeee;
    data1.data3=0x22;
    data1.data4=0xabcd;
print_memory_range(&data1,sizeof(data1));
return 0;
}