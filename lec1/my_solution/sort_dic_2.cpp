#include <bits/stdc++.h>
#include <fstream>
#include <iostream>

using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i<n;i++)
typedef pair<string,vector<string>> P;
typedef tuple<ll,string,map<char,ll>>T;


int main() {
    // 単語数は84093


    string filename("../anagram/words.txt");

    string line;
    vector <T> new_lines;
    ll points=0;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        return EXIT_FAILURE;
    }

    while (getline(input_file, line)){
        points=0;
        map<char,ll> tmp_map;
        rep(i,line.size()){
            if(line.at(i)=='j' || line.at(i)=='k' || line.at(i)=='q' || line.at(i)=='x' || line.at(i)=='z')
                points+=4;
            else if(line.at(i)=='b' || line.at(i)=='f' || line.at(i)=='g' || line.at(i)=='p' || line.at(i)=='v' || line.at(i)=='w' || line.at(i)=='y')
                points+=3;
            else if(line.at(i)=='c' || line.at(i)=='d' || line.at(i)=='l' || line.at(i)=='m' || line.at(i)=='u')
                points+=2;
            else
                points++;

            tmp_map[line.at(i)]++;
        }

        new_lines.push_back(make_tuple(points,line,tmp_map));


    }


    sort(new_lines.begin(),new_lines.end());
    reverse(new_lines.begin(),new_lines.end());

    input_file.close();


    ofstream fout("new_dictionary_2.txt");


    string tmp_str;
    map<char,ll> tmp_map_2;
    rep(i,new_lines.size()){
        tie(points,tmp_str,tmp_map_2)=new_lines.at(i);
        fout << points << ',' << tmp_str << ',';

        for(auto v:tmp_map_2){
            fout << v.first << ':' << v.second << ' ';
        }
        fout << endl;

    }


    fout.close();
    return 0;

    

}
