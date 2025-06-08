#include <iostream>
#include <cstdint>
using std::cout; using std::uint16_t; using std::uint32_t;

uint32_t p(uint16_t x,uint16_t y){return (uint32_t(x)<<16)|y;}
void u(uint32_t v,uint16_t&x,uint16_t&y){x=uint16_t(v>>16);y=uint16_t(v&0xFFFF);}
int main(){uint16_t x=300,y=500;uint32_t v=p(x,y);cout<<v<<"\n";uint16_t a,b;u(v,a,b);cout<<a<<","<<b<<"\n";return 0;}