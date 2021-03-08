#include <iostream>
#include <vector>
#include <cstdlib>

//Cheuk Lam Cheung
//CSCI 235
std::vector<int> merge(std::vector<int> le, std::vector<int> ri){
    std::vector<int> m;
    //adds the smallest element from each vector until one of the vector is empty
    while (le.size() > 0 && ri.size() >0 ){
        if(le[0] < ri[0]){
            m.push_back(le[0]);
            le.erase(le.begin());
        }
        else {
            m.push_back(ri[0]);
            ri.erase(ri.begin());
        }
    } 
    //adds the rest of the elements from the remaining vector
    if (le.size() > 0){
        while(le.size()>0){
            m.push_back(le[0]);
            le.erase(le.begin());
        }
    }
    else {
        while(ri.size()>0){
            m.push_back(ri[0]);
            ri.erase(ri.begin());
        }
    }
    return m;
}

// Luca Burlacu
std::vector<int> msort(std::vector<int> vec)
{
  int middle = vec.size() / 2;
  if(vec.size() > 1)
  {
    if(vec.size() == 2)
    {
      if(vec[0] > vec[1])
      {
        int temp = vec[1];
        vec[1] = vec[0];
        vec[0] = temp;
        return vec;
      }
      return vec;
    }

    auto left = msort(std::vector<int>(vec.begin(), vec.begin()+middle));
    auto right = msort(std::vector<int>(vec.begin()+middle, vec.end()));
    return merge(left,right);
  }
  else
    return vec;
}

void print_vector(std::vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << ", ";
    }
    std::cout << std::endl;
}

int main(){
    srand(time(NULL));
    std::vector<int> a(20);
    int i;
    for(i=0;i<20;i++){
        a[i] = rand()%100;    
    }

    std::cout << "Unsorted vector: " << std::endl;
    print_vector(a);
    a = msort(a);
    std::cout << "Sorted vector: " << std::endl;
    print_vector(a);
}