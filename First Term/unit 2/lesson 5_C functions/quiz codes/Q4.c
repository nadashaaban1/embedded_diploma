#include <stdio.h>
void convert(int x[])
{
    unsigned int result[10];
    for(int i=0;i<10;i++)
    {
        result[i] = x[i]-'0';
    }
    for(int i=0; i<10; i++)
    {
        printf("%u ",result[i]);
    }
    
}
int main()
{
int x[10]={0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39};
convert(x);

}
