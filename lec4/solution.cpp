#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll make_graph_name(string,map<ll,string>& ,string);
void make_graph(string,map<ll,vector<ll>>&);
ll bfs(map<ll,vector<ll>> &,map<ll,string> &,queue<ll> &, set<ll> &, map<ll,ll> &, string);
void path_restore(map<ll,ll> &, map<ll,string> &,ll,ll);

int main(int argc,char *argv[]) {


    if(argc!=5){
        cout << "引数忘れないで！" << endl;
        return 0;
    }

 
    map<ll,vector<ll>> graph;
    map<ll,string> page_name;
    queue <ll> page_links_queue;
    set <ll> visited;
    map <ll,ll> pre_page;


    make_graph((string)argv[1],graph);
    ll default_num = make_graph_name((string)argv[2],page_name,(string)argv[3]);



    page_links_queue.push(default_num);

    visited.insert(default_num);
  

    ll answer_node=bfs(graph,page_name,page_links_queue,visited,pre_page,(string)argv[4]);


    path_restore(pre_page,page_name,answer_node,default_num);


}

ll make_graph_name(string file_name,map<ll,string>& graph,string from){
    string line,page_name;
    ll page_num,default_num;
    ifstream input_file("data/"+file_name);

    while (getline(input_file, line)){

        page_num = ll(stoll(line.substr(0,line.find('\t'))));
        page_name= line.substr(line.find('\t')+1,(ll)line.size()-line.find('\t')-1);

        graph[page_num]=page_name;

        if(page_name==from)
            default_num = page_num;


    }
    return default_num;
}

void make_graph(string file_name,map<ll,vector<ll>>& graph){

    string line;
    ll first_num,second_num;

    ifstream input_file("data/"+file_name);

    while (getline(input_file, line)){
        
        first_num = ll(stoll(line.substr(0,line.find('\t'))));
        second_num = ll(stoll(line.substr(line.find('\t')+1,(ll)line.size()-line.find('\t')-1)));


        vector <ll> tmp = graph[first_num];
        tmp.push_back(second_num);
        graph[first_num]=tmp;

    }


    return;

}


ll bfs(map<ll,vector<ll>> &graph,map<ll,string> &page_name,queue<ll> &links_queue, set<ll> &visited, map<ll,ll> &pre_page, string to){
    
    ll now_node;
    
    while(!links_queue.empty()){
        now_node = links_queue.front();

        for(auto next_node:graph[now_node]){
            if(!visited.count(next_node)){
                pre_page[next_node] = now_node;
                links_queue.push(next_node);
                visited.insert(next_node);

                if(page_name[next_node]==to){
                    return next_node;
                }
            }
        }
        
       

        links_queue.pop();

    }

    return -1;
}


void path_restore(map<ll,ll> &pre_page, map<ll,string> &page_name,ll answer_node,ll default_num){

    if(answer_node == -1){
        cout << "そんなパスはない" << endl;
        return;
    }




    ll now = answer_node;

    vector <string> path;


    while(true){

        path.push_back(page_name[now]);
        if(now==default_num)
            break;
        now = pre_page[now];
    }


    reverse(path.begin(),path.end());


    for(auto page:path){
        cout << page << " ";
    }
    cout << endl;

    return;

}


