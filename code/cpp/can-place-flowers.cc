// 16 ms, 09/02/2017
bool canPlaceFlowers(vector<int>& flowerbed, int n)
{
    auto len = flowerbed.size();
    if (n > (len + 1) / 2) {
        return false; // pigeonhole principle
    }

    auto max_n = 0;

    // Count leading 0's
    auto i = 0, count = 0;
    for (; i < len && !flowerbed[i]; ++count, ++i);

    if (i == len)
        // All 0's case
        // 000 -> 101
        // 00 -> 10 or 10
        // 0 -> 1            
        return 2 * n <= len + 1;

    // flowerbed[i] == 1 at this point
    // 0001... -> 0101...
    // 001...  -> 101...
    // 01...   -> 01...
    // etc.
    max_n += count / 2;     

    while (++i < len) {
        // Count the consecutive number of 0's
        for (count = 0; i < len && !flowerbed[i]; ++count, ++i);

        if (i == len)
            // Trailing 0's case
            // 10.   -> 10.
            // 100.  -> 101.
            // 1000. -> 1010.
            max_n += count / 2;
        else
            // Itermediate 0's case
            // ...101...   -> ...101...
            // ...1001...  -> ...1001...
            // ...10001... -> ...10101...
            max_n += (count - 1) / 2;
    }

    return n <= max_n;
}
