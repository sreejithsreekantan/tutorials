#ifndef UTILITY_STDLIB_H_
#define UTILITY_STDLIB_H_

namespace utility   // to avoid polution of global namespace
{

void itoa(const int &i, char c[])
{
    sprintf(c, "%d", i);
}

void atoi(int &i, const char c[])
{
    sscanf(c, "%d", &i);
}

} // namespace utility

#endif // UTILITY_STDLIB_H_