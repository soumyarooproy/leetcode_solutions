// 3 ns, 09/01/2017
uint32_t reverseBits(uint32_t n)
{
    uint32_t result = 0;

    for (int i = 0; i < 32; ++i) {
        result = (result << 1) | (n & 0x1);
        n >>= 1;
    }

    return result;
}
/*-----------------------------------------------------------------*/
// TODO: Understand this - found this online
uint32_t reverseBits(uint32_t x)
{
    x = (x >> 16) | (x << 16);
    x = ((x & 0xFF00FF00) >> 8) | ((x & 0x00FF00FF) << 8);
    x = ((x & 0xF0F0F0F0) >> 4) | ((x & 0x0F0F0F0F) << 4);
    x = ((x & 0xCCCCCCCC) >> 2) | ((x & 0x33333333) << 2);
    return ((x & 0xAAAAAAAA) >> 1) | ((x & 0x55555555) << 1);
}
