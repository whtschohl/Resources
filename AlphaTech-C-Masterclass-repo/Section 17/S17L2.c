/*
    Problem Example:

    sin() vs cos()
*/

float sin(float x);
float cos(float x);

int main()
{
    float *ptrFunc;

    if (1)
        ptrFunc = sin;
    else
        ptrFunc = cos;    
}

float sin(float x)
{
    return 0.0f;
}

float cos(float x)
{
    return 0.0f;
}
