#!/usr/bin/env python3

import sys
import math
import random
import numpy as np

from common import print_tour, read_input

def distance(city1, city2):
    return math.sqrt((city1[0] - city2[0]) ** 2 + (city1[1] - city2[1]) ** 2)


def make_random_path(N):
    tmp = []
    for i in range(N):
        tmp.append(i)

    ans = []
    for _ in range(50):
        ans.append(random.sample(tmp, len(tmp)))

    return ans

def make_score_list(path_list,dist):
    score_list = []
    for path in path_list:
        pre = 0
        score = 0

        for now in path:
            score += dist[pre][now+1]
            pre = now+1

        score += dist[pre][0]

        score_list.append((score,len(score_list)))

    score_list.sort()
    return score_list


def crossover(score_list,path_list):
    j = 0
    for _,index in score_list:
        if j == 0:
            j+=1
            par1_index = index
            parent1 = path_list[index]
            continue

        parent2 = path_list[index]
        # path_list[index] = 
        cross_point = random.randrange(1, len(path_list)-1)
        child1 = parent1
        child2 = parent2
        # print("child1")
        # print(child1)
        for i in range(len(parent2) - cross_point):
            target_index = cross_point + i
            
            target_value1 = child1[target_index]
            target_value2 = child2[target_index]
            for k in range(len(parent1)):
                if parent1[k] == target_value1:
                    exchange_index1 = k
                    break
        # exchange_index2 = np.where(parent2 == target_value1)
            for k in range(len(parent2)):
                if parent2[k] == target_value1:
                    exchange_index2 = k
                    break
            
            child1[target_index] = target_value2
            child2[target_index] = target_value1
            child1[exchange_index1] = target_value1
            child2[exchange_index2] = target_value2
        
        path_list[index] = child2
        path_list[par1_index] = child1
        parent1 = parent2
        par1_index = index

    return path_list
    



def translocation_mutation(genes, num_mutation, p_value):
    mutated_genes = genes
    for i in range(num_mutation):
        mutation_flg = np.random.choice(2, 1, p = [1-p_value, p_value])
        if mutation_flg == 1:
            mutation_value = random.sample(genes[i], 2)

            for k in range(len(genes[i])):
                if genes[i][k] == mutation_value[0]:
                    mutation_position1 = k
                    break
            for k in range(len(genes[i])):
                if genes[i][k] == mutation_value[1]:
                    mutation_position2 = k
                    break
            # mutation_position2 = np.where(genes[i] == mutation_value[1])
            mutated_genes[i][mutation_position1] = mutation_value[1]
            mutated_genes[i][mutation_position2] = mutation_value[0]
    return mutated_genes





def solve(cities):
    N = len(cities)



    dist = [[0] * N for i in range(N)]



    for i in range(N):
        for j in range(i, N):
            dist[i][j] = dist[j][i] = distance(cities[i], cities[j])


    path_list = make_random_path(N-1)
    # for i in path_list:
    #     print(i)

    

    score_list = make_score_list(path_list, dist)

        
        # for i in score_list:
        #     print(i)
    for j in range(5000):
        crossovered_path_list = crossover(score_list[5:],path_list)
        

        # for i in crossovered_path_list:
        #     print(i)

        # child1,child2 = partial_crossover(path_list[0],path_list[1])

        # print(child1,child2)


        path_list = translocation_mutation(crossovered_path_list,5,0.3)
        score_list = make_score_list(path_list, dist)

        # print(len(crossovered_path_list ))
    score,index = score_list[0]
    return path_list[index],score

    


if __name__ == '__main__':
    assert len(sys.argv) > 2
    tour,score = solve(read_input(sys.argv[1]))
    # print(tour,score)
    print_tour(tour)
    f = open(sys.argv[2], 'w')
    f.write("index\n")
    f.write(str(0)+'\n')
    for index in tour:
        f.write(str(index+1)+'\n')
    f.close()