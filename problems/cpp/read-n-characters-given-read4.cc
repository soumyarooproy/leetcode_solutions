int read4(char *buf);

/**
 * @param buf Destination buffer
 * @param n   Maximum number of characters to read
 * @return    The number of characters read
 */
int read(char *buf, int n)
{
    auto start_buf = buf;

    while (n >= 4) {
        auto num_read = read4(buf);
        // if the stream is finished, break
        if (num_read < 4) {
            buf += num_read;
            n = 0;
            break;
        }
        buf += 4;
        n -= 4;
    }

    // At this stage 1-3 bytes need to be read
    if (n)
        buf += min(read4(buf), n);

    *buf = 0; // null terminate the char*
    return buf - start_buf;
}
