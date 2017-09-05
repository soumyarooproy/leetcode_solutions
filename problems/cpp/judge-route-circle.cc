// 19 ms, 09/05/2017
// Time  : O(n)
// Space : O(1)
bool judgeCircle(string moves)
{
    array<char, 26> steps;
    steps['R' - 'A'] = 1;
    steps['L' - 'A'] = -1;
    steps['D' - 'A'] = 1;
    steps['U' - 'A'] = -1;

    array<char, 26> dir;
    dir['R' - 'A'] = 0;
    dir['L' - 'A'] = 0;
    dir['D' - 'A'] = 1;
    dir['U' - 'A'] = 1;

    array<int, 2> dist({0,0});

    for (auto c : moves)
        dist[dir[c - 'A']] += steps[c - 'A'];

    return !dist[0] && !dist[1];
}
