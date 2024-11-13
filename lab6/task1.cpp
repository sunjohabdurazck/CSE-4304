#include <iostream>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime>

using namespace std;


class Matrix3D
{
private:
    int count;
    int incrementStep;
public:
    Matrix3D():count(0),incrementStep(1){}

    double det(int arr[3][3])
    {
       double a;
        a=((arr[0][0])*(arr[1][1]*arr[2][2])-(arr[1][2]*arr[2][1])) -((arr[0][1])*(arr[1][0]*arr[2][2])-(arr[1][2]*arr[2][0])) +((arr[0][2])*(arr[1][0]*arr[2][1])-(arr[1][1]*arr[2][0]));

        cout<<a;
    }
    Matrix3D_inverse()
    {

    }
    void setIncrement(int val)
    {
        if (count == 0)
        {
            if (val > 0)
            {
                incrementStep = val;
            }
        }
        else
        {
            cout << "Cannot set the increment step when count is not zero." << endl;
        }

    }

    int getMatrix(int arr[3][3])
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                arr[i][j];
            }

        }

    }

    void increment(int arr[3][3])
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                arr[i][j]+=incrementStep;
            }
        }

    }

    bool operator>(const Matrix3D& other) const
    {
        return count > other.count;
    }
    bool operator<(const Matrix3D& other) const
    {
        return count < other.count;
    }
    bool operator>=(const Matrix3D& other) const
    {
        return count >= other.count;
    }
    bool operator<=(const Matrix3D& other) const
    {
        return count <= other.count;
    }
    bool operator==(const Matrix3D& other) const
    {
        return count == other.count;
    }
    bool operator!=(const Matrix3D& other) const
    {
        return count != other.count;
    }
    int display(int arr[3][3]){

    for(int i=0;i<3;i++){
        cout<<"\n";
        for(int j=0;j<3;j++){
            cout<<arr[i][j] <<" ";


        }

    }
    }
};


void randomAssignment(int arr[][3]) {
    for (int i = 0; i < 3; ++i) {
            for(int j=0;j<3;j++)
        arr[i][j] = (rand() % 5);
    }
}

int randomInRange(int min, int max) {

    if (min > max) {
        std::swap(min, max);
    }

    return rand() % (max - min + 1) + min;
}

double randomInRange(double min, double max) {

    if (min > max) {
        std::swap(min, max);
    }


    double randomFraction = static_cast<double>(rand()) / RAND_MAX;


    return min + randomFraction * (max - min);
}


int main()
{
    Matrix3D MAT;
    srand(static_cast<unsigned int>(time(0)));
   int arr[3][3];
    randomAssignment(arr);
    MAT.display(arr);
    MAT.det(arr);

    return 0;
}
