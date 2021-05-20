#include <bits/stdc++.h>
#include <sys/time.h>
#include <fstream>
#include <iostream>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i<n;i++)
typedef pair<int,int> P;

//時間の計測
double get_time()
{
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec + tv.tv_usec * 1e-6;
}



double calculation(ll n) {


    //適当に作ったmatrix_aとmatrix_bを計算したものをmatrix_cにぶち込む

    vector<vector<ll> > matrix_a(n,vector <ll>(n)),matrix_b(n,vector <ll>(n)),matrix_c(n,vector <ll>(n,0));

    // matrix_aとmatrix_bという行列を適当に生成
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            matrix_a.at(i).at(j)=i+j;
            matrix_b.at(i).at(j)=i+j;
        }
    }


    double begin = get_time();

    // 行列積を計算
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;i<n;i++){
                matrix_c.at(i).at(j)+=matrix_a.at(i).at(k)*matrix_b.at(k).at(j);
            }
        }
    }

    double end = get_time();


    // かかった時間を返す
    return end-begin;




}

int main(int argc, char** argv){
    //datファイルに時間を出力する
    ofstream fout("time.dat"); 
    if (argc != 2) {
    cout << "usage: " << argv[0] << endl;
    return -1;
    }
    
    ll n = stoi(string(argv[1]));

    for(int i=0;i<n;i++){
        fout << i+1 << ' '  << calculation(i+1) << endl;
    }

    fout.close();

}