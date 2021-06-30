#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <vector>
#include <sys/time.h>
#include <ostream>
#include <iostream>
#include <random>
#include <cstdlib>
using namespace std;

double get_time()
{
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec + tv.tv_usec * 1e-6;
}

int main(){
    std::srand(time(NULL));
    double begin,end;
    vector <vector<int>> first_matrix(100,vector<int>(100));
    vector <vector<int>> second_matrix(100,vector<int>(100));
    vector <vector<int>> third_matrix(100,vector<int>(100,0));

    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            first_matrix.at(i).at(j)=rand()%10;
            second_matrix.at(i).at(j)=rand()%10;
            // third_matrix.at(i).at(j)=rand()%10;
        }
    }


    // i-j-k

    begin = get_time();

    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            for(int k=0;k<100;k++){
                third_matrix.at(i).at(j)+=first_matrix.at(i).at(k)*second_matrix.at(k).at(j);
            }
        }
    }

    end = get_time();

    std::cout << "i-j-k:" << end-begin << std::endl;


    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            third_matrix.at(i).at(j)=0;
        }
    }

    //i-k-j

    begin = get_time();

    for(int i=0;i<100;i++){
        for(int k=0;k<100;k++){
            for(int j=0;j<100;j++){
                third_matrix.at(i).at(j)+=first_matrix.at(i).at(k)*second_matrix.at(k).at(j);
            }
        }
    }

    end = get_time();

    std::cout << "i-k-j:" << end-begin << std::endl;


    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            third_matrix.at(i).at(j)=0;
        }
    }


    //j-i-k

    begin = get_time();

    for(int j=0;j<100;j++){
        for(int i=0;i<100;i++){
            for(int k=0;k<100;k++){
                third_matrix.at(i).at(j)+=first_matrix.at(i).at(k)*second_matrix.at(k).at(j);
            }
        }
    }

    end = get_time();

    std::cout << "j-i-k:" << end-begin << std::endl;



    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            third_matrix.at(i).at(j)=0;
        }
    }


    //j-k-i

    begin = get_time();

    for(int j=0;j<100;j++){
        for(int k=0;k<100;k++){
            for(int i=0;i<100;i++){
                third_matrix.at(i).at(j)+=first_matrix.at(i).at(k)*second_matrix.at(k).at(j);
            }
        }
    }

    end = get_time();

    std::cout << "j-k-i:" << end-begin << std::endl;



    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            third_matrix.at(i).at(j)=0;
        }
    }
    //k-i-j
    begin = get_time();

    for(int k=0;k<100;k++){
        for(int i=0;i<100;i++){
            for(int j=0;j<100;j++){
                third_matrix.at(i).at(j)+=first_matrix.at(i).at(k)*second_matrix.at(k).at(j);
            }
        }
    }

    end = get_time();

    std::cout << "k-i-j:" << end-begin << std::endl;





    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            third_matrix.at(i).at(j)=0;
        }
    }
    //k-j-i
    begin = get_time();

    for(int k=0;k<100;k++){
        for(int j=0;j<100;j++){
            for(int i=0;i<100;i++){
                third_matrix.at(i).at(j)+=first_matrix.at(i).at(k)*second_matrix.at(k).at(j);
            }
        }
    }

    end = get_time();

    std::cout << "k-j-i:" << end-begin << std::endl;




    



}